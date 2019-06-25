/*********************************************************************

**		Author: Connie McClung

**

**		Description: Helpers.hpp
.
**		function declarations for collection of helper functions
**

*********************************************************************/
#ifndef HELPERS_HPP
#define HELPERS_HPP

#include<string>


//function prototypes

//helper routines for input validation 
int getAnInt(std::string userPrompt);
bool isValidPosOrNegInt(std::string stringIn);
int strToInt(std::string intString);
bool isInt(const std::string &intString);
void slowDown();



#endif