/*********************************************************************

**		Author: Connie McClung

**		Date: 

**		Description: Being.cpp
.
**		This is the Being abstract base class implementation file.


*********************************************************************/
#include"Being.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

/*********************************************************************

**

**		Description: Being()
.
**		default constructor


*********************************************************************/
Being::Being()
{
	name = "NONAME";
	numDieAttack = 0;
	numDieSidesAttack = 0;
	numDieDefense = 0;
	numDieSidesDefense = 0;
	armor = 0;
	strength = 0;
	isDead = false;
}

/*********************************************************************

**

**		Description: Being(std::string nameIn, int numDieAttackIn, int numDieSidesAttackIn, int numDieDefenseIn, int numDieSidesDefenseIn, int armorIn, int strengthIn)
.
**		constructor from inputs


*********************************************************************/

Being::Being (std::string nameIn, int numDieAttackIn, int numDieSidesAttackIn, int numDieDefenseIn, int numDieSidesDefenseIn, int armorIn, int strengthIn)
{
	name = nameIn;
	numDieAttack = numDieAttackIn;
	numDieSidesAttack = numDieSidesAttackIn;
	numDieDefense = numDieDefenseIn;
	numDieSidesDefense = numDieSidesDefenseIn;
	armor = armorIn;
	strength = strengthIn;
}


/*********************************************************************

**

**		Description: attack()
.
**		attack function - virtual, can be overridden by child class


*********************************************************************/
int Being::attack(Being *opponent)
{
	int attackScore = 0; //roll score accumulator
	int attackRoll; //score for each roll

	for (int i = 0; i < numDieAttack; i++)
	{
		attackRoll = rand() % numDieSidesAttack + 1;
		//std::cout << "Attack Roll score for Die " << i+1 <<" is "<< attackRoll << std::endl;
		attackScore = attackScore + attackRoll;
	}
	std::cout << "Attack score is " << attackScore << std::endl;
	return attackScore;

}

/*********************************************************************

**

**		Description: defense()
.
**		defense function - virtual, can be overridden by child class


*********************************************************************/

void Being::defense(int otherAttack)
{
	int initialStrength = strength;
	int defenseRollScore = 0; //roll score accumulator
	int defenseRoll;
	int damage;
	for (int j = 0; j < numDieDefense; j++)
	{
		defenseRoll = rand() % numDieSidesDefense + 1;
		//std::cout << "Defense Roll score for Die " << j + 1 << " is " << defenseRoll << std::endl;
		defenseRollScore = defenseRollScore + defenseRoll;
	}
	//std::cout << "Defense roll is " << defenseRollScore << std::endl;
	//calculate damage
	damage = otherAttack - defenseRollScore - armor;
	//apply damage;
	if (initialStrength == 0) //creature has already been defeated by opponent, game over
	{
		strength = initialStrength; //don't change strength
	}
	else //otherwise, apply damage and adjust strength
	{
		strength = strength - damage;
	}

	//but don't let strength increase after an attack
	if (strength > initialStrength)
	{
		strength = initialStrength;
	}

}


/*********************************************************************

**

**		Description: getStrength()
.
**		returns strength


*********************************************************************/
int Being::getStrength()
{
	return strength;
}


/*********************************************************************

**

**		Description: setStrength(int strengthIn)
.
**		setter function strength


*********************************************************************/
void Being::setStrength(int strengthIn)
{
	strength = strengthIn;
}


/*********************************************************************

**

**		Description: getName()
.
**		returns strength


*********************************************************************/
std::string Being::getName()
{
	return name;
}


/*********************************************************************

**

**		Description: setName(std::string nameIn)
.
**		setter function name


*********************************************************************/
void Being::setName(std::string nameIn)
{
	name = nameIn;
}


/*********************************************************************

**

**		Description: ~Being()
.
**		pure virtual destructor


*********************************************************************/
Being::~Being()
{

}