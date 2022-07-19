#include "game.h"
#include "Color.h"
#include "player.h"
#include "Type.h"
#include <vector>
#include "QDebug"

Game::Game(bool variante, unsigned size): _currentPlayer{Player(Color::BLUE)},
    _opponentPlayer{Player(Color::RED)}, _selectedPosition(std::nullopt),
    _board{Board(size)}

{
    _gameStatus = GENERATED;
    std::list<Move>
    _listMove;
    std::list<Position>
    _listPass;
    _size = size;
    _variant = variante;
    std::list<Direction> _directions;
    std::list<Direction> _passdirections;
}
void Game::initializeNewGame()
{
    for (unsigned i = 0; i < _size; i++)
    {
        if (!_variant)
        {
            if (i == _size / 2)
            {
                fillboard(i, Type::BILLE, false);
            }
            else
            {
                fillboard(i, Type::SUPPORT, false);
            }
        }
        else
        {
            if (i == _size / 2 )
            {
                fillboard(i, Type::BILLE, false);
            }
            else
            {
                if (i == 1 || i == _size - 2)
                {
                    fillboard(i, Type::SUPPORT, true);
                }
                else
                {
                    fillboard(i, Type::SUPPORT, false);
                }
            }
        }
    }
    _directions = {Direction(-1, 0, 1), Direction(-2, 0, 2), Direction(-1, 1, 2)
                   , Direction(0, 1, 1), Direction(0, 2, 2), Direction(1, 1, 2), Direction(1, 0, 1)
                   , Direction(2, 0, 2), Direction(1, -1, 2), Direction(0, -1, 1), Direction(0, -2, 2), Direction(-1, -1, 2)
                  };
    _passdirection = {Direction(-1, 0, 1), Direction(-1, 1, 1)
                      , Direction(0, 1, 1), Direction(1, 1, 1), Direction(1, 0, 1)
                      , Direction(1, -1, 1), Direction(0, -1, 1), Direction(-1, -1, 1)
                     };
    _gameStatus = INIT;
}

void Game::fillboard(unsigned column, Type pieceType, bool invert)
{
    if (!invert)
    {
        _board.putInSquare(Piece(Color::BLUE, pieceType), Position(0,
                           column));
        _board.putInSquare(Piece(Color::RED, pieceType), Position(_size - 1,
                           column));
    }
    else
    {
        _board.putInSquare(Piece(Color::BLUE, pieceType),
                           Position(_size - 1, column));
        _board.putInSquare(Piece(Color::RED, pieceType), Position(0, column));
    }
}
void Game::startGame()
{
    if (isOver())
    {
        std::logic_error("La partie est terminée");
    }
    _gameStatus = RUNNING;
}
bool Game::isOver()
{
    if (checkWinner() || checkAntiJeu())
    {
        _gameStatus = FINISHED;
        return true;
    }
    return false;
}
void Game::selectPosition(unsigned row,
                          unsigned column)
{
    if (!_board.isInside(Position(row, column)))
    {
        std::logic_error("The position is not inside the board");
    }
    if (_board.isFree(Position(row, column)))
    {
        std::logic_error("The position is empty");
    }
    if (!_board.isMyOwn(Position(row, column), _currentPlayer.getColor()))
    {
        std::logic_error("the piece at this position is not yours");
    }
    _selectedPosition = Position(row, column);
}
std::vector<std::vector<Square>> Game::getBoard()
{
    return   _board.getBoard();
}

