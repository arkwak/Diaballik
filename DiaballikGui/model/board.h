#ifndef BOARD_H
#define BOARD_H
#include "square.h"
#include <stdlib.h>
#include "vector"
#include "position.h"
/**
 * @brief The Board class
 * This class contains the board
 */
class Board
{
  private:
    /**
     * @brief _size the size of the board
     */
    unsigned _size;
    /**
     * @brief _board the board of Squares
     */
    std::vector<std::vector<Square>>_board;
    /**
     * @brief variant design if the board is variant version or not
     */
    bool variant;
  public:
    /**
     * @brief Board Construct an empty Board
     * @param size the Size of the board
     */
    Board(unsigned
          size);
    /**
     * @brief CheckSquare Check if the square at the position extsts
     * @param position The position we want to check
     * @return True if the Square exists, False if it is not
     */
    bool CheckSquare(Position
                     position);
    /**
     * @brief getSquare Get the Square at the Position we want
     * @param position the position we want to check
     * @return  The Square
     */
    Square getSquare(Position position);
    /**
     * @brief putInSquare Put the piece given a the position we want
     * @param piece the piece we want to put
     * @param position the position
     */
    void putInSquare(Piece piece,
                     Position position);
    /**
     * @brief removeFromSquare remove the piece at a position
     * @param position a position
     */
    void removeFromSquare(Position
                          position);
    /**
     * @brief getSize the size of the board
     */
    unsigned getSize();
    /**
     * @brief setSize set the size of the board
     * @param size the new size
     */
    unsigned setSize(unsigned size);
    /**
     * @brief getBoard get the board
     * @return the board
     */
    std::vector<std::vector<Square>> getBoard();
    /**
     * @brief isInside check if the position is inside the board
     * @param position the position we want to check
     * @return true if the position is inside, false if it is not
     */
    bool isInside(Position position);
    /**
     * @brief isFree check is there is a piece at a position
     * @param position the position we want to check
     * @return  true if there is no pieces at the position, false if there is one
     */
    bool isFree(Position position);
    /**
     * @brief isMyOwn check if the piece at a position has the same color than the player
     * @param position the position we want to check
     * @param color the color of the player
     * @return true if they have the same color than the player
     */
    bool isMyOwn(Position position, Color color);
    /**
     * @brief getPiece get the piece at a position
     * @param position the position we want
     * @return the piece at the position
     */
    Piece getPiece(Position position);
    /**
     * @brief CheckSquareColor check inf the piece on the square has the good color
     * @param position the position on the square
     * @param color the color
     * @return  true if the colors are the same, false if they has not
     */
    bool CheckSquareColor(Position position, Color color);
};
#endif // BOARD_H
