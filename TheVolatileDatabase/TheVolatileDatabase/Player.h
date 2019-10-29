#pragma once
#include "Product.h"
#include <list>

class Player
{
public:
	Player(float money);
	~Player();

	float GetGold();
	void SetGold(float i);

	std::list<Product> GetBought();
	void SetBought(std::list<Product> cart);

private:
	float gold = 0;
	std::list<Product> bought;
};

