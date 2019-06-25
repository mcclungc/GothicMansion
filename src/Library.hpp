/*********************************************************************

**		Author: Connie McClung

**		Date:

**		Description: Library.hpp
.
**		This is the Library child class header file. It contains the member variables and member variable declarations
**		Derived from Room abstract class.

*********************************************************************/
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include"Room.hpp"

class Library : public Room
{

public:
	Library();//default constructor
	~Library();

	virtual char menu(); //run the room menu        
	void searchRoom() override;//search the room for clues
	virtual void fightDanger(Being *opponent) override;//battle enemy for objects
	virtual void getDescription() override;//display description of the room

protected:
	//all member variables inherited from parent 


private:



};
#endif

