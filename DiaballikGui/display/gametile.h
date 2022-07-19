#ifndef GAMETILE_H
#define GAMETILE_H
#include <QObject>
#include <QPushButton>
class gameTile : public QPushButton
{
    Q_OBJECT
public:
    /**
     * @brief gameTile game tile constructor
     * @param row row position
     * @param column column position
     * @param parent gameWindow
     */
    gameTile(int row, int column, QWidget * parent = nullptr);
    /**
     * @brief getrow getter for row integer
     * @return
     */
    int getrow();
    /**
     * @brief getcolumn getter for column integer
     * @return
     */
    int getcolumn();
private:
    /**
     * @brief _row row position
     */
    int _row;
    /**
     * @brief _column column position
     */
    int _column;
};
#endif // GAMETILE_H
