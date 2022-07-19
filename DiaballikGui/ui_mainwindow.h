/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *BluePlayer;
    QLineEdit *BluePlayerName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *RedPlayer;
    QLineEdit *RedPlayerName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QRadioButton *Five;
    QRadioButton *Seven;
    QRadioButton *Nine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuQuit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/Img/Quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(250, 200, 327, 241));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        BluePlayer = new QLabel(layoutWidget);
        BluePlayer->setObjectName(QString::fromUtf8("BluePlayer"));

        horizontalLayout->addWidget(BluePlayer);

        BluePlayerName = new QLineEdit(layoutWidget);
        BluePlayerName->setObjectName(QString::fromUtf8("BluePlayerName"));

        horizontalLayout->addWidget(BluePlayerName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        RedPlayer = new QLabel(layoutWidget);
        RedPlayer->setObjectName(QString::fromUtf8("RedPlayer"));

        horizontalLayout_2->addWidget(RedPlayer);

        RedPlayerName = new QLineEdit(layoutWidget);
        RedPlayerName->setObjectName(QString::fromUtf8("RedPlayerName"));

        horizontalLayout_2->addWidget(RedPlayerName);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        Five = new QRadioButton(layoutWidget);
        Five->setObjectName(QString::fromUtf8("Five"));
        Five->setChecked(true);

        horizontalLayout_4->addWidget(Five);

        Seven = new QRadioButton(layoutWidget);
        Seven->setObjectName(QString::fromUtf8("Seven"));

        horizontalLayout_4->addWidget(Seven);

        Nine = new QRadioButton(layoutWidget);
        Nine->setObjectName(QString::fromUtf8("Nine"));

        horizontalLayout_4->addWidget(Nine);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setScaledContents(false);

        horizontalLayout_3->addWidget(label_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_3->addWidget(checkBox);


        horizontalLayout_3->addLayout(verticalLayout_3);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuQuit = new QMenu(menubar);
        menuQuit->setObjectName(QString::fromUtf8("menuQuit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        BluePlayer->setBuddy(BluePlayerName);
        RedPlayer->setBuddy(RedPlayerName);
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menuQuit->menuAction());
        menuQuit->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        BluePlayer->setText(QCoreApplication::translate("MainWindow", "Player 1", nullptr));
        BluePlayerName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your name...", nullptr));
        RedPlayer->setText(QCoreApplication::translate("MainWindow", "Player 2", nullptr));
        RedPlayerName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your name...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Game board size :", nullptr));
        Five->setText(QCoreApplication::translate("MainWindow", "5x5", nullptr));
        Seven->setText(QCoreApplication::translate("MainWindow", "7x7", nullptr));
        Nine->setText(QCoreApplication::translate("MainWindow", "9x9", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "BY G42991 & G52167", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Variant", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Launch Game", nullptr));
        menuQuit->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
