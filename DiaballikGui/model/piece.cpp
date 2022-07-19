#include "piece.h"

Piece::Piece(Color color, Type type): _pieceColor(color), _type(type)
{

}

Color Piece::getPieceColor()
{
    return _pieceColor;
}
Type Piece::getType()
{
    return _type;
}
void Piece::setType(Type type)
{
    _type = type;
}


