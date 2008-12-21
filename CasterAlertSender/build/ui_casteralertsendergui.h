/********************************************************************************
** Form generated from reading ui file 'casteralertsendergui.ui'
**
** Created: Sun Dec 21 17:27:05 2008
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CasterAlertSenderGUI
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *fromField;
    QLabel *label;
    QListWidget *userList;
    QHBoxLayout *horizontalLayout;
    QPushButton *addUserButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *removeUserButton;
    QPushButton *sendAlertButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CasterAlertSenderGUI)
    {
    if (CasterAlertSenderGUI->objectName().isEmpty())
        CasterAlertSenderGUI->setObjectName(QString::fromUtf8("CasterAlertSenderGUI"));
    CasterAlertSenderGUI->resize(156, 326);
    centralwidget = new QWidget(CasterAlertSenderGUI);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    verticalLayout = new QVBoxLayout(centralwidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    label_2 = new QLabel(centralwidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    QFont font;
    font.setBold(true);
    font.setUnderline(false);
    font.setWeight(75);
    label_2->setFont(font);
    label_2->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label_2);

    fromField = new QLineEdit(centralwidget);
    fromField->setObjectName(QString::fromUtf8("fromField"));

    verticalLayout->addWidget(fromField);

    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label);

    userList = new QListWidget(centralwidget);
    userList->setObjectName(QString::fromUtf8("userList"));
    userList->setSelectionMode(QAbstractItemView::MultiSelection);

    verticalLayout->addWidget(userList);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    addUserButton = new QPushButton(centralwidget);
    addUserButton->setObjectName(QString::fromUtf8("addUserButton"));
    addUserButton->setMaximumSize(QSize(24, 24));
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/icons/add")), QIcon::Normal, QIcon::Off);
    addUserButton->setIcon(icon);

    horizontalLayout->addWidget(addUserButton);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);

    removeUserButton = new QPushButton(centralwidget);
    removeUserButton->setObjectName(QString::fromUtf8("removeUserButton"));
    removeUserButton->setMaximumSize(QSize(24, 24));
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/icons/remove")), QIcon::Normal, QIcon::Off);
    removeUserButton->setIcon(icon1);

    horizontalLayout->addWidget(removeUserButton);


    verticalLayout->addLayout(horizontalLayout);

    sendAlertButton = new QPushButton(centralwidget);
    sendAlertButton->setObjectName(QString::fromUtf8("sendAlertButton"));

    verticalLayout->addWidget(sendAlertButton);

    CasterAlertSenderGUI->setCentralWidget(centralwidget);
    menubar = new QMenuBar(CasterAlertSenderGUI);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 156, 23));
    CasterAlertSenderGUI->setMenuBar(menubar);
    statusbar = new QStatusBar(CasterAlertSenderGUI);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    CasterAlertSenderGUI->setStatusBar(statusbar);

    retranslateUi(CasterAlertSenderGUI);

    QMetaObject::connectSlotsByName(CasterAlertSenderGUI);
    } // setupUi

    void retranslateUi(QMainWindow *CasterAlertSenderGUI)
    {
    CasterAlertSenderGUI->setWindowTitle(QApplication::translate("CasterAlertSenderGUI", "CAS : Caster Alert Sender", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("CasterAlertSenderGUI", "From :", 0, QApplication::UnicodeUTF8));
    fromField->setText(QApplication::translate("CasterAlertSenderGUI", "Comptoir", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("CasterAlertSenderGUI", "Recipient(s) :", 0, QApplication::UnicodeUTF8));
    addUserButton->setText(QString());
    removeUserButton->setText(QString());
    sendAlertButton->setText(QApplication::translate("CasterAlertSenderGUI", "Send Alert", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CasterAlertSenderGUI);
    } // retranslateUi

};

namespace Ui {
    class CasterAlertSenderGUI: public Ui_CasterAlertSenderGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASTERALERTSENDERGUI_H
