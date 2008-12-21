#ifndef CASTERALERTSENDERIMPL_H
#define CASTERALERTSENDERIMPL_H

//#ifdef Q_WS_X11
#  include <sys/types.h>
#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <arpa/inet.h>
//#else
//#  include <winsock2.h>
//#  include <ws2tcpip.h>
//#endif

#include <QMainWindow>
#include "ui_casteralertsendergui.h"
#include "../libs/src/casteralert.h"
#include <QUdpSocket>
#include <QHostAddress>
#include <QByteArray>
#include <QDataStream>
#include <QInputDialog>
#include <QSettings>
#include <QCloseEvent>

#include <QtDebug>

class CasterAlertSenderImpl : public QMainWindow, public Ui::CasterAlertSenderGUI
{
    Q_OBJECT

public:
    CasterAlertSenderImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
    void initSocket();

private slots:
    void readPendingDatagramsM();
    void on_sendAlertButton_clicked();
    void on_addUserButton_clicked();
    void on_removeUserButton_clicked();
    void readSettings();
    void writeSettings();
    void closeEvent(QCloseEvent *event);

private:
    CasterAlert * buildAlert();
    QStringList getUserList(bool onlySelectedUsers);

    QUdpSocket *sockM;      // Multicast UDP socket for sending alerts
    QHostAddress addrM;     // Multicast address for sending alerts
    quint16 portM;          // Multicast port for sending alerts
};

#endif




