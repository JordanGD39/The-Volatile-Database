#pragma once
#include <string>

class Product
{
public:
	enum WeaponType
	{
		SWORD,
		AXE,
		LANCE,
		BOW,
		MAGIC
	};

	Product(std::string aName, std::string aDescription, float aCost, WeaponType aTypeWeapon);
	~Product();

	std::string GetName();
	std::string GetDes();
	void SetName(std::string aName);
	float GetCost();	
	void SetCost(float g);	
	void SetDes(std::string d);
	void SetType(WeaponType aTypeWeapon);
private:

	std::string name = "";
	std::string description = "";
	float cost = 39;
	WeaponType typeWeapon;
};

