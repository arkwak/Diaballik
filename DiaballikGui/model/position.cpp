#include "position.h"

Position::Position(unsigned row, unsigned column): _row(row),
    _column(column)
{

}

Position::Position()
{

}

unsigned Position::getRow()
{
    return _row;
}
unsigned Position::getColumn()
{
    return _column;
}
void Position::setRow(unsigned newRow)
{
    _row = newRow;
}
void Position::setColumn(unsigned newColumn)
{
    _column = newColumn;
}
