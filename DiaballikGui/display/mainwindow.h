#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "gamewindow.h"
#include <string>
QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    /**
     * @brief MainWindow constructor of QMainWindow
     * @param parent Q_Object
     */
    MainWindow(QWidget * parent = nullptr);
    /**
     * destructor of QMainWindow
     */
    ~MainWindow();
    /**
     * @brief getBlueName getter for blue player name
     * @return Blue player name
     */
    QString getBlueName();
    /**
     * @brief getRedName getter for red player name
     * @return red player name
     */
    QString getRedName();
    /**
     * @brief getVariant get variant choice
     * @return true if variant is selected
     */
    bool getVariant();
  private slots:
    /**
     * @brief on_pushButton_clicked launch the game window
     */
    void on_pushButton_clicked();
    /**
     * @brief on_actionQuit_triggered kill the QMainWindow process
     */
    void on_actionQuit_triggered();
  private:
    /**
     * @brief ui application interface
     */
    Ui::MainWindow * ui;
    /**
     * @brief gameWindow game Qapplication
     */
    GameWindow * gameWindow;
    /**
     * @brief _size board size
     */
    int _size;
    /**
     * @brief variant variant choice
     */
    bool variant;
};
#endif // MAINWINDOW_H
