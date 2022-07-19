#ifndef SQUARE_H
#define SQUARE_H
#include "piece.h"
#include <optional>
#include <functional>
/**
 * @brief The Square class manages a square
 */
class Square
{
  private:
    /**
     * @brief _currentPiece the current Piece
     */
    std::optional<Piece> _currentPiece;
  public:
    /**
     * @brief Square construct an empty square
     */
    Square();
    /**
     * @brief getCurrentPiece get the current piece
     * @return the piece
     */
    Piece getCurrentPiece();
    /**
     * @brief put put a piece on the square
     * @param piece the new piece
     */
    void put(Piece piece);
    /**
     * @brief isMyColor check if the piece on the square has the same color as the player
     * @param color the color of the player
     * @return true if the color are the same, false if it is not
     */
    bool isMyOwn(Color color);
    /**
     * @brief getPieceType get the type of the piece
     * @return the type
     */
    Type getPieceType();
    /**
     * @brief isFree check if the square is empty
     * @return true if the square is empty, false if it is not
     */
    bool isFree();
    /**
     * @brief removePiece remove the piece of the square
     */
    void removePiece();
    /**
     * @brief getPieceColor get the color of the piece
     * @return the color
     */
    Color getPieceColor();
    /**
     * @brief setCurrentPieceType get the  type of the piece
     * @param type the type
     */
    void setCurrentPieceType(Type type);
};
#endif // SQUARE_H
