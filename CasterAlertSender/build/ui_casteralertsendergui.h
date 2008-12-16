/********************************************************************************
** Form generated from reading ui file 'casteralertsendergui.ui'
**
** Created: Tue Dec 16 19:33:54 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CASTERALERTSENDERGUI_H
#define UI_CASTERALERTSENDERGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CasterAlertSenderGUI
{
public:
    QWidget *centralwidget;
    QPushButton *sendAlertButton;
    QListWidget *userList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CasterAlertSenderGUI)
    {
    if (CasterAlertSenderGUI->objectName().isEmpty())
        CasterAlertSenderGUI->setObjectName(QString::fromUtf8("CasterAlertSenderGUI"));
    CasterAlertSenderGUI->resize(536, 388);
    centralwidget = new QWidget(CasterAlertSenderGUI);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    sendAlertButton = new QPushButton(centralwidget);
    sendAlertButton->setObjectName(QString::fromUtf8("sendAlertButton"));
    sendAlertButton->setGeometry(QRect(120, 130, 75, 25));
    userList = new QListWidget(centralwidget);
    new QListWidgetItem(userList);
    new QListWidgetItem(userList);
    new QListWidgetItem(userList);
    new QListWidgetItem(userList);
    userList->setObjectName(QString::fromUtf8("userList"));
    userList->setGeometry(QRect(360, 70, 120, 192));
    userList->setMaximumSize(QSize(120, 16777215));
    userList->setSelectionMode(QAbstractItemView::ExtendedSelection);
    CasterAlertSenderGUI->setCentralWidget(centralwidget);
    menubar = new QMenuBar(CasterAlertSenderGUI);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 536, 20));
    CasterAlertSenderGUI->setMenuBar(menubar);
    statusbar = new QStatusBar(CasterAlertSenderGUI);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    CasterAlertSenderGUI->setStatusBar(statusbar);

    retranslateUi(CasterAlertSenderGUI);

    QMetaObject::connectSlotsByName(CasterAlertSenderGUI);
    } // setupUi

    void retranslateUi(QMainWindow *CasterAlertSenderGUI)
    {
    CasterAlertSenderGUI->setWindowTitle(QApplication::translate("CasterAlertSenderGUI", "Caster Alert Sender", 0, QApplication::UnicodeUTF8));
    sendAlertButton->setText(QApplication::translate("CasterAlertSenderGUI", "SendAlert", 0, QApplication::UnicodeUTF8));

    const bool __sortingEnabled = userList->isSortingEnabled();
    userList->setSortingEnabled(false);
    userList->item(0)->setText(QApplication::translate("CasterAlertSenderGUI", "Dominique", 0, QApplication::UnicodeUTF8));
    userList->item(1)->setText(QApplication::translate("CasterAlertSenderGUI", "Jean-Yves", 0, QApplication::UnicodeUTF8));
    userList->item(2)->setText(QApplication::translate("CasterAlertSenderGUI", "R\303\251my", 0, QApplication::UnicodeUTF8));
    userList->item(3)->setText(QApplication::translate("CasterAlertSenderGUI", "???", 0, QApplication::UnicodeUTF8));

    userList->setSortingEnabled(__sortingEnabled);
    Q_UNUSED(CasterAlertSenderGUI);
    } // retranslateUi

};

namespace Ui {
    class CasterAlertSenderGUI: public Ui_CasterAlertSenderGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASTERALERTSENDERGUI_H
