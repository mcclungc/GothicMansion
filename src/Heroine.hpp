/*********************************************************************

**		Author: Connie McClung

**		Date:

**		Description: Heroine.hpp
.
**		This is the Heroine child class header file. It contains the member variables and member variable declarations
**		Derived from Being class.

*********************************************************************/
#ifndef HEROINE_HPP
#define HEROINE_HPP
#include "Being.hpp"
#include <iostream>


class Heroine: public Being
{

public:
	Heroine();//default constructor
	virtual ~Heroine();
	
	int attack(Being *opponent) override;// virtual function can be overridden by child class
	void defense(int otherAttack) override;// virtual function can be overridden by child class
	
	bool getIsFirstLife();
protected:
	

private:
	//int lives;
	bool isFirstLife;
	


};
#endif