#include "View.h"
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include <math.h>
#include "../model/piece.h"

View::View()
{

}
void View::displayIntro()
{
    cout << "|==============================================================================|"
         << endl;
    cout << "| ________  .___   _____ __________    _____  .____    .____    .___ ____  __. |"
         << endl;
    cout << "| \\______ \\ |   | /  _  \\\\______   \\  /  _  \\ |    |   |    |   |   |    |/ _| |"
         << endl;
    cout << "|  |    |  \\|   |/  /_\\  \\|    |  _/ /  /_\\  \\|    |   |    |   |   |      <   |"
         << endl;
    cout << "|  |    `   \\   /    |    \\    |   \\/    |    \\    |___|    |___|   |    |  \\  |"
         << endl;
    cout << "| /_______  /___\\____|__  /______  /\\____|__  /_______ \\_______ \\___|____|__ \\ |"
         << endl;
    cout << "|         \\/            \\/       \\/         \\/        \\/       \\/           \\/ |"
         << endl;
    cout << "|==============================================================================|"
         << endl;
    cout << "|================================================================== version 1.0|"
         << endl;
    cout << "|==============================================================================|"
         << endl;
}

bool View::askVariant()
{
    int choice = 0;
    bool valid = false;
    cout << "select the version you want to play! (1 or 2)" <<
         endl;
    cout << "\f 1.original" << endl;
    cout << "\f 2.variant" << endl;
    cout << "> ";
    while (!valid)
    {
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please select a version between 1 or 2 !" <<
                 endl;
            cout <<  "> ";
        }
        if (choice != 1 && choice != 2)
        {
            cout << "please select a version between 1 or 2 !" <<
                 endl;
            cout << "> ";
        }
        else
        {
            valid = true;
        }
    }
    switch (choice)
    {
        case 1:
            return false;
        case 2:
            return true;

    }
    return false;
}
unsigned View::asksize()
{
    int choice = 0;
    bool valid = false;
    cout << "select the board size you want! (5, 7 or 9)" <<
         endl;
    cout << "> ";
    while (!valid)
    {
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please select a size between 5, 7 or 9 !" <<
                 endl;
            cout << "> ";
        }
        if (choice != 5 && choice != 7 && choice != 9)
        {
            cout << "please select a size between 5, 7 or 9 !" <<
                 endl;
            cout << "> ";
        }
        else
        {
            valid = true;
        }
    }
    return choice;
}
void View::displayQuit()
{
    cout << "Au revoir" << endl;
    cout << "" << endl;
}
void View::displayHelp()
{
    cout << "|==============================================================================|"
         << endl;
    cout << "|  Commands :                  Fonction:                                       |"
         << endl;
    cout << "|  quit                        : exit the game                                 |"
         << endl;
    cout << "|  select row column           : select a piece in the gaming board            |"
         << endl;
    cout << "|  moves                       : show all possibles moves for a selected piece |"
         << endl;
    cout << "|  apply number                : apply a move for the selected piece           |"
         << endl;
    cout << "|  skip                        : skip your turn                                |"
         << endl;
    cout << "|==============================================================================|"
         << endl;
}
void View::displayStatus(Player player, int moves, int passes)
{
    string color;
    if (player.getColor() == Color::RED)
    {
        color = "RED ";
    }
    else
    {
        color = "BLUE";
    }
    cout << "|==============================================================================|"
         << endl;
    cout << "|  Game Status:                Values:                                         |"
         << endl;
    cout << "|  PlayerTurn                  : " << color <<
         "                                          |" << endl;
    cout << "|  moves left                  : " << moves <<
         "                                             |" << endl;
    cout << "|  pass left                   : " << passes <<
         "                                             |" << endl;
    cout << "|==============================================================================|"
         << endl;
}
std::vector<string> View::displayAskCommand()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Write your command : ";
    string command;
    getline(cin, command);
    std::vector<string> finalCommand;
    std::istringstream iss(command);
    for (std::string s; iss >> s;)
    {
        finalCommand.push_back(s);
    }
    return finalCommand;
}
void View::displayCurrentPlayer(Player player)
{
    Player player1(BLUE);
    if (player.getColor() == Color::RED)
    {
        cout << "C'est a votre tour joueur ROUGE" << endl;
        cout << "" << endl;
    }
    else if (player.getColor() == Color::BLUE)
    {
        cout << "C'est a votre tour joueur BLEU" << endl;
        cout << "" << endl;
    }
}
void View::displaySelected(Piece piece, int row, int column)
{
    if (piece.getPieceColor() == Color::RED)
    {
        switch (piece.getType())
        {
            case Type::BILLE :
                cout << "You selected a RED WITH BALL at ROW: " << row << " COLUMN: "
                     << column << " - PRESS ENTER TO CONTINUE";
                break;
            case Type::SUPPORT :
                cout << "You selected a RED SUPPORT at at ROW: " << row << " COLUMN: "
                     << column << " - PRESS ENTER TO CONTINUE";
                break;
            case Type::NOTYPE:
                break;
        }
    }
    else
    {
        switch (piece.getType())
        {
            case Type::BILLE :
                cout << "You selected a BLUE WITH BALL at ROW: " << row << " COLUMN: "
                     << column << " - PRESS ENTER TO CONTINUE";
                break;
            case Type::SUPPORT :
                cout << "You selected a BLUE SUPPORT at ROW: " << row << " COLUMN: "
                     << column << " - PRESS ENTER TO CONTINUE";
                break;
            case Type::NOTYPE:
                break;
        }
    }
}
void View::displayIsOver(Player winner)
{
    if (winner.getColor() == Color::RED)
    {
        cout << "|==============================================================================|"
             << endl;
        cout << "|                         RED PLAYER WON THE GAME                              |"
             << endl;
        cout << "|==============================================================================|"
             << endl;
    }
    else
    {
        cout << "|==============================================================================|"
             << endl;
        cout << "|                         BLUE PLAYER WON THE GAME                             |"
             << endl;
        cout << "|==============================================================================|"
             << endl;
    }
}
void View::displayBoardSepa()
{
    for (int i = 0; i < 49; i++)
    {
        cout << "=" << endl;
    }
    cout << "" << endl;
}
void View::displayBoardHead(std::vector<std::vector<Square>> squares)
{
    cout << " col# ||  " << endl;
    for (size_t i = 0; i < squares.front().size(); i++)
    {
        cout << " | " << "0" << i << " | " << endl;
    }
    cout << "" << endl;
}
void View::displayBoard(std::vector<std::vector<Square>> squares)
{
    for (unsigned i = 0; i < squares.size() + 2; i++)
    {
        for (unsigned j = 0; j < squares.size() + 2; j++)
        {
            if ((i == 0 && j == 0) || (i == squares.size() + 1 &&
                                       j == squares.size() + 1) || (i == 0 && j == squares.size() + 1) ||
                    (i == squares.size() + 1 && j == 0))
            {
                cout << "   ";
            }
            else if (i == 0 || i == squares.size() + 1)
            {
                cout << " " << j - 1 << " ";
            }
            else
            {
                if (j == 0 || j == squares.size() + 1)
                {
                    cout << " " << i - 1 << " ";
                }
                else if (squares.at(i - 1).at(j - 1).isFree())
                {
                    cout << " . ";
                }
                else if (squares.at(i - 1).at(j - 1).getPieceType() == Type::BILLE)
                {
                    switch (squares.at(i - 1).at(j -
                                                 1).getCurrentPiece().getPieceColor())
                    {
                        case RED:
                            cout << "_R_";
                            break;
                        case BLUE:
                            cout << "_B_";
                            break;
                        case NONE:
                            break;
                    }
                }
                else
                {
                    switch (squares.at(i - 1).at(j - 1).getPieceColor())
                    {
                        case RED:
                            cout << " R ";
                            break;
                        case BLUE:
                            cout << " B ";
                            break;
                        case NONE:
                            break;
                    }
                }

            }
        }
        cout << "" << endl;
    }



}
void View::displayMoves(std::vector<Move> moves)
{
    cout << "|  Choice:                     Action:                                         |"
         << endl;
    for (Move move : moves)
    {
        if (move.getselectedPiece().getPieceColor() == Color::RED)
        {
            switch (move.getselectedPiece().getType())
            {
                case Type::BILLE :
                    //pas trouvé comment traduire indexOf en c++
                    cout << "|  " << move.getIndex() <<
                         "                           : pass to ROW: " +
                         std::to_string(move.getEndPosition().getRow()) << " COLUMN: " <<
                         std::to_string(move.getEndPosition().getColumn()) <<
                         "                      |" << endl;
                    break;
                case Type::SUPPORT :
                    cout << "|  " << move.getIndex() <<
                         "                           : move to ROW: " +
                         std::to_string(move.getEndPosition().getRow()) << " COLUMN: " <<
                         std::to_string(move.getEndPosition().getColumn()) <<
                         "                      |" << endl;
                    break;
                case Type::NOTYPE:
                    break;
            }
        }
        else
        {
            switch (move.getselectedPiece().getType())
            {
                case Type::BILLE :

                    cout << "|  " << move.getIndex() <<
                         "                           : pass to ROW: " +
                         std::to_string(move.getEndPosition().getRow()) << " COLUMN: " <<
                         std::to_string(move.getEndPosition().getColumn()) <<
                         "                      |" << endl;
                    break;
                case Type::SUPPORT :
                    cout << "|  " << move.getIndex() <<
                         "                           : move to ROW: " +
                         std::to_string(move.getEndPosition().getRow()) << " COLUMN: " <<
                         std::to_string(move.getEndPosition().getColumn()) <<
                         "                      |" << endl;
                    break;
                case Type::NOTYPE:
                    break;
            }
        }
    }
    cout << "|==============================================================================|"
         << endl;
    cout << "You can choose between " << moves.size() <<
         " moves for selected Piece - PRESS ENTER TO CONTINUE";
}

void View::displaySkip(Player player)
{
    if (player.getColor() == RED)
    {
        cout << "BLUE player skiped his turn - PRESS ENTER TO CONTINUE";
    }
    else
    {
        cout << "RED player skiped his turn - PRESS ENTER TO CONTINUE";
    }
}

void View::displayHasMove(Player player, Type type, unsigned cost)
{
    if (player.getColor() == RED)
    {
        if (type == BILLE)
        {
            cout << "RED player paid " << cost <<
                 "to pass the ball - PRESS ENTER TO CONTINUE";
        }
        else
        {
            cout << "RED player paid " << cost <<
                 "to move into the board - PRESS ENTER TO CONTINUE";
        }
    }
    else
    {
        if (type == BILLE)
        {
            cout << "BLUE player paid " << cost <<
                 " to pass the ball - PRESS ENTER TO CONTINUE";
        }
        else
        {
            cout << "BLUE player paid " << cost <<
                 " to move into the board - PRESS ENTER TO CONTINUE";
        }
    }
}


