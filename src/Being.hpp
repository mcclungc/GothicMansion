/*********************************************************************

**		Author: Connie McClung

**		Date: 

**		Description: Being.hpp
.
**		This is the Being abstract base class header file. It contains the member variables and member variable declarations
**

*********************************************************************/
#ifndef BEING_HPP
#define BEING_HPP
#include <iostream>
#include <string>

//Being base class definition
class Being
{

public:
	Being();//default constructor
	//constructor that takes passed value for sides
	Being(std::string nameIn, int numDieAttackIn, int numDieSidesAttackIn, int numDieDefenseIn, int numDieSidesDefenseIn, int armorIn, int strengthIn);
	int virtual attack(Being *opponent);// virtual function can be overridden by child class
	void virtual defense(int otherAttack);// virtual function can be overridden by child class
	virtual ~Being() = 0; //destructor to make this an abstract class
	
	//getter functions
	std::string getName();
	int getStrength();//will allow tracking of score and game over status
	
	//setter functions
	void setStrength(int strengthIn); //allows possible direct change of strength
	void setName(std::string nameIn);
	
	

protected:
	//variables for battle
	std::string name;
	int numDieAttack;
	int numDieSidesAttack;
	int numDieDefense;
	int numDieSidesDefense;
	int armor;
	int strength;
	bool isDead;

private:



};
#endif
