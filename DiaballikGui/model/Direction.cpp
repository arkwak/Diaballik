#include "board.h"
#include "Direction.h"
#include <stdexcept>
# include <iostream>
using namespace std;

Direction::Direction(signed row, signed column, unsigned cost): rowindex(row),columnindex(column), _cost(cost)
{

}
signed Direction::getRowIndex() {
    return rowindex;
}
signed Direction::getColumnIndex() {
    return columnindex;
}
unsigned Direction::getCost() {
    return _cost;
}
