/*********************************************************************

**		Author: Connie McClung

**

**		Description: Ghost.hpp
.
**		This is the Ghostly Lady child class header file. It contains the member variables and member variable declarations
**		Derived from Being abstract class.

*********************************************************************/
#ifndef GHOST_HPP
#define GHOST_HPP

#include"Being.hpp"

class Ghost : public Being
{

public:
	Ghost();//default constructor
	virtual void defense(int otherAttack);//overrides parent function
	virtual ~Ghost();

protected:
	//all member variables inherited from parent 


private:



};
#endif
