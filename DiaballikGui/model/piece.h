#ifndef PIECE_H
#define PIECE_H
#include "Color.h"
#include "Type.h"
/**
 * @brief The Piece class manage pieces
 */
class Piece
{
  private:
    /**
     * @brief _pieceColor the color of the piece
     */
    Color _pieceColor;
    /**
     * @brief _type the type of the piece
     */
    Type _type;

  public:
    /**
     * @brief Piece contruct a piece with a color and a type
     * @param color the color of the piece
     * @param type the type of the piece
     */
    Piece(Color color, Type type);
    /**
     * @brief getColor get the color of the piece
     * @return the color
     */
    Color getPieceColor();
    /**
     * @brief getType get the type of the piece
     * @return  the type
     */
    Type getType();
    /**
     * @brief setType set a new type for the piece
     * @param type new type of the piece
     */
    void setType(Type type);
};
#endif // PIECE_H
