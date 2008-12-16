#ifndef CASTERALERTLISTENERIMPL_H
#define CASTERALERTLISTENERIMPL_H

#include <QtGlobal>         // Pour que les macro Q_OS_UNIX etc soient définis
#include <QMainWindow>
#include "ui_casteralertlistenergui.h"
#include "../libs/src/casteralert.h"
#include <QUdpSocket>
#include <QPlainTextEdit>
#include <QInputDialog>

// Car Qt gère pas encore comme il faut le multicast ... tututut
#if defined (Q_OS_UNIX)
#  include <sys/types.h>
#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <arpa/inet.h>
#endif
#ifdef Q_WS_WIN
#  include <winsock2.h>
#  include <ws2tcpip.h>
#endif

class CasterAlertListenerImpl : public QMainWindow, public Ui::CasterAlertListenerGUI
{
    Q_OBJECT

public:
    CasterAlertListenerImpl( QWidget * parent = 0, Qt::WFlags f = 0 );

public slots:
    void startListenning();

private slots:
    void readPendingDatagrams();
    void stopListenning();
    void on_addUserButton_clicked();
    void on_removeUserButton_clicked();

private:
    bool checkConcern(const CasterAlert& ca) const;

    QUdpSocket *sockM;      // Multicast UDP socket for listenning alerts
    QHostAddress addrM;     // Multicast address for listenning alerts
    quint16 portM;          // Multicast port for listenning alerts
};

#endif




