#include "Player.h"

Player::Player(float money)
{
	gold = money;
}

Player::~Player()
{

}

float Player::GetGold()
{
	return gold;
}

void Player::SetGold(float i)
{
	gold = i;
}

std::list<Product> Player::GetBought()
{
	return bought;
}

void Player::SetBought(std::list<Product> cart)
{
	bought = cart;
}