bool Game::checkSupport()
{
    return _board.getSquare(
               _selectedPosition.value()).getCurrentPiece().getType() == SUPPORT;
}
bool Game::checkMovePositions()
{
    if (_selectedPosition != nullopt)
    {
        unsigned i = 0;
        Position selectedtemporary =
            *_selectedPosition;
        for (Direction dir : this->_directions)
        {
            Position endPosition =
                *_selectedPosition;
            endPosition.setRow(_selectedPosition->getRow() + dir.getRowIndex());
            endPosition.setColumn(_selectedPosition->getColumn() +
                                  dir.getColumnIndex());
            if (_currentPlayer.getMovesLeft() >= dir.getCost())
            {
                Move move(_board.getSquare(selectedtemporary).getCurrentPiece(),
                          selectedtemporary,
                          endPosition, i, dir.getCost());
                if (isPossibleToMove(
                            move))
                {
                    _listMove.push_back(move);
                    i++;
                }
            }
        }
        return _listMove.size() !=
               0;
    }
    return false;
}
bool Game::isPossibleToMove(Move
                            move)
{
    signed oneRow = 0;
    signed oneColumn = 0;
    signed twoRow = 0;
    signed twoColumn = 0;
    if (move.getMoveCost() == 2)
    {
        if (move.checkWestWest(move))
        {
            oneRow = -1;
            oneColumn = 0;
        }
        else if (move.checkNorthWest(move))
        {
            oneRow = -1;
            oneColumn = 0;
            twoRow = 0;
            twoColumn = 1;
        }
        else if (move.checkNorthNorth(move))
        {
            oneRow = 0;
            oneColumn = 1;
        }
        else if (move.checkNorthEast(move))
        {
            oneRow = 0;
            oneColumn = 1;
            twoRow = 1;
            twoColumn = 0;
        }
        else if (move.checkEastEast(move))
        {
            oneRow = 1;
            oneColumn = 0;
        }
        else if (move.checkSouthEast(move))
        {
            oneRow = 1;
            oneColumn = 0;
            twoRow = 0;
            twoColumn = -1;
        }
        else if (move.checkSouthSouth(move))
        {
            oneRow = 0;
            oneColumn = -1;
        }
        else if (move.checkSouthWest(move))
        {
            oneRow = 0;
            oneColumn = -1;
            twoRow = -1;
            twoColumn = 0;
        }
    }
    if (oneRow == 0 && oneColumn == 0 && twoRow == 0 && twoColumn == 0)
    {
        return (_board.CheckSquare(move.getEndPosition()) &&
                move.getEndPosition().getRow() >= 0 &&
                move.getEndPosition().getRow() <= _size - 1 &&
                move.getEndPosition().getColumn() >= 0 &&
                move.getEndPosition().getColumn() <= _size - 1);
    }
    else
    {
        if (twoRow == 0 && twoColumn == 0)
        {
            Position pos(Position(move.getStartPosition().getRow() + oneRow,
                                  move.getStartPosition().getColumn() + oneColumn));
            return ((_board.CheckSquare(pos) ||
                     _board.CheckSquareColor(pos, _currentPlayer.getColor())) &&
                    _board.CheckSquare(move.getEndPosition()) &&
                    move.getEndPosition().getRow() >= 0 &&
                    move.getEndPosition().getRow() <= _size - 1 &&
                    move.getEndPosition().getColumn() >= 0 &&
                    move.getEndPosition().getColumn() <= _size - 1);
        }
        else
        {
            Position pos(Position(move.getStartPosition().getRow() + oneRow,
                                  move.getStartPosition().getColumn() + oneColumn));
            Position pos2(Position(move.getStartPosition().getRow() + twoRow,
                                   move.getStartPosition().getColumn() + twoColumn));
            return ((_board.CheckSquare(pos) ||
                     _board.CheckSquare(pos2) ||
                     _board.CheckSquareColor(pos, _currentPlayer.getColor()) ||
                     _board.CheckSquareColor(pos, _currentPlayer.getColor())) &&
                    _board.CheckSquare(move.getEndPosition()) &&
                    move.getEndPosition().getRow() >= 0 &&
                    move.getEndPosition().getRow() <= _size - 1 &&
                    move.getEndPosition().getColumn() >= 0 &&
                    move.getEndPosition().getColumn() <= _size - 1);
        }
    }
    // return false;
}
std::vector<Move> Game::getValidMoves()
{
    return _listMove;
}
void Game::setIndexToMoves()
{
    unsigned i = 0;
    for (Move move : _listMove)
    {
        move.setIndex(i);

        i++;
    }
}
unsigned Game::getNumberOfMoves()
{
    return _listMove.size();
}
void Game::applyMove(Move
                     move)
{
    Position start = move.getStartPosition();
    Piece piece = move.getselectedPiece();
    Position end = move.getEndPosition();

    if (_board.getSquare(end).isFree())
    {
        _board.putInSquare(piece, end);
        _board.removeFromSquare(start);
        for (unsigned i = 0; i < move.getMoveCost(); i++)
        {
            _currentPlayer.useMove();
        }
    }
}
void Game::swapPlayer()
{
    Player oldCurrent = _currentPlayer;
    Player oldOpponent = _opponentPlayer;
    _currentPlayer = oldOpponent;
    _opponentPlayer = oldCurrent;
}
bool Game::hasMoves(Player
                    player)
{
    return player.getMovesLeft() != 0;
}
bool Game::checkWinner()
{
    if (checkAntiJeu())
    {
        return true;
    }
    else if (!checkAntiJeu())
    {
        for (unsigned i = 0; i < _size; i++)
        {
            if (_board.getBoard().at(0).at(i).isMyOwn(Color::RED) &&
                    (_board.getBoard().at(0).at(i).getPieceType() == Type::BILLE))
            {
                _currentPlayer.setWinner();
                return true;
            }
            else if (_board.getBoard().at(_size - 1).at(i).isMyOwn(Color::BLUE) &&
                     (_board.getBoard().at(_size - 1).at(i).getPieceType() == Type::BILLE))
            {
                _currentPlayer.setWinner();
                return true;
            }
        }
    }
    return false;
}
bool Game::checkGiveBall()
{
    if (_selectedPosition != nullopt)
    {
        unsigned i = 0;
        Position selectedtemporary = *_selectedPosition;
        for (Direction dir : _passdirection)
        {
            Position endPosition =
                *_selectedPosition;
            endPosition.setRow(_selectedPosition->getRow() + dir.getRowIndex());
            endPosition.setColumn(_selectedPosition->getColumn() +
                                  dir.getColumnIndex());
            while (_board.isInside(endPosition) && isPossibleToPass(endPosition))
            {
                if (_board.getSquare(endPosition).isMyOwn(_currentPlayer.getColor()))
                {
                    Move move(_board.getSquare(selectedtemporary).getCurrentPiece(),
                              selectedtemporary,
                              endPosition, i, dir.getCost());
                    _listPass.push_back(move);
                    i++;
                }
                endPosition.setRow(endPosition.getRow() + dir.getRowIndex());
                endPosition.setColumn(endPosition.getColumn() + dir.getColumnIndex());
            }
        }
        if (_listPass.size() != 0)
        {
            return true;
        }
    }
    return false;
}

