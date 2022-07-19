#ifndef DIRECTION_H
#define DIRECTION_H
/**
 * @brief The Direction enum lists all the direction possible for a move
 */
class Direction
{
  private:
    /**
     * @brief rowindex a row
     */
    signed rowindex;
    /**
     * @brief columnindex a column
     */
    signed columnindex;
    /**
     * @brief _cost the cost of the move
     */
    unsigned _cost;
  public:
    /**
     * @brief Direction construct a direction
     * @param row the row
     * @param column the column
     * @param cost the cost
     */
    Direction(signed row, signed column, unsigned cost);
    /**
     * @brief getRowIndex get the row
     */
    signed getRowIndex();
    /**
     * @brief getColumnIndex get the column
     */
    signed getColumnIndex();
    /**
     * @brief getCost get the cost
     */
    unsigned getCost();
};
#endif // DIRECTION_H
