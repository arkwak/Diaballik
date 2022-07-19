#ifndef POSITION_H
#define POSITION_H
#include "Direction.h"
/**
 * @brief The Position class manage the positions
 */
class Position
{
  private:
    /**
     * @brief _row a row
     */
    unsigned _row;
    /**
     * @brief _column a column
     */
    unsigned _column;
  public:
    /**
     * @brief Position construct a position with a row and a column
     * @param row the row
     * @param column the column
     */
    Position(unsigned row, unsigned column);
    Position();
    /**
     * @brief getRow get the row
     */
    unsigned getRow();
    /**
     * @brief getColumn get the column
     */
    unsigned getColumn();
    /**
     * @brief setRow change current position row
     * @param row the current selected position row
     */
    void setRow(unsigned newRow);
    /**
     * @brief setColumn change current position column
     * @param newColumn the current selected position column
     */
    void setColumn(unsigned newColumn);
    /**
     * @brief nextPosition gives the position in a given direction
     * @param direction the direction
     * @return the position
     */
    Position nextPosition(Direction direction);
};
#endif // POSITION_H
