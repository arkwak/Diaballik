#include "Controller.h"
#include "View.h"
#include "../model/game.h"
#include <string>
#include <regex>
#include<iostream>
#include <list>


Controller::Controller(Game game, View view): _game(game), _view(view)
{

}
void Controller::initialize()
{
    _game.initializeNewGame();
    _game.startGame();
}

void Controller::startGameBis()
{
    _game.startGame();
    _view.displayHelp();
    _view.displayBoard(_game.getBoard());
    _view.displayStatus(_game.getCurrent(),
                        _game.getCurrent().getMovesLeft(), _game.getCurrent().getPassLeft());
    unsigned int cost = 0;
    bool showGrid = false;
    int messageNumber = 0;
    while (!_game.isOver())
    {
        if (showGrid)
        {
            _view.displayHelp();
            _view.displayBoard(_game.getBoard());
            _view.displayStatus(_game.getCurrent(),
                                _game.getCurrent().getMovesLeft(), _game.getCurrent().getPassLeft());
            switch (messageNumber)
            {
                case 1:
                    _game.setIndexToMoves();
                    _view.displayMoves(_game.getValidMoves());
                    break;
                case 2:
                    _view.displayHasMove(_game.getCurrent(), _game.getSelectedPieceType(),
                                         cost);
                    break;
                case 3:
                    _view.displaySkip(_game.getCurrent());
                    break;
                case 4:
                    _view.displayMoves(_game.getListValidPass());
                    break;
            }
            messageNumber = 0;
            showGrid = false;
        }
        std::vector<string> command = _view.displayAskCommand();
        cin.clear();
        if (command.size() != 0)
        {
            if (command.at(0) == "select" || command.at(0) == "Select" ||
                    command.at(0) == "SELECT")
            {
                if (command.size() == 3 && command.at(1).length() == 1 &&
                        command.at(2).length() == 1)
                {
                    try
                    {
                        if (_game.isValidSelect(std::stoi(command.at(1)),
                                                std::stoi(command.at(2))))
                        {
                            unsigned row = std::stoi(command.at(1));
                            unsigned column = std::stoi(command.at(2));
                            _game.selectPosition(row, column);
                            _view.displaySelected(_game.getSelected(),
                                                  _game.getSelectedPosition()->getRow(),
                                                  _game.getSelectedPosition()->getColumn());
                            _game.emptyListMoves();
                        }
                        else
                        {
                            if (_game.getObjectBoard().isInside(Position(std::stoi(command.at(1)),
                                                                std::stoi(command.at(2)))))
                            {
                                cout << "BAD POSITION : none of your pieces found at this position - PRESS ENTER TO CONTINUE";
                            }
                            else
                            {
                                cout << "BAD POSITION : Your row and your column don't match with board - PRESS ENTER TO CONTINUE";
                            }
                        }
                    }
                    catch (const exception & ex)
                    {
                        cout << "BAD POSITION : Your row and your column don't match with board - PRESS ENTER TO CONTINUE";
                    }
                }
                else
                {
                    cout << "BAD SYNTAX : To select a piece you only need a valid row and column - PRESS ENTER TO CONTINUE";
                    command.clear();
                }
            }
            else if (command.at(0) == "moves" || command.at(0) == "Moves" ||
                     command.at(0) == "MOVES")
            {
                if (_game.isSelectedPiece())
                {
                    if (_game.getSelectedPieceType() == Type::SUPPORT)
                    {
                        if (_game.checkMovePositions())
                        {
                            _game.setIndexToMoves();
                            showGrid = true;
                            messageNumber = 1;
                        }
                        else
                        {
                            cout << "BLOCKED : Your piece is blocked and cant move anymore - PRESS ENTER TO CONTINUE";
                        }
                    }
                    else
                    {
                        if (_game.checkGiveBall())
                        {
                            showGrid = true;
                            messageNumber = 4;
                        }
                        else
                        {
                            cout << "BLOCKED : You cant pass to nobody - PRESS ENTER TO CONTINUE";
                        }
                    }
                }
                else
                {
                    cout << "BAD COMMAND : Please select a piece before see his moves - PRESS ENTER TO CONTINUE";
                    command.clear();
                }
            }
            else if (command.at(0) == "apply" || command.at(0) == "Apply" ||
                     command.at(0) == "APPLY")
            {
                if (_game.isSelectedPiece())
                {
                    if (_game.getSelectedPieceType() == Type::SUPPORT)
                    {
                        try
                        {
                            unsigned i = std::stoi(command.at(1));
                            if (_game.getValidMoves().size() > i && i >= 0)
                            {
                                if (_game.getValidMoves().size() != 0)
                                {
                                    if (_game.getCurrent().getMovesLeft() != 0)
                                    {
                                        cost = _game.getValidMoves().at(i).getMoveCost();
                                        _game.applyMove(_game.getValidMoves().at(i));
                                        messageNumber = 2;
                                        showGrid = true;
                                    }
                                    else
                                    {
                                        cout << "BAD COMMAND : You have no moves left - PRESS ENTER TO CONTINUE";
                                    }
                                }
                                else
                                {
                                    cout << "BAD COMMAND : You need to enter moves command before apply - PRESS ENTER TO CONTINUE";
                                }
                            }
                            else
                            {
                                cout << "BAD SYNTAX : your move number is not valid  - PRESS ENTER TO CONTINUE";
                            }
                        }
                        catch (const exception & ex)
                        {
                            cout << "BAD SYNTAX : your move number is not valid  - PRESS ENTER TO CONTINUE";
                        }
                    }
                    else
                    {
                        if (_game.getCurrent().getPassLeft() != 0)
                        {
                            try
                            {
                                unsigned i = std::stoi(command.at(1));
                                if (_game.getListValidPass().size() > i && i >= 0)
                                {
                                    if (_game.getListValidPass().size() != 0)
                                    {
                                        cout << "on effectue une passe" << endl;
                                        cost = _game.getListValidPass().at(i).getMoveCost();
                                        _game.giveBall(_game.getListValidPass().at(i));
                                        messageNumber = 2;
                                        showGrid = true;
                                    }
                                    else
                                    {
                                        cout << "BAD COMMAND : You need to enter moves command before apply - PRESS ENTER TO CONTINUE";
                                    }
                                }
                                else
                                {
                                    cout << "BAD SYNTAX : your move number is not valid  - PRESS ENTER TO CONTINUE";
                                }
                            }
                            catch (const exception & ex)
                            {
                                cout << "BAD SYNTAX : your pass number is not valid  - PRESS ENTER TO CONTINUE";
                            }
                        }
                        else
                        {
                            cout << "BAD COMMAND : You have no passes left - PRESS ENTER TO CONTINUE";
                        }
                    }
                }
                else
                {
                    cout << "BAD COMMAND : you need to select a piece before apply - PRESS ENTER TO CONTINUE";
                }

            }
            else if (command.at(0) == "skip" || command.at(0) == "Skip" ||
                     command.at(0) == "SKIP")
            {
                _game.endTurn();
                messageNumber = 3;
                showGrid = true;

            }
            else if (command.at(0) == "quit" || command.at(0) == "Quit" ||
                     command.at(0) == "QUIT")
            {
                exit(0);
            }
            else
            {
                cout << "NOT REGOGNIZED : This command does not match - PRESS ENTER TO CONTINUE";
                command.clear();
            }
        }
        else
        {
            cout << "NO COMMAND : please enter a command to do a action - PRESS ENTER TO CONTINUE";
            command.clear();
        }
    }
    _view.displayIsOver(_game.getWinner());
}



