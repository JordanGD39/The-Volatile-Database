#include "Product.h"

Product::Product(std::string aName, std::string aDescription, float aCost, WeaponType aTypeWeapon)
{
	name = aName;
	description = aDescription;
	cost = aCost;
	typeWeapon = aTypeWeapon;
}

Product::~Product()
{

}

std::string Product::GetName()
{
	return name;
}

void Product::SetName(std::string aName)
{
	name = aName;
}

float Product::GetCost()
{
	return cost;
}

void Product::SetCost(float g)
{
	cost = g;
}

void Product::SetDes(std::string d)
{
	description = d;
}

void Product::SetType(WeaponType aTypeWeapon)
{
	typeWeapon = aTypeWeapon;
}
