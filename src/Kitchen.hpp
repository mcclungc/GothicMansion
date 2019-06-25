/*********************************************************************

**		Author: Connie McClung

**		Date: 

**		Description: Kitchen.hpp
.
**		This is the Kitchen child class header file. It contains the member variables and member variable declarations
**		Derived from Room abstract class.

*********************************************************************/
#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include"Room.hpp"

class Kitchen : public Room
{

public:
	Kitchen();//default constructor
	~Kitchen();

	virtual char menu();//run the room menu
	virtual void searchRoom() override;//search the room for clues
	virtual void fightDanger(Being *opponent) override;//battle enemy for objects
	virtual void getDescription() override;//display description of the room

protected:
	//all member variables inherited from parent 


private:

	bool lightObtained;

};
#endif
