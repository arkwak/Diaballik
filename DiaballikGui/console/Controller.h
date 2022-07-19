#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../model/game.h"
#include "View.h"

class Controller
{
  private:
    /**
     * @brief _game
     */
    Game  _game;
    View  _view;
  public:/**
     * @brief Controller contruct the game and the view
     * @param game the game
     * @param view the view
     */
    Controller(Game game, View view);
    /**
    * @brief initialize initialize the whole game
    */
    void initialize();
    /**
     * @brief startGameBis start the game and manage all the commands from the user
     */
    void startGameBis();

};
#endif // CONTROLLER_H
