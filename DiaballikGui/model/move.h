#ifndef MOVE_H
#define MOVE_H
#include "piece.h"
#include "position.h"
#include <optional>
#include <functional>
/**
 * @brief The Move class manage the movements
 */
class Move
{
  private:
    /**
     * @brief _selectedPiece the piece selected by the user
     */
    Piece _selectedPiece;
    /**
     * @brief _startPosition the position before the move
     */
    Position _startPosition;
    /**
     * @brief _endPosition the position after the move
     */
    Position _endPosition;
    /**
     * @brief _index index of a move
     */
    unsigned _index;
    /**
     * @brief _cost the cost
     */
    unsigned _cost;
  public:
    /**
     * @brief Move the constructor a a move
     * @param piece the piece we want to move
     * @param start the position before the move
     * @param end the position after the move
     */
    Move (Piece piece, Position start, Position end, unsigned index,
          unsigned cost);
    Move ();
    /**
     * @brief getselectedPiece get the piece selected by the user
     * @return the piece
     */
    Piece getselectedPiece();
    /**
     * @brief getStartPosition get the position before the move
     * @return the position
     */
    Position getStartPosition();
    /**
     * @brief getEndPosition get the position after the move
     * @return the position
     */
    Position getEndPosition();
    /**
     * @brief setIndex set the index
     * @param number the new index
     */
    void setIndex(unsigned number);
    /**
     * @brief getIndex get the index
     */
    unsigned getIndex();
    /**
     * @brief getMoveCost get the cost for a move
     */
    unsigned getMoveCost();
    /**
     * @brief checkWestWest check if choosed move is RightRight
     * @param move current move choosed
     * @return true if its RightRight
     */
    bool checkWestWest(Move move);
    /**
     * @brief checkWestWest check if choosed move is UpUp
     * @param move current move choosed
     * @return true if its UpUp
     */
    bool checkNorthNorth(Move move);
    /**
     * @brief checkWestWest check if choosed move is UpRight
     * @param move current move choosed
     * @return true if its UpRight
     */
    bool checkNorthEast(Move move);
    /**
     * @brief checkWestWest check if choosed move is UpLeft
     * @param move current move choosed
     * @return true if its UpLeft
     */
    bool checkNorthWest(Move move);
    /**
     * @brief checkWestWest check if choosed move is UpRight
     * @param move current move choosed
     * @return true if its UpRight
     */
    bool checkEastEast(Move move);
    /**
     * @brief checkWestWest check if choosed move is DownRight
     * @param move current move choosed
     * @return true if its DownRight
     */
    bool checkSouthEast(Move move);
    /**
     * @brief checkWestWest check if choosed move is DownDown
     * @param move current move choosed
     * @return true if its DownDown
     */
    bool checkSouthSouth(Move move);
    /**
     * @brief checkWestWest check if choosed move is DownLeft
     * @param move current move choosed
     * @return true if its DownLeft
     */
    bool checkSouthWest(Move move);
};
#endif // MOVE_H
