/*********************************************************************

**		Author: Connie McClung

**

**		Description: Raven.cpp
.
**		This is the Raven child class implementation file.


*********************************************************************/
#include "Raven.hpp"
#include <cstdlib>
#include <iostream>

/*********************************************************************

**

**		Description: Raven()
.
**		default constructor


*********************************************************************/
Raven::Raven()
{
	this->numDieAttack = 2;
	this->numDieSidesAttack = 4;
	this->numDieDefense = 2;
	this->numDieSidesDefense = 4;
	this->armor = 1;
	this->strength = 10;
	this->name = "VAMPIRE RAVEN";

	/*
	std::cout << "Being name is " << this->name << std::endl;
	std::cout << "Number of attack die is " << this->numDieAttack << std::endl;
	std::cout << "Number of attack die sides is " << this->numDieSidesAttack << std::endl;
	std::cout << "Number of defense die is " << this->numDieDefense << std::endl;
	std::cout << "Number of defense die sides is " << this->numDieSidesDefense << std::endl;
	std::cout << "Armor power is " << this->armor << std::endl;
	std::cout << "Strength is " << this->strength << std::endl;
	*/
}


/*********************************************************************

**

**		Description: defense()
.
**		defense function - calls parent 50% of time, and applies no damage 50% of time


*********************************************************************/

void Raven::defense(int otherAttack)
{
	
	int attackChance = rand() % 2+ 1; //1= chance no damage from attack, strength not changed.
	if (attackChance <2)
	{//apply damage as usual to strength
		//std::cout << "Special vampire raven charm not activated. Damage will be done." << std::endl;
		Being::defense(otherAttack);
	}
	else//don't apply damage
	{
		if (strength >0)
		{
			std::cout << "This vampire raven has special defense powers. NO damage will be done." << std::endl;
		}
	}
}


/*********************************************************************

**

**		Description: ~Raven()
.
**		destructor


*********************************************************************/
Raven::~Raven()
{

}