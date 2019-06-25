/*********************************************************************

**		Author: Connie McClung

**		Description: Armor.cpp
.
**		This is the Haunted Armor child class implementation file.


*********************************************************************/
#include "Armor.hpp"
#include <cstdlib>


/*********************************************************************

**

**		Description: Armor()
.
**		default constructor


*********************************************************************/
Armor::Armor()
{
	this->numDieAttack = 2;
	this->numDieSidesAttack = 6;
	this->numDieDefense = 1;
	this->numDieSidesDefense = 6;
	this->armor = 3;
	this->strength = 8;
	this->name = "HAUNTED SUIT OF ARMOR";

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

**		Description: attack()
.
**		attack function - calls parent attack function, but adds logic for score of 12


*********************************************************************/
int Armor::attack(Being *opponent)
{
	int attackScore = Being::attack(opponent);
	if (attackScore == 12) //if Armor rolls 12, reduce opponent's strength
	{
		std::cout << "Impermeable Armor weakens opponent!" << std::endl;
		opponent->setStrength((opponent->getStrength())/2);
	}
	return attackScore;
}

/*********************************************************************

**

**		Description: ~Armor()
.
**		destructor


*********************************************************************/

Armor::~Armor()
{

}
