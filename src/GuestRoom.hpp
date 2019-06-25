/*********************************************************************

**		Author: Connie McClung

**		Date:

**		Description: GuestRoom.hpp
.
**		This is the GuestRoom child class header file. It contains the member variables and member variable declarations
**

*********************************************************************/
#ifndef GUESTROOM_HPP
#define GUESTROOM_HPP

#include"Room.hpp"
#include "Heroine.hpp"

class GuestRoom : public Room
{

public:

	GuestRoom();//default constructor
	~GuestRoom();

	virtual char menu();  //run the room menu       
	virtual void searchRoom() override;//search the room for clues
	virtual void fightDanger(Being *opponent) override;//battle enemy for objects
	virtual void getDescription() override;//display description of the room


protected:
	//all member variables inherited from parent 


private:

	bool isDressed;

};
#endif
