/*********************************************************************

**		Author: Connie McClung

**		Date:

**		Description: Roof.hpp
.
**		This is the Roof child class header file. It contains the member variables and member variable declarations
**		Derived from Room abstract class.

*********************************************************************/
#ifndef ROOF_HPP
#define ROOF_HPP

#include"Room.hpp"

class Roof : public Room
{

public:
	Roof();//default constructor
	~Roof();

	virtual char menu(); //run the room menu        
	void searchRoom() override;//search the room for clues
	virtual void fightDanger(Being *opponent) override;//battle enemy for objects
	virtual void getDescription() override;//display description of the room
	



protected:
	//all member variables inherited from parent 


private:
	bool villainIsKnown;//to control whether certain displays occur 


};
#endif

