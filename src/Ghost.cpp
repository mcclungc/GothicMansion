/*********************************************************************

**		Author: Connie McClung

**

**		Description: Ghost.cpp
.
**		This is the Ghostly Lady child class implemntation file.


*********************************************************************/
#include "Ghost.hpp"
#include <string>


/*********************************************************************

**

**		Description: Ghost()
.
**		default constructor


*********************************************************************/
Ghost::Ghost()
{
	this->numDieAttack = 2;
	this->numDieSidesAttack = 6;
	this->numDieDefense = 3;
	this->numDieSidesDefense = 4;
	this->armor = 1;
	this->strength = 10;
	this->name = "GHOSTLY LADY";

	/*std::cout << "Being name is " << this->name << std::endl;
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
**		defense function - calls parent function, then adds defense die update logic


*********************************************************************/

void Ghost::defense(int otherAttack)
{
	Being::defense(otherAttack);
	//update number of defense die if needed
	int defenseStrength = strength - (strength % 4);
	switch (defenseStrength)
	{
	case 8:
	{
		numDieDefense = 2;
		std::cout << std::endl;
		//std::cout << "After this round, defending being " << name << " has " << numDieDefense << " defense die." << std::endl;
		break;
	}
	case 4:
	{
		numDieDefense = 1;
		std::cout << std::endl;
		//std::cout << "After this round, defending creature has " << numDieDefense << " defense die." << std::endl;
		std::cout << name << " is growing weak." << std::endl;
		break;
	}
	case 0:
	{
		numDieDefense = 0;
		std::cout << std::endl;
		//std::cout << "After this round, defending creature has " << numDieDefense << " defense die." << std::endl;
		std::cout << name << " has no more defenses." << std::endl;
		break;
	}
	}

}


/*********************************************************************

**

**		Description: ~Ghost()
.
**		destructor


*********************************************************************/
Ghost::~Ghost()
{

}