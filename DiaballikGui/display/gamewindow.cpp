#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <string>
#include <stdlib.h>
#include "../model/game.h"
#include "QDebug"
#include "vector"
#include <vector>
#include <regex>
#include <string>


using namespace std;

GameWindow::GameWindow(QWidget * parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    QPixmap blueCircle("Img/bluesupport.png");
    QPixmap redCircle("Img/redsupport.png");
    ui->BluePieceImg->setPixmap(blueCircle.scaled(15, 15,
                                Qt::KeepAspectRatio));
    ui->RedPieceImg->setPixmap(redCircle.scaled(15, 15,
                               Qt::KeepAspectRatio));
    QPixmap bkgnd("Img/Gamebackground.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    ui->console->setStyleSheet("background-color: #E1E1E1");
    ui->console->setFontPointSize(16);
    this->setWindowTitle("Diaballik - Jeu");
    this->bluewins = 0;
    this->redwins = 0;
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_skipButton_clicked()
{
    game->endTurn();
    if (game->getCurrent().getColor() == Color::BLUE)
    {
        ui->console->append("___ Its blue player turn! ___");
    }
    else
    {
        ui->console->append("___ Its red player turn! ___");
    }
    consoleinfo();
}

void GameWindow::on_conceedButton_clicked()
{

    QString win = getwinnerQwidget();

    QMessageBox::StandardButton reply = QMessageBox::question(this,
                                        "The Game if Finished",
                                        win + " Player Won the game. Do you want to play again?",
                                        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        if (win == "RED")
        {
            this->redwins = redwins + 1;
            ui->RedWins->clear();
            ui->RedWins->setNum(redwins);
        }
        else
        {
            this->bluewins = redwins + 1;
            ui->RedWins->clear();
            ui->BlueWins->setNum(bluewins);
        }
        ui->console->clear();
        on_restartgame_clicked();
    }
    else
    {
        QApplication::quit();
    }
}

void GameWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void GameWindow::on_actionAcceuil_triggered()
{
    hide();
    this->parentWidget()->show();

}
void GameWindow::setBlueName(QString name)
{
    ui->BluePlayerNameInfo->setText(name);
}
void GameWindow::setRedName(QString name)
{
    ui->RedPlayerNameInfo->setText(name);
}

void GameWindow::createBoard(int size, bool variant)
{
    this->variant= variant;
    _size = size;
    QPixmap blueCircle("Img/tile.png");
    for (int i = 0; i < size; i++)
    {
        std::vector<gameTile *> xx;
        for (int j = 0; j < size; j++)
        {
            gameTile * _piece = new gameTile(i, j, this);

            if (size == 5)
            {

                const QSize btnSize5 = QSize(75, 75);
                _piece->setFixedSize(btnSize5);
            }
            else if (size == 7)
            {

                const QSize btnSize7 = QSize(50, 50);
                _piece->setFixedSize(btnSize7);
            }
            else if (size == 9)
            {

                const QSize btnSize9 = QSize(40, 40);
                _piece->setFixedSize(btnSize9);
            }
            xx.push_back(_piece);

            connect(_piece, SIGNAL(clicked()), this, SLOT(on_gameTile_clicked()));
            ui->board->addWidget(_piece, i, j);
        }
        _gameboard.push_back(xx);
    }
    on_restartgame_clicked();
}

void GameWindow::on_gameTile_clicked()
{
    QObject * senderObj = sender();
    if (senderObj->isWidgetType())
    {
        gameTile * button = qobject_cast<gameTile *>(senderObj);
        if (button)
        {
            if (!game->isSelectedPiece())
            {
                if (game->isValidSelect(button->getrow(), button->getcolumn()))
                {
                    selectPiece(button);
                }
                else
                {
                    QString string("You cannot select this tile!");
                    error_message(string);
                }
            }
            else
            {
                if (game->getSelected().getType() == Type::BILLE)
                {
                    if (checkValidTilePass(button))
                    {
                        game->giveBall(game->getListValidPass().at(moveinteger));
                        updateview(game->getBoard());
                        checkEndGame();
                        checkEndTurn();
                        consoleinfo();
                        game->cleanvalidPass();
                        game->cleanselected();
                    }
                    else
                    {
                        QString string("You cannot pass to this piece!");
                        error_message(string);
                    }
                }
                else if (game->getSelected().getType() == Type::SUPPORT)
                {
                    if (game->isValidSelect(button->getrow(), button->getcolumn()))
                    {
                        selectPiece(button);
                    }
                    else
                    {
                        if (checkValidTileMove(button))
                        {
                            game->applyMove(game->getValidMoves().at(moveinteger));
                            updateview(game->getBoard());
                            checkEndGame();
                            checkEndTurn();
                            consoleinfo();
                            game->cleanValidMoves();
                            game->cleanselected();
                        }
                        else
                        {
                            QString string("You cannot select this tile!");
                            error_message(string);
                        }
                    }
                }
            }
        }
    }
}

bool GameWindow::checkValidTilePass(gameTile * button)
{
    for (Move pass : game->getListValidPass())
    {
        if ((pass.getEndPosition().getRow() == button->getrow()) &&
                (pass.getEndPosition().getColumn() == button->getcolumn()))
        {
            moveinteger = pass.getIndex();
            return true;
        }
    }
    return false;
}

bool GameWindow::checkValidTileMove(gameTile * button)
{
    for (Move move : game->getValidMoves())
    {
        if ((move.getEndPosition().getRow() == button->getrow()) &&
                (move.getEndPosition().getColumn() == button->getcolumn()))
        {
            moveinteger = move.getIndex();
            return true;
        }
    }
    return false;
}

void GameWindow::selectPiece(gameTile * button)
{
    updateview(game->getBoard());
    game->cleanValidMoves();
    game->cleanvalidPass();
    game->selectPosition(button->getrow(), button->getcolumn());
    if (game->getSelectedPieceType() == Type::SUPPORT)
    {
        if (game->checkMovePositions())
        {
            showMove();
        }
    }
    else
    {
        if (game->checkGiveBall())
        {
            showPass();
        }
    }

}

void GameWindow::showMove()
{
    QPixmap pixmap("Img/move.png");
    for (Move move : game->getValidMoves())
    {
        _gameboard.at(move.getEndPosition().getRow()).at(
            move.getEndPosition().getColumn())->setIcon(pixmap);
    }
}

void GameWindow::showPass()
{
    for (Move pass : game->getListValidPass())
    {
        _gameboard.at(pass.getEndPosition().getRow()).at(
            pass.getEndPosition().getColumn())->setText("PASS");
    }
}

void GameWindow::error_message(QString message)
{
    QMessageBox::information(this, "Action Refused", message);
}

void GameWindow::on_restartgame_clicked()
{
    game = new Game(this->variant,_size);
    game->initializeNewGame();
    game->startGame();
    updateview(game->getBoard());
    ui->console->append("______ Game stated ______\n");
    ui->console->append("___ Its blue player turn! ___");
    consoleinfo();
}

void GameWindow::consoleinfo()
{
    ui->console->append("moves left: " + QString::number(
                             game->getCurrent().getMovesLeft()));
    ui->console->append("pass left: " + QString::number(
                             game->getCurrent().getPassLeft()));
}

void GameWindow::checkEndTurn()
{
    if (game->getCurrent().getPassLeft() <= 0 &&
            game->getCurrent().getMovesLeft() <= 0)
    {
        consoleinfo();
        game->endTurn();
        updateview(game->getBoard());
        if (game->getCurrent().getColor() == Color::BLUE)
        {
            ui->console->append("___ Its blue player turn! ___");
        }
        else
        {
            ui->console->append("___ Its red player turn! ___");
        }
    }
}

void GameWindow::updateview(std::vector<std::vector<Square>>_board)
{
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            _gameboard.at(i).at(j)->setText("");
            if (_board.at(i).at(j).isMyOwn(Color::RED))
            {
                if (_board.at(i).at(j).getPieceType() == Type::SUPPORT)
                {
                    QPixmap redsupport("Img/redsupport.png");
                    _gameboard.at(i).at(j)->setIcon(redsupport);
                }
                else
                {
                    QPixmap redball("Img/redball.png");
                    _gameboard.at(i).at(j)->setIcon(redball);
                }
            }
            else if (_board.at(i).at(j).isMyOwn(Color::BLUE))
            {
                if (_board.at(i).at(j).getPieceType() == Type::SUPPORT)
                {
                    QPixmap bluesupport("Img/bluesupport.png");
                    _gameboard.at(i).at(j)->setIcon(bluesupport);
                }
                else
                {
                    QPixmap blueball("Img/blueball.png");
                    _gameboard.at(i).at(j)->setIcon(blueball);
                }
            }
            else
            {
                _gameboard.at(i).at(j)->setIcon(QIcon(""));
            }
        }
    }
}

void GameWindow::checkEndGame()
{
    if (game->checkWinner())
    {
        on_conceedButton_clicked();
    }
}

QString GameWindow::getwinnerQwidget()
{
    QString winner1;
    if (game->isOver())
    {
        if (game->getWinner() == Color::RED)
        {
            winner1 = "RED";
        }
        else
        {
            winner1 = "BLUE";
        }
    }
    else
    {
        if (game->getOpponent().getColor() == Color::RED)
        {
            winner1 = "RED";
        }
        else
        {
            winner1 = "BLUE";
        }
    }
    return winner1;
}
