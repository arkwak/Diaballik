#ifndef GAME_H
#define GAME_H
#include "move.h"
#include "player.h"
#include "position.h"
#include "Status.h"
#include "board.h"
#include <list>
#include <iostream>
using namespace std;
/**
 * @brief The Game class controls all the rules of the game
 */
class Game
{
  private:
    /**
     * @brief currentPlayer the player wich actually plays
     */
    Player  _currentPlayer;
    /**
     * @brief opponentPlayer the player opponent
     */
    Player  _opponentPlayer;
    /**
     * @brief _selectedPosition the position selected by the user
     */
    std::optional<Position> _selectedPosition;
    /**
     * @brief _gameStatus the actual status of the game
     */
    Status _gameStatus;

    /**
     * @brief _listMove the list of the possible moves
     */
    std::vector<Move> _listMove;
    /**
     * @brief _listPass list of positions where actual player can pass
     */
    std::vector<Move> _listPass;
    /**
     * @brief board the board
     */
    Board  _board;
    /**
     * @brief _directions list of all possible directions from Direction class
     */
    std::list<Direction> _directions;
    std::list<Direction> _passdirection;
    /**
     * @brief size game board size
     */
    unsigned _size;
    /**
     * @brief variant
     */
    bool _variant;

  public:
    /**
     * @brief Game contructs a game
     */
    Game(bool variante, unsigned size);
    /**
     * @brief initializeNewGame initalize the game with the pieces on the board
     */
    void initializeNewGame();
    /**
     * @brief fillboard fill the board with a piece
     * @param column piece column
     * @param pieceType pieceType
     * @param invert variant or not
     */
    void fillboard(unsigned column, Type pieceType, bool invert);
    /**
     * @brief startGame starts the game
     */
    void startGame();
    /**
     * @brief selectPosition select a new position to play from here
     * @param row selected position row
     * @param column selected potition column
     */
    void selectPosition(unsigned row, unsigned column);
    /**
     * @brief checkSupport check if the current selected position have a support on it or no
     * @return true if the selected position have a support inside
     */
    bool checkSupport();
    /**
     * @brief checkPositions check if the position is legal
     * @return true if the position is legal, false if it is not
     */
    bool checkMovePositions();
    /**
     * @brief isPossibleToMove check if the move is possible
     * @param move the move we want to do
     * @return true if the Move is possible, false if it is not
     */
    bool isPossibleToMove(Move move);
    /**
     * @brief getValidMoves get all the valid moves
     * @return the moves
     */
    std::vector<Move> getValidMoves();
    /**
     * @brief getNumberOfMoves get total number of possible moves for the curent selected piece
     */
    unsigned getNumberOfMoves();
    /**
     * @brief applyMove apply the move we want to do
     * @param move the move we want to do
     */
    void applyMove(Move move);
    /**
     * @brief swapPlayer swap the 2 players
     */
    void swapPlayer();
    /**
     * @brief hasMoves check if the player has a move
     * @param player the player we want to check
     * @return True if the player has move(s), false if he has not
     */
    bool hasMoves(Player player);
    /**
     * @brief checkWinner check if a player won
     * @return true if a player won, false if it is not
     */
    bool checkWinner();/**
     * @brief giveBall Give the ball to a piece at the position we want
     * @param position the position where we want to give the ball
     */
    void giveBall(Move move);
    /**
     * @brief checkGiveBall check if we can give the ball
     * @return true if we can, false if we can't
     */
    bool checkGiveBall();
    /**
     * @brief isPossibleToPass check if a pass is possible for a specific position
     * @param position
     * @return
     */
    bool isPossibleToPass(Position position);
    /**
     * @brief getWinner get the winner of the game
     * @return the winner
     */
    Color getWinner();
    /**
     * @brief checkAntiJeu check is there is a antiJeu
     * @return true if there is a antiJeu, false if it is not
     */
    bool checkAntiJeu();
    /**
     * @brief getCurrent get the color of the current player
     * @return the color of the player
     */
    Player getCurrent();
    /**
     * @brief getOpponent get the color of the opponent player
     * @return the coloor of the player
     */
    Player getOpponent();
    /**
     * @brief isOver check if the game is over
     * @return true if the game is over, false if it is not
     */
    bool isOver();
    /**
     * @brief endTurn end the currentplayer turn
     */
    void endTurn();
    /**
     * @brief getBoard get the board
     * @return  the board
     */
    std::vector<std::vector<Square>> getBoard();
    /**
     * @brief isValidSelect check if tile selected is correct
     * @param row tile row
     * @param column tile column
     * @return true if the select is correct
     */
    bool isValidSelect(int row, int column);
    /**
     * @brief getSelected get the selected piece
     * @return the selected piece
     */
    Piece getSelected();
    /**
     * @brief isSelectedPiece inform if a piece is currently selected
     * @return if a piece is selected
     */
    bool isSelectedPiece();
    /**
     * @brief getSize get the size
     */
    unsigned getSize();
    /**
     * @brief getSelectedPosition get the selected position
     * @return  the selected position
     */
    std::optional<Position> getSelectedPosition();
    /**
     * @brief getObjectBoard get the object on the board
     * @return the board
     */
    Board getObjectBoard();
    /**
     * @brief setIndexToMoves set the indox to the moves
     */
    void setIndexToMoves();
    /**
     * @brief getSelectedPieceType get the type of the selected piece
     * @return the type of the selected piece
     */
    Type getSelectedPieceType();
    /**
     * @brief emptyListMoves remove the list of moves
     */
    void emptyListMoves();
    /**
     * @brief getListValidPass get the list of the valid pass
     * @return  the moves of pass
     */
    std::vector<Move> getListValidPass();
    /**
     * @brief checkLineBlocked check if the line is blocked
     * @return true if it is blocked, false if it is not
     */
    bool checkLineBlocked();
    /**
     * @brief cleanValidMoves clean list of moves
     */
    void cleanValidMoves();
    /**
     * @brief cleanvalidPass clean list of pases
     */
    void cleanvalidPass();
    /**
     * @brief cleanselected clean selected piece
     */
    void cleanselected();
    /**
     * @brief checkNorthWest check if the player move to the north west
     * @param move the move
     * @return  true if the move is to the north west, false if it is not
     */
    bool checkNorthWest(Move move);

    /**
     * @brief checkNorthNorth check if the player move to the north 2 times
     * @param move the move
     * @return  true if the move is to the north, false if it is not
     */
    bool checkNorthNorth(Move move);

    /**
     * @brief checkNorthEast check if the player move to the north east
     * @param move the move
     * @return  true if the move is to the north east, false if it is not
     */
    bool checkNorthEast(Move move);

    /**
     * @brief checkWestWest check if the player move to the west 2 times
     * @param move the move
     * @return  true if the move is to the west 2 times, false if it is not
     */
    bool checkWestWest(Move move);
    /**
     * @brief checkEastEast check if the player move to the  east 2 times
     * @param move the move
     * @return  true if the move is to the  east, false if it is not
     */
    bool checkEastEast(Move move);
    /**
     * @brief checkSouthEast check if the player move to the south east
     * @param move the move
     * @return  true if the move is to the south east, false if it is not
     */
    bool checkSouthEast(Move move);
    /**
     * @brief checkSouthSouth check if the player move to the south 2 times
     * @param move the move
     * @return  true if the move is to the south , false if it is not
     */
    bool checkSouthSouth(Move move);
    /**
     * @brief checkSouthWest check if the player move to the south west
     * @param move the move
     * @return  true if the move is to the south west, false if it is not
     */
    bool checkSouthWest(Move move);
};
#endif // GAME_H
