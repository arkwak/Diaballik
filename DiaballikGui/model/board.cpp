#include "board.h"
#include "square.h"
#include <stdexcept>
# include <iostream>
using namespace std;

Board::Board(unsigned size): _size(size)
{
    for (unsigned i = 0; i < _size; i++)
    {
        std::vector<Square> x;
        for (unsigned j = 0; j < _size; j++)
        {
            x.push_back(Square());
        }
        _board.push_back(x);
    }
}

std::vector<std::vector<Square>> Board::getBoard()
{
    return _board;
}

bool Board::CheckSquare(Position position)
{
    if (position.getRow()>=0 && position.getRow()<=_size-1 && position.getColumn()>=0 && position.getColumn()<=_size-1) {
        return _board.at(position.getRow()).at(position.getColumn()).isFree();
    }
    return false;
}
bool Board::CheckSquareColor(Position position,Color color)
{
    if (position.getRow()>=0 && position.getRow()<=_size-1 && position.getColumn()>=0 && position.getColumn()<=_size-1) {
        return _board.at(position.getRow()).at(position.getColumn()).getPieceColor()==color;
    }
    return false;
}

Square Board::getSquare(Position position)
{
    if (isInside(position) == false)
    {
        std::logic_error("la position n'appatient pas au tableau");
    }
    return _board.at(position.getRow()).at(position.getColumn());
}


void Board::putInSquare(Piece piece, Position position)
{
    if (isInside(position) == false)
    {
        std::logic_error("la position n'appatient pas au tableau");
    }
    _board.at(position.getRow()).at(position.getColumn()).put(
        piece);
}

void Board::removeFromSquare(Position position)
{
    _board.at(position.getRow()).at(position.getColumn()).removePiece();

}

unsigned Board::getSize()
{
    return _size;
}
bool Board::isInside(Position position)
{
    return !((position.getRow() > _size-1 || position.getRow() < 0) ||
             (position.getColumn() > _size-1 || position.getColumn() < 0));
}

bool Board::isFree(Position position)
{
    if (isInside(position) == false)
    {
        std::logic_error("la position n'appatient pas au tableau");
    }
    return _board.at(position.getRow()).at(
               position.getColumn()).isFree();

}
bool Board::isMyOwn(Position position, Color color)
{
    if (isInside(position) == false)
    {
        std::logic_error("la position n'appatient pas au tableau");
    }
    return getPiece(position).getPieceColor() == color;
}
Piece Board::getPiece(Position position)
{
    if (isInside(position) == false)
    {
        std::logic_error("la position n'appatient pas au tableau");
    }
    return _board.at(position.getRow()).at(
               position.getColumn()).getCurrentPiece();
}



