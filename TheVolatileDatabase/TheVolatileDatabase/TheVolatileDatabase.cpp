// TheVolatileDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//These scripts are made by Jordan Pignato GD2B

#include <iostream>
#include "Product.h"
#include "Player.h"

void StartGame() 
{
	int i;

	std::list<Product> bought;
	std::list<Product> newProducts;
	std::list<Product> oldProducts;

	oldProducts.push_back(Product("Leek", "An ordinary leek", 39, Product::SWORD));
	oldProducts.push_back(Product("Guitar", "An old guitar", 50, Product::AXE));
	oldProducts.push_back(Product("Mic Stand", "An normal mic stand", 45, Product::LANCE));
	oldProducts.push_back(Product("Drum stick", "An drum stick", 20, Product::BOW));
	oldProducts.push_back(Product("Elfire", "An magic book", 200, Product::MAGIC));

	Player player(390);
	player.SetBought(bought);

	while (true)
	{
		std::cout << "You have " << player.GetGold() << " gold to spend\n";

		std::cout << "You're choices are:\n" << "-1: Suprise me\n" << "0: List of what you bought\n";

		int index = 1;

		for (Product pr : oldProducts)
		{
			std::cout << index << ": " << pr.GetName() << " | "<< pr.GetDes() << " | " << pr.GetCost() << " gold\n";
			index++;
		}

		std::cout << "6: Make a new item\n";

		index = 7;

		for (Product pr : newProducts)
		{
			std::cout << index << ": " << pr.GetName() << " | " << pr.GetDes() << " | " << pr.GetCost() << " gold\n";
			index++;
		}

		int randNum = 0;

		index -= 1;

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
		Product::WeaponType weaponType = Product::SWORD;
		int inputWeapon = 0;
		Product productNew(prName, des, prCost, weaponType);

		index = 1;
		bool foundProduct = false;

		std::cout << "\n";

		if (i == -1)
		{
			i = randNum;
		}

		switch (i)
		{
		case 0:
			for (Product pr : bought)
			{
				std::cout << pr.GetName() << "\n";
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
				weaponType = Product::SWORD;
				break;
			case 2:
				weaponType = Product::AXE;
				break;
			case 3:
				weaponType = Product::LANCE;
				break;
			case 4:
				weaponType = Product::BOW;
				break;
			case 5:
				weaponType = Product::MAGIC;
				break;
			}

			productNew.SetName(prName);
			productNew.SetDes(des);
			productNew.SetCost(prCost);
			productNew.SetType(weaponType);

			newProducts.push_back(productNew);

			break;
		default:

			for (Product pr : oldProducts)
			{
				if (index == i)
				{
					bought.push_back(pr);
					player.SetGold(player.GetGold() - pr.GetCost());
					std::cout << "You bought the " << pr.GetName() << "\n" << "You have: " << player.GetGold() << " left\n";
					foundProduct = true;
					break;
				}

				index++;
			}

			index = 7;

			for (Product pr : newProducts)
			{
				if (index == i)
				{
					bought.push_back(pr);
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
	StartGame();
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
