#include "move.h"
#include <optional>
#include <functional>

Move::Move (Piece piece, Position start,
            Position end, unsigned index, unsigned cost): _selectedPiece(piece), _startPosition(start),
    _endPosition(end), _index(index), _cost(cost)
{
}

Piece Move::getselectedPiece()
{
    return _selectedPiece;
}
Position Move::getStartPosition()
{
    return  _startPosition;
}
Position Move::getEndPosition()
{
    return _endPosition;
}
unsigned Move::getIndex()
{
    return _index;
}
void Move::setIndex(unsigned value)
{
    this->_index=value;
}
unsigned Move::getMoveCost()
{
    return _cost;
}
bool Move::checkWestWest(Move move)
{
    return move.getEndPosition().getRow() ==
           move.getStartPosition().getRow()
           - 2 && move.getEndPosition().getColumn() ==
           move.getStartPosition().getColumn();
}
bool Move::checkNorthNorth(Move move)
{
    return move.getEndPosition().getRow() ==
           move.getStartPosition().getRow() &&
           move.getEndPosition().getColumn() ==
           move.getStartPosition().getColumn() + 2;
}
bool Move::checkNorthEast(Move move)
{
    return move.getEndPosition().getRow() ==
           move.getStartPosition().getRow() + 1 &&
           move.getEndPosition().getColumn() ==
           move.getStartPosition().getColumn() + 1;
}
bool Move::checkNorthWest(Move move)
{
    return move.getEndPosition().getRow() ==
           move.getStartPosition().getRow() - 1 &&
           move.getEndPosition().getColumn() ==
           move.getStartPosition().getColumn() + 1 ;
}
bool Move::checkEastEast(Move move)
{
    return move.getEndPosition().getRow() ==
           move.getStartPosition().getRow() + 2 &&
           move.getEndPosition().getColumn() ==
           move.getStartPosition().getColumn();
}
bool Move::checkSouthEast(Move move)
{
    return move.getEndPosition().getRow() ==
           move.getStartPosition().getRow() + 1 &&
           move.getEndPosition().getColumn() ==
           move.getStartPosition().getColumn() - 1;
}
bool Move::checkSouthSouth(Move move)
{
    return move.getEndPosition().getRow() ==
           move.getStartPosition().getRow() &&
           move.getEndPosition().getColumn() ==
           move.getStartPosition().getColumn() - 2;
}
bool Move::checkSouthWest(Move move)
{
    return move.getEndPosition().getRow() ==
           move.getStartPosition().getRow() - 1 &&
           move.getEndPosition().getColumn() ==
           move.getStartPosition().getColumn() - 1;
}