Color Game::getWinner()
{
    return _currentPlayer.getColor();
}
void Game::giveBall(Move move)
{
    Position start = move.getStartPosition();
    Piece piece = move.getselectedPiece();
    Position end = move.getEndPosition();
    _board.putInSquare(piece,
                       end);
    _board.putInSquare(Piece(_currentPlayer.getColor(), Type::SUPPORT),
                       start);
    _currentPlayer.usePass();
}

bool Game::isPossibleToPass(Position position)
{
    return ((_board.getSquare(position).isMyOwn(_currentPlayer.getColor())
             || _board.getSquare(position).isFree()) &&
            _currentPlayer.getPassLeft() >= 1);
}
bool Game::checkAntiJeu()
{
    unsigned counter = 0;
    for (unsigned i = 0; i < _size - 1;
            i++)
    {
        for (unsigned j = 0; j < _size;
                j++)
        {
            if (_board.getBoard().at(i).at(j).isMyOwn(Color::BLUE) &&
                    _board.getBoard().at(i + 1).at(j).isMyOwn(Color::RED))
            {
                counter++;
            }
        }
    } if (counter >= 3)
    {
        if (_currentPlayer.getColor() ==
                Color::BLUE)
        {
            _currentPlayer.setWinner();
            return true;
        }
        else
        {
            _opponentPlayer.setWinner();
            return true;
        }
    }
    counter = 0;
    for (unsigned i = 1; i < _size;
            i++)
    {
        for (unsigned j = 1; j < _size;
                j++)
        {
            if (_board.getBoard().at(i).at(j).isMyOwn(Color::RED) &&
                    _board.getBoard().at(i - 1).at(j).isMyOwn(Color::BLUE))
            {
                counter++;
            }
        }
    } if (counter >= 3)
    {
        if (_currentPlayer.getColor() ==
                BLUE)
        {
            _currentPlayer.setWinner();
            return true;
        }
        else
        {
            _opponentPlayer.setWinner();
            return true;
        }
    }
    return false;
}
Player Game::getCurrent()
{
    return _currentPlayer;
}
Player Game::getOpponent()
{
    return _opponentPlayer;
}
void Game::endTurn()
{
    _currentPlayer.endTurn();
    swapPlayer();
    std::vector<Move> list;
    this->_listMove = list;
    this->_listPass = list;
    _selectedPosition = std::nullopt;
}
Piece Game::getSelected()
{
    Position selected = _selectedPosition.value();
    return _board.getPiece(selected);
}
bool Game::isSelectedPiece()
{
    return _selectedPosition != std::nullopt;
}
unsigned Game::getSize()
{
    return _size;
}
bool Game::isValidSelect(int row, int column)
{
    if (_board.isInside(Position(row, column)) &&
            _board.getBoard().at(row).at(column).isMyOwn(
                _currentPlayer.getColor()))
    {
        if (_board.getBoard().at(row).at(column).getPieceType() == Type::BILLE
                && _currentPlayer.getPassLeft() >= 1)
        {
            return true;
        }
        else if (_board.getBoard().at(row).at(column).getPieceType() ==
                 Type::SUPPORT && _currentPlayer.getMovesLeft() >= 1)
        {
            return true;
        }
    }
    return false;
}
std::optional<Position> Game::getSelectedPosition()
{
    if (_selectedPosition != std::nullopt)
    {
        return _selectedPosition;
    }
    return std::nullopt;
}
Board Game::getObjectBoard()
{
    return _board;
}
Type Game::getSelectedPieceType()
{
    return _board.getBoard().at(_selectedPosition->getRow()).at(
               _selectedPosition->getColumn()).getPieceType();
}
void Game::emptyListMoves()
{
    std::vector<Move> _new;
    _listMove = _new;
    _listPass = _new;
}
std::vector<Move> Game::getListValidPass()
{
    return _listPass;
}

void Game::cleanValidMoves()
{
    std::vector<Move> list;
    this->_listMove = list;
}

void Game::cleanvalidPass()
{
    std::vector<Move> list;
    this->_listPass = list;
}

void Game::cleanselected()
{
    _selectedPosition.reset();
}
