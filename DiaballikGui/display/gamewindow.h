#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QMainWindow>
#include "tile.h"
#include "gametile.h"
#include "../model/game.h"
#include "../model/piece.h"
#include "../model/square.h"
#include "../model/position.h"
#include "../model/Color.h"
#include "../model/Color.h"
#include "../model/Type.h"
#include "../model/piece.h"
#include <stdlib.h>
#include "vector"
#include <vector>
#include "../model/board.h"
#include <optional>
#include <functional>
#include "gametile.h"
namespace Ui
{
class GameWindow;
}
class GameWindow : public QMainWindow
{
    Q_OBJECT
  public:
    /**
     * @brief GameWindow game window constructor
     * @param parent QMainWindow
     */
    explicit GameWindow(QWidget * parent = nullptr);
    /**
     * GameWindow destructor
     */
    ~GameWindow();
    /**
     * @brief setBlueName set blue player name
     * @param name blue player name
     */
    void setBlueName(QString name);
    /**
     * @brief setBlueName set red player name
     * @param name red player name
     */
    void setRedName(QString name);
    /**
     * @brief createBoard create game board visual
     * @param size game board size
     * @param variant parameter for pieces placement
     */
    void createBoard(int size, bool variant);
    /**
     * @brief selectPiece
     * @param button
     */
    void selectPiece(gameTile* button);
    /**
     * @brief showMove display a move
     */
    void showMove();
    /**
     * @brief showPass display a pass
     */
    void showPass();
    /**
     * @brief checkValidTileMove check if a move is valid
     * @param button selected button
     * @return true if move is valid
     */
    bool checkValidTileMove(gameTile* button);
    /**
     * @brief checkValidTilePass check if a pass is valid
     * @param button selected button
     * @return true if pass is valid
     */
    bool checkValidTilePass(gameTile* button);
    /**
     * @brief consoleinfo add console informations
     */
    void consoleinfo();
    /**
     * @brief checkEndTurn check if the current turn is finished
     */
    void checkEndTurn();
    /**
     * @brief updateview update the board
     * @param _board model game board
     */
    void updateview(std::vector<std::vector<Square>>_board);
    /**
     * @brief checkEndGame check if the game is finished
     */
    void checkEndGame();
    /**
     * @brief getwinnerQwidget get a Qwidget with winner name
     * @return Winner name
     */
    QString getwinnerQwidget();
  private slots:
    /**
     * @brief on_pushButton_clicked
     */
    void on_skipButton_clicked();
    /**
     * @brief on_conceedButton_clicked conceed for the current player
     */
    void on_conceedButton_clicked();
    /**
     * @brief on_actionQuit_triggered exit game page
     */
    void on_actionQuit_triggered();
    /**
     * @brief on_actionAcceuil_triggered back to main menu
     */
    void on_actionAcceuil_triggered();
    /**
     * @brief on_gameTile_clicked called when a gametile is clicked
     */
    void on_gameTile_clicked();
    /**
     * @brief on_restartgame_clicked restart the current game
     */
    void on_restartgame_clicked();
    /**
     * @brief error_message show a alert with an error message
     * @param message specific error
     */
    void error_message(QString message);
  private:
    /**
     * @brief ui QMainWindow
     */
    Ui::GameWindow * ui;
    /**
     * @brief game model interface
     */
    Game* game;
    /**
     * @brief _size board size
     */
    int _size;
    /**
     * @brief _gameboard gametiles container
     */
    std::vector<std::vector<gameTile*>>_gameboard;
    /**
     * @brief moveinteger moves integer
     */
    int moveinteger;
    /**
     * @brief winner game winner
     */
    QString winner;
    /**
     * @brief bluewins blue player total wins
     */
    int bluewins;
    /**
     * @brief redwins red player total wins
     */
    int redwins;
    /**
     * @brief variant true if variant is checked on mainwindow
     */
    bool variant;
};
#endif // GAMEWINDOW_H
