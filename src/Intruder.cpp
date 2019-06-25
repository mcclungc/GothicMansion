/*********************************************************************

**		Author: Connie McClung

**

**		Description: Intruder.cpp
.
**		This is the Shadowy Intruder child class implementation file.


*********************************************************************/
#include "Intruder.hpp"


/*********************************************************************

**

**		Description: Intruder()
.
**		default constructor


*********************************************************************/
Intruder::Intruder()
{
	this->numDieAttack = 2;
	this->numDieSidesAttack = 6;
	this->numDieDefense = 1;
	this->numDieSidesDefense = 4;
	this->armor = 0;
	this->strength = 6;
	this->name = "SHADOWY INTRUDER";

/*	std::cout << "Being name is " << this->name << std::endl;
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

**		Description: ~Intruder()
.
**		destructor


*********************************************************************/
Intruder::~Intruder()
{

}