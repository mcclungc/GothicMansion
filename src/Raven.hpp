/*********************************************************************

**		Author: Connie McClung

**		Date:

**		Description: Raven.hpp
.
**		This is the Being a class header file. It contains the member variables and member variable declarations
**		Derived from Being abstract class.

*********************************************************************/
#ifndef RAVEN_HPP
#define RAVEN_HPP
#include "Being.hpp"
#include <iostream>

class Raven : public Being
{

public:
	Raven();//default constructor
	void defense(int otherAttack) override;//overrides parent function
	virtual ~Raven();
protected:


private:



};
#endif
