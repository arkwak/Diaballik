/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QAction *actionQuit;
    QAction *actionAcceuil;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *BluePlayerInfo;
    QLabel *BluePieceInfo;
    QLabel *BlueWinsInfo;
    QLabel *BluePlayerNameInfo;
    QLabel *BluePieceImg;
    QLabel *BlueWins;
    QGridLayout *gridLayout_2;
    QLabel *RedPlayerInfo;
    QLabel *RedPieceInfo;
    QLabel *RedWinsInfo;
    QLabel *RedPlayerNameInfo;
    QLabel *RedPieceImg;
    QLabel *RedWins;
    QTextEdit *console;
    QPushButton *restartgame;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *board;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *skipButton;
    QPushButton *conceedButton;
    QMenuBar *menubar;
    QMenu *menuQuitter;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(800, 600);
        actionQuit = new QAction(GameWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/Img/Quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon);
        actionAcceuil = new QAction(GameWindow);
        actionAcceuil->setObjectName(QString::fromUtf8("actionAcceuil"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/Img/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAcceuil->setIcon(icon1);
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(460, 0, 331, 551));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 30, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 10, 0, -1);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        BluePlayerInfo = new QLabel(layoutWidget);
        BluePlayerInfo->setObjectName(QString::fromUtf8("BluePlayerInfo"));

        gridLayout->addWidget(BluePlayerInfo, 0, 0, 1, 1);

        BluePieceInfo = new QLabel(layoutWidget);
        BluePieceInfo->setObjectName(QString::fromUtf8("BluePieceInfo"));

        gridLayout->addWidget(BluePieceInfo, 0, 1, 1, 1);

        BlueWinsInfo = new QLabel(layoutWidget);
        BlueWinsInfo->setObjectName(QString::fromUtf8("BlueWinsInfo"));

        gridLayout->addWidget(BlueWinsInfo, 0, 2, 1, 1);

        BluePlayerNameInfo = new QLabel(layoutWidget);
        BluePlayerNameInfo->setObjectName(QString::fromUtf8("BluePlayerNameInfo"));

        gridLayout->addWidget(BluePlayerNameInfo, 1, 0, 1, 1);

        BluePieceImg = new QLabel(layoutWidget);
        BluePieceImg->setObjectName(QString::fromUtf8("BluePieceImg"));

        gridLayout->addWidget(BluePieceImg, 1, 1, 1, 1);

        BlueWins = new QLabel(layoutWidget);
        BlueWins->setObjectName(QString::fromUtf8("BlueWins"));

        gridLayout->addWidget(BlueWins, 1, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        RedPlayerInfo = new QLabel(layoutWidget);
        RedPlayerInfo->setObjectName(QString::fromUtf8("RedPlayerInfo"));

        gridLayout_2->addWidget(RedPlayerInfo, 0, 0, 1, 1);

        RedPieceInfo = new QLabel(layoutWidget);
        RedPieceInfo->setObjectName(QString::fromUtf8("RedPieceInfo"));

        gridLayout_2->addWidget(RedPieceInfo, 0, 1, 1, 1);

        RedWinsInfo = new QLabel(layoutWidget);
        RedWinsInfo->setObjectName(QString::fromUtf8("RedWinsInfo"));

        gridLayout_2->addWidget(RedWinsInfo, 0, 2, 1, 1);

        RedPlayerNameInfo = new QLabel(layoutWidget);
        RedPlayerNameInfo->setObjectName(QString::fromUtf8("RedPlayerNameInfo"));

        gridLayout_2->addWidget(RedPlayerNameInfo, 1, 0, 1, 1);

        RedPieceImg = new QLabel(layoutWidget);
        RedPieceImg->setObjectName(QString::fromUtf8("RedPieceImg"));

        gridLayout_2->addWidget(RedPieceImg, 1, 1, 1, 1);

        RedWins = new QLabel(layoutWidget);
        RedWins->setObjectName(QString::fromUtf8("RedWins"));

        gridLayout_2->addWidget(RedWins, 1, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        console = new QTextEdit(layoutWidget);
        console->setObjectName(QString::fromUtf8("console"));
        console->setAcceptDrops(true);
        console->setReadOnly(true);

        verticalLayout->addWidget(console);

        restartgame = new QPushButton(layoutWidget);
        restartgame->setObjectName(QString::fromUtf8("restartgame"));

        verticalLayout->addWidget(restartgame);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 431, 551));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        board = new QGridLayout();
        board->setSpacing(0);
        board->setObjectName(QString::fromUtf8("board"));
        board->setContentsMargins(50, 120, 30, 40);

        verticalLayout_2->addLayout(board);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(50, -1, 30, -1);
        skipButton = new QPushButton(layoutWidget1);
        skipButton->setObjectName(QString::fromUtf8("skipButton"));

        horizontalLayout_2->addWidget(skipButton);

        conceedButton = new QPushButton(layoutWidget1);
        conceedButton->setObjectName(QString::fromUtf8("conceedButton"));

        horizontalLayout_2->addWidget(conceedButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        GameWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuQuitter = new QMenu(menubar);
        menuQuitter->setObjectName(QString::fromUtf8("menuQuitter"));
        GameWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GameWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GameWindow->setStatusBar(statusbar);

        menubar->addAction(menuQuitter->menuAction());
        menuQuitter->addAction(actionQuit);
        menuQuitter->addAction(actionAcceuil);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "MainWindow", nullptr));
        actionQuit->setText(QCoreApplication::translate("GameWindow", "Exit", nullptr));
        actionAcceuil->setText(QCoreApplication::translate("GameWindow", "Home", nullptr));
        BluePlayerInfo->setText(QCoreApplication::translate("GameWindow", "Blue Player", nullptr));
        BluePieceInfo->setText(QCoreApplication::translate("GameWindow", "Piece", nullptr));
        BlueWinsInfo->setText(QCoreApplication::translate("GameWindow", "wins", nullptr));
        BluePlayerNameInfo->setText(QCoreApplication::translate("GameWindow", "Philistin", nullptr));
        BluePieceImg->setText(QString());
        BlueWins->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        RedPlayerInfo->setText(QCoreApplication::translate("GameWindow", "Red Player", nullptr));
        RedPieceInfo->setText(QCoreApplication::translate("GameWindow", "Piece", nullptr));
        RedWinsInfo->setText(QCoreApplication::translate("GameWindow", "wins", nullptr));
        RedPlayerNameInfo->setText(QCoreApplication::translate("GameWindow", "Clitorine", nullptr));
        RedPieceImg->setText(QString());
        RedWins->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        restartgame->setText(QCoreApplication::translate("GameWindow", "Restart Game", nullptr));
        skipButton->setText(QCoreApplication::translate("GameWindow", "Skip your turn", nullptr));
        conceedButton->setText(QCoreApplication::translate("GameWindow", "Conceed", nullptr));
        menuQuitter->setTitle(QCoreApplication::translate("GameWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
