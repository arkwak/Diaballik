#include "square.h"
#include "piece.h"
# include <iostream>
using namespace std;

Square::Square(): _currentPiece(std::nullopt)
{

}
bool Square::isMyOwn(Color color)
{
    if (_currentPiece!=std::nullopt) {
        return _currentPiece->getPieceColor() == color;
    }else{
        return false;
    }
}
Type Square::getPieceType()
{
    return _currentPiece->getType();
}
Piece Square::getCurrentPiece()
{
    return _currentPiece.value();
}
void Square::put(Piece piece)
{
    _currentPiece = piece;
}
bool Square::isFree()
{
    return this->_currentPiece==nullopt;
}
void Square::removePiece()
{
    if (!_currentPiece)
    {
        throw std::logic_error("Il n'y a pas de pieces sur la case");
    }
    this->_currentPiece=nullopt;
}
Color Square::getPieceColor() {
    return _currentPiece->getPieceColor();
}
void Square::setCurrentPieceType(Type type) {
    _currentPiece->setType(type);
}

