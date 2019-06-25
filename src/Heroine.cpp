/*********************************************************************

**		Author: Connie McClung


**		Description: Heroine.cpp
.
**		This is the Heroine child class implementation file.


*********************************************************************/
#include "Heroine.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

/*********************************************************************

**

**		Description: Heroine()
.
**		default constructor


*********************************************************************/
Heroine::Heroine()
{
	this->name = "JANE";
	this->numDieAttack = 3;
	this->numDieSidesAttack = 6;
	this->numDieDefense = 2;
	this->numDieSidesDefense = 6;
	this->armor = 2;
	this->strength = 12;
	isFirstLife = true;
	
	//echo variables to screen for testing
		/*
	std::cout << "Being name is "<< this->name << std::endl;
	std::cout << "Number of attack die is " << this->numDieAttack << std::endl;
	std::cout << "Number of attack die sides is " << this->numDieSidesAttack << std::endl;
	std::cout << "Number of defense die is " << this->numDieDefense << std::endl;
	std::cout << "Number of defense die sides is " << this->numDieSidesDefense << std::endl;
	std::cout << "Armor power is " << this->armor << std::endl;
	std::cout << "Strength is " << this->strength << std::endl;
	std::cout << "First life is " << isFirstLife << std::endl;
	*/
}

/*********************************************************************

**

**		Description: attack()
.
**		attack function - calls parent attack function, but adds logic for score of 12


*********************************************************************/
int Heroine::attack(Being *opponent)
{
	int attackScore = Being::attack(opponent);
	if (attackScore >= 14) //if Heroine rolls >=14, set opponent strength to zero
	{
		std::cout << this->name<< " has knocked her enemy unconscious with her reticule." <<  std::endl;
		opponent->setStrength(0);
	}
	//std::cout << "Attack score is " << attackScore << std::endl;
	return attackScore;

}


/*********************************************************************

**

**		Description: defense()
.
**		defense function - virtual, can be overridden by child class


*********************************************************************/

void Heroine::defense(int otherAttack)
{
	Being::defense(otherAttack);
	if ((this->strength <= 0)) //if dies first time, revive and set strength to 20
	{
		std::cout << "Oops, "<<this->name<<" has died!" << std::endl;
		if (isFirstLife)
		{
			std::cout << "False alarm, she just fainted for a moment because her corset is too tight..." << std::endl;
			strength = 20;
			isFirstLife = false;
		}

	}

}


/*********************************************************************

**

**		Description: ~Heroine()
.
**		destructor


*********************************************************************/
Heroine::~Heroine()
{

}
/*********************************************************************

**

**		Description: getIsFirstLife()
.
**		


*********************************************************************/
bool Heroine::getIsFirstLife()
{
	return isFirstLife;
}
