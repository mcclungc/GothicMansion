/*********************************************************************

**		Author: Connie McClung

**		Date:

**		Description: Attic.hpp
.
**		This is the Attic child class header file. It contains the member variables and member variable declarations
**		One of the spaces based on Room abstract class.

*********************************************************************/
#ifndef ATTIC_HPP
#define ATTIC_HPP

#include"Room.hpp"

class Attic : public Room
{

public:
	Attic();// constructor
	~Attic();

	virtual char menu(); //run the room menu    
	virtual void searchRoom() override; //search room for clues
	virtual void fightDanger(Being *opponent) override; //search room and battle enemy for objects
	virtual void getDescription() override; //display the room's description

protected:
	//all member variables inherited from parent 


private:



};
#endif
