#ifndef PLAYER_H
#define PLAYER_H
#include "Color.h"
#include "piece.h"
#include <list>
#include <iostream>
#include <stdlib.h>
#include "vector"
using namespace std;
/**
 * @brief The Player class manage a player
 */
class Player
{
  private:
    /**
     * @brief _playerColor the color of a player
     */
    Color _playerColor;
    /**
     * @brief _PieceList the list of pieces owned
     */
    vector<Piece> _PieceList;
    /**
     * @brief _movesLeft actual turn moves left
     */
    unsigned _movesLeft;
    /**
     * @brief _passLeft actual turn pass left
     */
    unsigned _passLeft;
    /**
     * @brief winner say if the player is the winner
     */
    bool winner;
  public:
    /**
     * @brief Player constructs a player with a  color
     * @param playerColor the color of the player
     */
    Player(Color playerColor);
    Player();
    /**
     * @brief getColor get the color of the player
     * @return the color
     */
    Color getColor();
    /**
     * @brief getMovesLeft get actual turn moves left
     */
    unsigned getMovesLeft();
    /**
     * @brief getPassLeft get actual turn pass left
     */
    unsigned getPassLeft();
    /**
     * @brief getWinner says if the player won
     * @return true if the player won the game
     */
    bool isWinner();
    /**
     * @brief useMove use a move for the player actual turn
     */
    void useMove();
    /**
     * @brief usePass use a pass for the player actual turn
     */
    void usePass();
    /**
     * @brief endTurn end actual turn for the player
     */
    void endTurn();
    /**
     * @brief setWinner set the player as the winner of the game
     */
    void setWinner();
};
#endif // PLAYER_H
