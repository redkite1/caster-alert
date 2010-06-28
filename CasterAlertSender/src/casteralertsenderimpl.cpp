#include "casteralertsenderimpl.h"

CasterAlertSenderImpl::CasterAlertSenderImpl( QWidget * parent, Qt::WFlags f) : QMainWindow(parent, f)
{
    setupUi(this);

    // Read settings
    readSettings();

    addrM.setAddress("225.1.2.3");
    portM = (quint16) 22512;
    initSocket();

    initTray();
}

void CasterAlertSenderImpl::initSocket()
{
    sockM = new QUdpSocket(this);
    sockM->bind(this->portM, QUdpSocket::ShareAddress);     // Listening on : ip=QHostAddress::Any(it's an overloaded method), port=portM
                                                            // QUdpSocket::ShareAddress = Allow other services to bind to the same address and port
}

void CasterAlertSenderImpl::on_addUserPB_clicked()
{
    QString user = QInputDialog::getText(this, trUtf8("Username"), trUtf8("Username to add to the list :"), QLineEdit::Normal, trUtf8("username"));

    /* Check if user is not empty and if username specied is not already in the list */
    if ( user != "" && userLW->findItems(user, Qt::MatchFixedString).count()==0 )
        userLW->addItem(user);
}

void CasterAlertSenderImpl::on_removeUserPB_clicked()
{
    QList<QListWidgetItem *> lwi = userLW->selectedItems();
    int nbr = lwi.count();

    for (int i=0; i<nbr; ++i)
        delete lwi.at(i);
}

void CasterAlertSenderImpl::on_sendAlertPB_clicked()
{
    CasterAlert *ca = NULL;

    // Check if at least one user is selected as target
    if ( userLW->selectedItems().size()==0 ) {
        statusbar->showMessage(trUtf8("Alert not sended"), 3000);
        return;
    }

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
    CasterAlert *ca = new CasterAlert();
    ca->setFrom(fromLE->text());

    QList<QListWidgetItem *> selectedUsers = userLW->selectedItems();

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

    fromLE->setText(settings.value("sender", "Sender").toString());
    userLW->addItems(settings.value("users/list", NULL).toStringList());
}

void CasterAlertSenderImpl::writeSettings()
{
    QSettings settings;

    settings.setValue("sender", fromLE->text());
    settings.setValue("users/list", getUserList(false));
}

QStringList CasterAlertSenderImpl::getUserList(bool onlySelectedUsers)
{
    QStringList slu;
    QList<QListWidgetItem *> lwi;
    int nbr;

    if ( onlySelectedUsers )
        lwi = userLW->selectedItems();
    else
    {
        nbr = userLW->count();
        for (int i=0; i<nbr; i++)
            lwi.append(userLW->item(i));
    }

    nbr = lwi.count();
    for (int i=0; i<nbr; i++)
        slu.append(lwi.at(i)->text());

    return slu;
}

/*
 * Functions for tray icon
 */

void CasterAlertSenderImpl::initTray()
{
    /*
     * Va initialiser et afficher un icone dans le systeme tray
     */

    sticon = new QSystemTrayIcon(QIcon(":/icons/images/icons/edit_add.png"),this);

    stmenu = new QMenu(this);

    QAction *aff_cach = new QAction("Afficher / Cacher",this);              // Crée une action
    stmenu->addAction(aff_cach);                                            // L'ajoute dans un menu
    stmenu->setDefaultAction(aff_cach);                                     // Change l'APPARANCE de l'action (en gras) et c'est tout!
    connect(aff_cach,SIGNAL(triggered()),this,SLOT(show_hide()));           // Lie l'actionau slot qui affiche/cache la fenêtre principale

    stmenu->setSeparatorsCollapsible(false);
    stmenu->addSeparator();
    stmenu->addSeparator();

    connect(sticon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(sticon_dblclicked(QSystemTrayIcon::ActivationReason)));

    QAction *quit = new QAction("Quitter",this);
    stmenu->addAction(quit);
    connect(quit,SIGNAL(triggered()),this,SLOT(exit_applic()));

    sticon->setContextMenu(stmenu); // On assigne le menu contextuel à l'icône de notification
    sticon->show();

    return;
}

void CasterAlertSenderImpl::show_hide()
{
    if(this->isHidden())
    {
            /*
             * void QWidget::activateWindow ()
             *
             * This function performs the same operation as clicking the mouse on the title bar of a top-level window.
             * On X11, the result depends on the Window Manager. If you want to ensure that the window is stacked on top
             * as well you should also call raise(). Note that the window must be visible, otherwise activateWindow() has no effect.
             */
            this->show();
            this->raise();
            this->activateWindow();
    }
    else
        if(this->isMinimized())
        {
                this->showNormal();
                //raise et activate? faire test sous windows
        }
        else
                this->hide();

    return;
}

void CasterAlertSenderImpl::sticon_dblclicked(QSystemTrayIcon::ActivationReason reason)
{
    if ( reason == 2 || reason == 3 )
            this->show_hide();

    return;
}

void CasterAlertSenderImpl::exit_applic()
{
    sticon->hide();
    this->close();
}

void CasterAlertSenderImpl::update_tray_actions()
{
    // Mise à jour du menu du system Tray
    /* TODO : faire un signal mapper qui va appeller une fct qui en fct du nom, crée une alert, et l'envoit
    QAction *act = new QAction(t,this);
    connect(act,SIGNAL(triggered()),button1,SLOT(click()));
    QList<QAction *> list = stmenu->actions();	// Pour pouvoir récupérer le before
    stmenu->insertAction(list.at(list.size()-2),act);
    */
}
