#ifndef VIEW_H
#define VIEW_H
#include "../model/move.h"
#include "../model/player.h"
#include "../model/board.h"
#include <string>
#include <vector>
/**
 * @brief The View class This class manages the view in the console
 */
class View
{
  private:
    string startline = "| ";

  public:
    /**
     * @brief View Construct a view
     */
    View();
    /**
     * @brief askVariant ask user if he want to play variant version or not
     */
    bool askVariant();
    /**
     * @brief asksize ask user the board size he want
     */
    unsigned asksize();
    /**
     * @brief displayIntro display a message to introduce the game
     */
    void displayIntro();
    /**
      * @brief displayQuit display a message when the user quits
      */
    void displayQuit();
    /**
     * @brief displayHelp display the commands that the user can use
     */
    void displayHelp();
    /**
     * @brief displayStatus show information about the current turn
     */
    void displayStatus(Player player, int moves, int passes);
    /**
     * @brief displayBoard display the board on the console
     */
    void displayBoard(std::vector<std::vector<Square>> squares);
    /**
     * @brief displayAskCommand ask to the user to enter a command
     * @return the command given
     */
    std::vector<string> displayAskCommand();
    /**
     * @brief displayCurrentPlayer display the current Player
     */
    void displayCurrentPlayer(Player player);
    /**
     * @brief displayIsOver display the winner
     */
    void displayIsOver(Player winner);
    /**
     * @brief displayBoardSepa display the separation in the board
     */
    void displayBoardSepa();
    /**
     * @brief displayBoardHead display the header in the board
     * @param
     */
    void displayBoardHead(std::vector<std::vector<Square>> squares);
    /**
     * @brief displaySelected display the selected piece
     * @param piece the selected piece
     */
    void displaySelected(Piece piece, int row, int column);
    /**
     * @brief displayMoves display the list of moves
     * @param moves the list of moves
     */
    void displayMoves(std::vector<Move> moves);
    /**
     * @brief displaySkip display the skip
     * @param player the player who skips
     */
    void displaySkip(Player player);
    /**
     * @brief displayHasMove display the moves
     * @param player the current player
     * @param type the type of the piece
     * @param cost the cost of the move
     */
    void displayHasMove(Player player, Type type, unsigned cost);
};

#endif // VIEW_H

