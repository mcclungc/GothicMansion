/*********************************************************************

**		Author: Connie McClung

**

**		Description: Servant.hpp
.
**		This is the Murderous Servant child class header file. It contains the member variables and member variable declarations
**		Derived from Being Class.

*********************************************************************/
#ifndef SERVANT_HPP
#define SERVANT_HPP

#include"Being.hpp"

class Servant : public Being
{
public:
	Servant();//default constructor
	//all other functions inherited from parent class
	virtual ~Servant();

protected:
	//all data variables inherited from parent

private:



};
#endif