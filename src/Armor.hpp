/*********************************************************************

**		
**		Description: Armor.hpp
.
**		This is the Haunted Armor child class header file. It contains the member variables and member variable declarations
**		One of the enemy's heroine must battle to obtain an object. Derived from Being abstract class.

*********************************************************************/
#ifndef ARMOR_HPP
#define ARMOR_HPP

#include"Being.hpp"

class Armor : public Being
{

public:
	Armor();//default constructor
	int attack(Being *opponent) override;//overrides parent function
	virtual ~Armor();

protected:
	//all variables inherited from parent


private:



};
#endif
