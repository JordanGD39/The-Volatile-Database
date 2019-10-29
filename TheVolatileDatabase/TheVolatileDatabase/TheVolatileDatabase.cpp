// TheVolatileDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Product.h"
#include "Player.h"

void StartGame(float g, std::list<Product> b, std::list<Product> newProducts)
{
	int i;

	Product product("Leek", "An ordinary leek", 39, Product::SWORD);
	Product product2("Guitar", "An old guitar", 50, Product::AXE);
	Product product3("Mic Stand", "An normal mic stand", 45, Product::LANCE);
	Product product4("Drum stick", "An drum stick", 20, Product::BOW);
	Product product5("Elfire", "An magic book", 200, Product::MAGIC);

	Player player(g);
	player.SetBought(b);

	while (true)
	{
		std::cout << "You have " << player.GetGold() << " gold to spend\n";

		std::cout << "You're choices are:\n" << "-1: Suprise me\n" << "0: List of what you bought\n" << "1: " << product.GetName() << " | " << product.GetCost() << " gold\n" << "2: " << product2.GetName() << " | " << product2.GetCost() << " gold\n" << "3: " << product3.GetName() << " | " << product3.GetCost() << " gold\n" << "4: " << product4.GetName() << " | " << product4.GetCost() << " gold\n" << "5: " << product5.GetName() << " | " << product5.GetCost() << " gold\n" << "6: Make a new item\n";
		int index = 7;

		for (Product pr : newProducts)
		{
			std::cout << index << ": " << pr.GetName() << " | " << pr.GetCost() << " gold\n";
			index++;
		}

		int randNum = 0;

		if (!newProducts.empty())
		{
			randNum = rand() % index + 1;
			if (randNum == 6)
			{
				randNum = 7;
			}
		}
		else
		{
			randNum = rand() % 5 + 1;
		}

		std::cin >> i;

		std::string prName = "";
		std::string des = "";
		float prCost = 0;
		Product::WeaponType waah = Product::SWORD;
		int inputWeapon = 0;
		Product productNew(prName, des, prCost, waah);

		index = 7;
		bool foundProduct = false;

		std::cout << "\n";

		if (i == -1)
		{
			i = randNum;
		}

		switch (i)
		{
		case 0:
			for (Product pr : b)
			{
				std::cout << pr.GetName() << "\n";
			}
			break;
		case 1:
			if (player.GetGold() >= product.GetCost())
			{
				b.push_back(product);
				player.SetGold(player.GetGold() - product.GetCost());
				std::cout << "You bought the " << product.GetName() << "\n" << "You have: " << player.GetGold() << " left\n";
			}
			else
			{
				std::cout << "You don't have enough money\n";
			}
			break;
		case 2:
			if (player.GetGold() >= product2.GetCost())
			{
				b.push_back(product2);
				player.SetGold(player.GetGold() - product2.GetCost());
				std::cout << "You bought the " << product2.GetName() << "\n" << "You have: " << player.GetGold() << " left\n";
			}
			else
			{
				std::cout << "You don't have enough money\n";
			}
			break;
		case 3:
			if (player.GetGold() >= product3.GetCost())
			{
				b.push_back(product3);
				player.SetGold(player.GetGold() - product3.GetCost());
				std::cout << "You bought the " << product3.GetName() << "\n" << "You have: " << player.GetGold() << " left\n";
			}
			else
			{
				std::cout << "You don't have enough money\n";
			}
			break;
		case 4:
			if (player.GetGold() >= product4.GetCost())
			{
				b.push_back(product4);
				player.SetGold(player.GetGold() - product4.GetCost());
				std::cout << "You bought the " << product4.GetName() << "\n" << "You have: " << player.GetGold() << " left\n";
			}
			else
			{
				std::cout << "You don't have enough\n";
			}
			break;
		case 5:
			if (player.GetGold() >= product5.GetCost())
			{
				b.push_back(product5);
				player.SetGold(player.GetGold() - product5.GetCost());
				std::cout << "You bought the " << product5.GetName() << "\n" << "You have: " << player.GetGold() << " left\n";
			}
			else
			{
				std::cout << "You don't have enough money\n";
			}
			break;
		case 6:
			std::cout << "Type name for the product\n";
			std::cin >> prName;
			std::cout << "Type the description for the product\n";
			std::cin >> des;
			std::cout << "Type the cost for the product\n";
			std::cin >> prCost;
			std::cout << "Type the type of weapon:\n 1: Sword\n 2: Axe\n 3: Lance\n 4: Bow\n 5: Magic book\n";
			std::cin >> inputWeapon;
			switch (inputWeapon)
			{
			case 1:
				waah = Product::SWORD;
				break;
			case 2:
				waah = Product::AXE;
				break;
			case 3:
				waah = Product::LANCE;
				break;
			case 4:
				waah = Product::BOW;
				break;
			case 5:
				waah = Product::MAGIC;
				break;
			}

			productNew.SetName(prName);
			productNew.SetDes(des);
			productNew.SetCost(prCost);
			productNew.SetType(waah);

			newProducts.push_back(productNew);

			break;
		default:

			for (Product pr : newProducts)
			{
				if (index == i)
				{
					b.push_back(pr);
					player.SetGold(player.GetGold() - pr.GetCost());
					std::cout << "You bought the " << pr.GetName() << "\n" << "You have: " << player.GetGold() << " left\n";
					foundProduct = true;
					break;
				}

				index++;
			}

			if (!foundProduct)
			{
				std::cout << "That's not a valid product\n";
			}			
			break;
		}
		std::cout << "\n";
	}
}

int main()
{
	std::list<Product> a;
	StartGame(390, a, a);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
