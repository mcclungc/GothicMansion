/*********************************************************************

**		Author: Connie McClung

**		Date:

**		Description: Cellar.hpp
.
**		This is the Cellar child class header file. It contains the member variables and member variable declarations
**		Derived from Room abstract class.

*********************************************************************/
#ifndef CELLAR_HPP
#define CELLAR_HPP

#include"Room.hpp"

class Cellar : public Room
{

public:
	Cellar();// constructor
	~Cellar();

	virtual char menu(); //run the room menu        
	void searchRoom() override;//search the room for clues
	virtual void fightDanger(Being *opponent1) override;//battle enemy and obtain objects
	virtual void getDescription() override;//display description of the room

protected:
	//all member variables inherited from parent 


private:



};
#endif

