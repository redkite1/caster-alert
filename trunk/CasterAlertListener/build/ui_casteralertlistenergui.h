/********************************************************************************
** Form generated from reading ui file 'casteralertlistenergui.ui'
**
** Created: Tue Dec 16 19:33:49 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CASTERALERTLISTENERGUI_H
#define UI_CASTERALERTLISTENERGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CasterAlertListenerGUI
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *stopButton;
    QPlainTextEdit *infoConsole;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *userList;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CasterAlertListenerGUI)
    {
    if (CasterAlertListenerGUI->objectName().isEmpty())
        CasterAlertListenerGUI->setObjectName(QString::fromUtf8("CasterAlertListenerGUI"));
    CasterAlertListenerGUI->resize(451, 388);
    centralwidget = new QWidget(CasterAlertListenerGUI);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    horizontalLayout_4 = new QHBoxLayout(centralwidget);
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    startButton = new QPushButton(centralwidget);
    startButton->setObjectName(QString::fromUtf8("startButton"));

    horizontalLayout->addWidget(startButton);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);

    stopButton = new QPushButton(centralwidget);
    stopButton->setObjectName(QString::fromUtf8("stopButton"));

    horizontalLayout->addWidget(stopButton);


    verticalLayout->addLayout(horizontalLayout);

    infoConsole = new QPlainTextEdit(centralwidget);
    infoConsole->setObjectName(QString::fromUtf8("infoConsole"));

    verticalLayout->addWidget(infoConsole);


    horizontalLayout_4->addLayout(verticalLayout);

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
    verticalSpacer = new QSpacerItem(167, 78, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer);

    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font;
    font.setBold(true);
    font.setUnderline(false);
    font.setWeight(75);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);

    verticalLayout_2->addWidget(label);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer_2);

    userList = new QListWidget(centralwidget);
    new QListWidgetItem(userList);
    new QListWidgetItem(userList);
    new QListWidgetItem(userList);
    new QListWidgetItem(userList);
    userList->setObjectName(QString::fromUtf8("userList"));
    userList->setMaximumSize(QSize(120, 16777215));
    userList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    userList->setAlternatingRowColors(false);
    userList->setSelectionMode(QAbstractItemView::ExtendedSelection);
    userList->setTextElideMode(Qt::ElideMiddle);

    horizontalLayout_3->addWidget(userList);

    horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer_3);


    verticalLayout_2->addLayout(horizontalLayout_3);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
    toolButton_2 = new QToolButton(centralwidget);
    toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

    horizontalLayout_2->addWidget(toolButton_2);

    toolButton = new QToolButton(centralwidget);
    toolButton->setObjectName(QString::fromUtf8("toolButton"));

    horizontalLayout_2->addWidget(toolButton);


    verticalLayout_2->addLayout(horizontalLayout_2);

    verticalSpacer_2 = new QSpacerItem(167, 33, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_2);


    horizontalLayout_4->addLayout(verticalLayout_2);

    CasterAlertListenerGUI->setCentralWidget(centralwidget);
    menubar = new QMenuBar(CasterAlertListenerGUI);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 451, 20));
    CasterAlertListenerGUI->setMenuBar(menubar);
    statusbar = new QStatusBar(CasterAlertListenerGUI);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    CasterAlertListenerGUI->setStatusBar(statusbar);

    retranslateUi(CasterAlertListenerGUI);

    QMetaObject::connectSlotsByName(CasterAlertListenerGUI);
    } // setupUi

    void retranslateUi(QMainWindow *CasterAlertListenerGUI)
    {
    CasterAlertListenerGUI->setWindowTitle(QApplication::translate("CasterAlertListenerGUI", "Caster Alert Listner", 0, QApplication::UnicodeUTF8));
    startButton->setText(QApplication::translate("CasterAlertListenerGUI", "Start Ecoute", 0, QApplication::UnicodeUTF8));
    stopButton->setText(QApplication::translate("CasterAlertListenerGUI", "Stop Ecoute", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("CasterAlertListenerGUI", "Utilisateur \303\240 \303\251couter :", 0, QApplication::UnicodeUTF8));

    const bool __sortingEnabled = userList->isSortingEnabled();
    userList->setSortingEnabled(false);
    userList->item(0)->setText(QApplication::translate("CasterAlertListenerGUI", "Dominique", 0, QApplication::UnicodeUTF8));
    userList->item(1)->setText(QApplication::translate("CasterAlertListenerGUI", "Jean-Yves", 0, QApplication::UnicodeUTF8));
    userList->item(2)->setText(QApplication::translate("CasterAlertListenerGUI", "R\303\251my", 0, QApplication::UnicodeUTF8));
    userList->item(3)->setText(QApplication::translate("CasterAlertListenerGUI", "???", 0, QApplication::UnicodeUTF8));

    userList->setSortingEnabled(__sortingEnabled);
    toolButton_2->setText(QApplication::translate("CasterAlertListenerGUI", "...", 0, QApplication::UnicodeUTF8));
    toolButton->setText(QApplication::translate("CasterAlertListenerGUI", "...", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CasterAlertListenerGUI);
    } // retranslateUi

};

namespace Ui {
    class CasterAlertListenerGUI: public Ui_CasterAlertListenerGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASTERALERTLISTENERGUI_H
