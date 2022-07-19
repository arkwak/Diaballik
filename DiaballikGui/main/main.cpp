#include "display/mainwindow.h"
#include "model/game.h"
#include <list>
#include <iostream>
#include <QApplication>
#include "../console/Controller.h"
#include "../console/View.h"

/**
 * @brief qMain main application for visual display
 * @param argc arguments
 * @param argv arguments
 * @return ending code value
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
/**
 * @brief qMain main application for console display
 * @param argc arguments
 * @param argv arguments
 * @return ending code value
 */
//int main()
//{
//    View view;
//    view.displayIntro();
//    bool variant;
//    unsigned size;
//    variant = view.askVariant();
//    size = view.asksize();
//    Game game(variant, size);
//    Controller controller(game, view);
//    controller.initialize();
//    controller.startGameBis();
//    controller.startGame();
//}

