/*********************************************************************

**		Author: Connie McClung

**		Date:

**		Description: MasterSuite.hpp
.
**		This is the MasterSuite child class header file. It contains the member variables and member variable declarations
**		Derived from Room abstract class.

*********************************************************************/
#ifndef MASTER_SUITE_HPP
#define MASTER_SUITE_HPP

#include"Room.hpp"

class MasterSuite : public Room
{

public:

	MasterSuite();//default constructor
	~MasterSuite();
	
	virtual char menu()override; //run the room menu       
	virtual void searchRoom();//search the room for clues
	virtual void fightDanger(Being *opponent) override;//battle enemy for objects
	virtual void getDescription() override;//display description of the room

protected:
	//all member variables inherited from parent 


private:



};
#endif
