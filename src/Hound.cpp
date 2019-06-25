/*********************************************************************

**		Author: Connie McClung

**

**		Description: Hound.cpp
.
**		This is the Hound child class implementation file.


*********************************************************************/
#include "Hound.hpp"


/*********************************************************************

**

**		Description: Hound()
.
**		default constructor


*********************************************************************/
Hound::Hound()
{
	this->numDieAttack = 2;
	this->numDieSidesAttack = 6;
	this->numDieDefense = 2;
	this->numDieSidesDefense = 6;
	this->armor = 0;
	this->strength = 8;
	this->name = "DEVIL HOUND";
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

**		Description: ~Hound()
.
**		destructor


*********************************************************************/
Hound::~Hound()
{

}