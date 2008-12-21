#include "casteralertsenderimpl.h"

CasterAlertSenderImpl::CasterAlertSenderImpl( QWidget * parent, Qt::WFlags f) : QMainWindow(parent, f)
{
    setupUi(this);

    // Read settings
    readSettings();

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

void CasterAlertSenderImpl::on_addUserButton_clicked()
{
    QString user = QInputDialog::getText(this, trUtf8("Username"), trUtf8("Username to add to the list :               "), QLineEdit::Normal, trUtf8("username"));

    if ( user != "" && userList->findItems(user, Qt::MatchFixedString).count()==0 )
        userList->addItem(user);
}

void CasterAlertSenderImpl::on_removeUserButton_clicked()
{
    QList<QListWidgetItem *> lwi = userList->selectedItems();
    int nbr = lwi.count();

    for (int i=0; i<nbr; i++)
        delete lwi.at(i);
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

    if (ret == packet.size())
        statusbar->showMessage(trUtf8("Alert sended"), 3000);
    else
        statusbar->showMessage(trUtf8("Send error !"), 3000);

    delete ca;
}

CasterAlert * CasterAlertSenderImpl::buildAlert()
{
    QList<QListWidgetItem *> selectedUsers = userList->selectedItems();
    CasterAlert *ca = new CasterAlert();

    ca->setFrom(fromField->text());

    for (int i=0; i<selectedUsers.size(); i++)
        ca->addTo(selectedUsers.at(i)->text());

    return ca;
}

void CasterAlertSenderImpl::closeEvent(QCloseEvent *event)
{
    writeSettings();
    event->accept();
}

void CasterAlertSenderImpl::readSettings()
{
    QSettings settings;

    fromField->setText(settings.value("sender", "Sender").toString());
    userList->addItems(settings.value("users/list", NULL).toStringList());
}

void CasterAlertSenderImpl::writeSettings()
{
    QSettings settings;

    settings.setValue("sender", fromField->text());
    settings.setValue("users/list", getUserList(false));
}

QStringList CasterAlertSenderImpl::getUserList(bool onlySelectedUsers)
{
    QStringList slu;
    QList<QListWidgetItem *> lwi;
    int nbr;

    if ( onlySelectedUsers )
        lwi = userList->selectedItems();
    else
    {
        nbr = userList->count();
        for (int i=0; i<nbr; i++)
            lwi.append(userList->item(i));
    }

    nbr = lwi.count();
    for (int i=0; i<nbr; i++)
        slu.append(lwi.at(i)->text());

    return slu;
}
