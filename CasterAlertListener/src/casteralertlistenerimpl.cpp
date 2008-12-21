#include "casteralertlistenerimpl.h"


CasterAlertListenerImpl::CasterAlertListenerImpl( QWidget * parent, Qt::WFlags f) : QMainWindow(parent, f), sockM(NULL), mediaObject(NULL), audioOutput(NULL)
{
    setupUi(this);

    // Read settings
    readSettings();

    connect(startButton, SIGNAL(clicked()), this, SLOT(startListenning()));
    connect(stopButton, SIGNAL(clicked()),this,SLOT(stopListenning()));
    connect(actionChoose_sound, SIGNAL(triggered()), SLOT(selectSong()));
}

void CasterAlertListenerImpl::startListenning()
{
    sockM = new QUdpSocket(this);

    portM = 22512;
    addrM = "225.1.2.3";
    sockM->bind(this->portM, QUdpSocket::ReuseAddressHint);  // Surcharge de bind, prend QHostAddress::Any

    // S'abonner a l adresse multicast ! (Qt ne gère pas, il faut appeler les méthode natives mais qd meme standard)
    struct ip_mreq mreq;
    mreq.imr_multiaddr.s_addr = inet_addr((const char*)addrM.toString().toStdString().c_str());
    mreq.imr_interface.s_addr = INADDR_ANY;
    int r = ::setsockopt(sockM->socketDescriptor(), IPPROTO_IP, IP_ADD_MEMBERSHIP, (const char *)&mreq, sizeof(struct ip_mreq));
    qDebug("setsockopt returned %d", r);

    connect(sockM, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
    stopButton->setEnabled(true);
    startButton->setEnabled(false);
}

void CasterAlertListenerImpl::stopListenning()
{
    sockM->abort();
    stopButton->setEnabled(false);
    startButton->setEnabled(true);
}

void CasterAlertListenerImpl::readPendingDatagrams()
{
    //qDebug() << "Receiving datagram";

    while (sockM->hasPendingDatagrams())
    {
        QByteArray datagram;
        QHostAddress sender;
        quint16 senderPort;

        datagram.resize(sockM->pendingDatagramSize());
        sockM->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        CasterAlert ca;
        QDataStream in(&datagram, QIODevice::ReadOnly);
        in >> ca;

        //qDebug() << "From : " + ca.getFrom();

        if (checkConcern(ca))
        {
            statusbar->showMessage("Alert received", 3000);
            performAlert(ca);
        }
        else
            statusbar->showMessage("Alert ignored", 3000);

        //qDebug() << datagram.data();
        //qDebug() << sender;
        //qDebug() << senderPort << endl;
    }
}

void CasterAlertListenerImpl::performAlert(const CasterAlert &ca)
{
    if (actionSound->isChecked())
        playSound();

    if (actionVisual->isChecked())
        showAlert(ca);

    if ( !actionSound->isChecked() && !actionVisual->isChecked() )
        QApplication::beep();
}

bool CasterAlertListenerImpl::checkConcern(const CasterAlert &ca) const
{
    QList<QListWidgetItem *> selectedUsers = userList->selectedItems();
    QList<QString> to = ca.getTo();

    for(int i=0; i < selectedUsers.size(); i++)
    {
        if ( to.contains(selectedUsers.at(i)->text()) )
            return true;
    }

    return false;
}

void CasterAlertListenerImpl::playSound()
{
    if (mediaObject == NULL)
    {
        mediaObject = new Phonon::MediaObject(this);
        audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
        Phonon::createPath(mediaObject, audioOutput);
    }

    mediaObject->setCurrentSource(Phonon::MediaSource(songPath));
    mediaObject->play();
    // TODO : check if there was an erro Phonon::ErrorState to check if the file is playable or ...
}

void CasterAlertListenerImpl::on_addUserButton_clicked()
{
    QString user = QInputDialog::getText(this, trUtf8("Username"), trUtf8("Username to add to the list :               "), QLineEdit::Normal, trUtf8("username"));

    if ( user != "" && userList->findItems(user, Qt::MatchFixedString).count()==0 )
        userList->addItem(user);
}

void CasterAlertListenerImpl::on_removeUserButton_clicked()
{    
    QList<QListWidgetItem *> lwi = userList->selectedItems();
    int nbr = lwi.count();

    for (int i=0; i<nbr; i++)
        delete lwi.at(i);
}

void CasterAlertListenerImpl::readSettings()
{
    QSettings settings;

    actionSound->setChecked(settings.value("alert/sound", false).toBool());
    actionVisual->setChecked(settings.value("alert/visual", false).toBool());
    songPath = settings.value("alert/songpath", "").toString();
    userList->addItems(settings.value("users/list", NULL).toStringList());
    QBitArray ba = settings.value("users/listselection").toBitArray();
    for (int i=0; i<ba.size(); i++)
        userList->item(i)->setSelected(ba.at(i));
}

void CasterAlertListenerImpl::writeSettings()
{
    QSettings settings;

    settings.setValue("alert/sound", actionSound->isChecked());
    settings.setValue("alert/visual", actionVisual->isChecked());
    settings.setValue("alert/songpath", songPath);
    settings.setValue("users/list", getUserList(false));
    settings.setValue("users/listselection", getSelectionList());
}

void CasterAlertListenerImpl::closeEvent(QCloseEvent *event)
{
    writeSettings();
    event->accept();
}

void CasterAlertListenerImpl::selectSong()
{
    songPath = QFileDialog::getOpenFileName(this, trUtf8("Choose a alert song"), QDir::homePath());
}

QStringList CasterAlertListenerImpl::getUserList(bool onlySelectedUsers)
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

QBitArray CasterAlertListenerImpl::getSelectionList()
{
    QBitArray ba;
    int nbr = userList->count();

    ba.resize(nbr);
    for (int i=0; i<nbr; i++)
        ba.setBit(i,userList->item(i)->isSelected());

    return ba;
}

void CasterAlertListenerImpl::showAlert(const CasterAlert &ca)
{
    QMessageBox::information(this,trUtf8("Caster Alert received"), "'" + ca.getFrom() + "'" + trUtf8(" is requesting your help."));
}










