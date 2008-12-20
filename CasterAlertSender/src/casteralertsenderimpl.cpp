#include "casteralertsenderimpl.h"

CasterAlertSenderImpl::CasterAlertSenderImpl( QWidget * parent, Qt::WFlags f) : QMainWindow(parent, f)
{
        setupUi(this);

        addrM.setAddress("225.1.2.3");
        portM = (quint16) 22512;
        initSocket();
}

void CasterAlertSenderImpl::initSocket()
{
    sockM = new QUdpSocket(this);
    sockM->bind(this->portM, QUdpSocket::ShareAddress);     // Listening on : ip=QHostAddress::Any(it's an overloaded method), port=portM
                                                            // QUdpSocket::ShareAddress = Allow other services to bind to the same address and port

/*  Plus besoin d'écouter, suffit d'envoyer ici, c juste bon pour tester :-)
    // S'abonner a l adresse multicast ! (Qt ne gere pas, il faut appeler les methode natives... tsss)
    struct ip_mreq mreq;
    mreq.imr_multiaddr.s_addr = inet_addr((const char*)addrM.toString().toStdString().c_str());
    mreq.imr_interface.s_addr = INADDR_ANY;
    int r = ::setsockopt(sockM->socketDescriptor(), IPPROTO_IP, IP_ADD_MEMBERSHIP, (const char *)&mreq, sizeof(struct ip_mreq));
    qDebug("setsockopt returned %d", r);

    connect(sockM, SIGNAL(readyRead()), this, SLOT(readPendingDatagramsM()));
*/
}

void CasterAlertSenderImpl::readPendingDatagramsM()
{
    qDebug() << "Retrieving datagram";

    while (sockM->hasPendingDatagrams())
    {
        QByteArray datagram;
        QHostAddress sender;
        quint16 senderPort;

        datagram.resize(sockM->pendingDatagramSize());
        sockM->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        QString str = QString::fromUtf8(datagram.data());

        //processTheDatagram(datagram);
        qDebug() << datagram.data();
        qDebug() << sender;
        qDebug() << senderPort << endl;
    }
}

void CasterAlertSenderImpl::on_sendAlertButton_clicked()
{
    CasterAlert *ca = NULL;

    // Check if at least one user is selected as target
    if ( userList->selectedItems().size()==0 )
        return; // TODO : Warning message

    ca = buildAlert();

    // Creating a packet
    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);

    out << *ca;

    // Sending packet
    int ret = sockM->writeDatagram(packet, addrM, portM);
    qDebug() << "Number of bytes sended : " << ret << "\n";

    delete ca;
}

CasterAlert * CasterAlertSenderImpl::buildAlert()
{
    QList<QListWidgetItem *> selectedUsers = userList->selectedItems();
    CasterAlert *ca = new CasterAlert();

    ca->setFrom("caisse");

    for (int i=0; i<selectedUsers.size(); i++)
        ca->addTo(selectedUsers.at(i)->text());

    return ca;
}
