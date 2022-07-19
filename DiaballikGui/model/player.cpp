#include "player.h"

Player::Player(Color playerColor): _playerColor(playerColor)
{
    _movesLeft = 2;
    _passLeft = 1;
    winner = false;

}
Player::Player()
{

}
Color Player::getColor()
{
    return _playerColor;
}
unsigned Player::getMovesLeft()
{
    return _movesLeft;
}
unsigned Player::getPassLeft()
{
    return _passLeft;
}
void Player::useMove()
{
    _movesLeft = _movesLeft - 1;
}
void Player::usePass()
{
    _passLeft = _passLeft - 1;
}
void Player::endTurn()
{
    _movesLeft = 2;
    _passLeft = 1;
}
void Player::setWinner()
{
    winner = true;
}
bool Player::isWinner()
{
    return winner;
}
