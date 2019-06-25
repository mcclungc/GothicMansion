/*********************************************************************

**		Author: Connie McClung

**		
**		Description: Helpers.cpp
.
**		This is the function implementation file for various helper functions


*********************************************************************/

#include "Helpers.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>


/*********************************************************************


**

**		Description : getAnInt()
.
**		//adapted from C++ for Engineers and Scientists By Gary J.Bronson, chapter 9


********************************************************************/

int getAnInt(std::string userPrompt)
{
	std::string numAsString;
	bool isValid;

	//run the desired prompt
	std::cout << userPrompt << std::endl;
	std::cin >> numAsString;

	 isValid= isInt(numAsString);

	//if the number entered was not an integer, prompt the user to try again
	while (!isValid)
	{
		std::cout << "Invalid choice. Please enter an integer value." << std::endl;
		std::cin >> numAsString;
		isValid = isInt(numAsString);

	}
	int num = strToInt(numAsString);
	return num;

}


/*********************************************************************

**		Description: isInt()
**
**		This helper function validates that input is an integer

*********************************************************************/
//method explained in http://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c

bool isInt(const std::string &intString) //iterate through string to see if it contains all numbers
{

	return !intString.empty() &&
	std::find_if(intString.begin(), intString.end(), [](char c)
	{ return !std::isdigit(c); }) == intString.end();
	
}

/*********************************************************************

**		Description: strToInt()
**
**		This helper function converts a number passed as string to an int

*********************************************************************/

int strToInt(std::string intString)
{
	return std::stoi(intString); //convert string to integer
}

/*********************************************************************

**		Description: isValidPosOrNegInt()
**
**		This helper function validates a positive or a negative integer


*********************************************************************/
//adapted from C++ for Engineers and Scientists By Gary J.Bronson, chapter 9
//validate numeric input allowing for positive or negative integer

bool isValidPosOrNegInt(std::string stringIn)
{
	int startNumeric = 0;
	int i;
	bool isValid = true;
	bool hasSign = false;

	if (static_cast<int>(stringIn.length()) == 0) //check use of int is this data type casting?
	{
		isValid = false;
	}

	if ((stringIn.at(0) == '-') || (stringIn.at(0) == '+'))
	{
		hasSign = true;
		startNumeric = 1;
	}

	if (hasSign && static_cast<int>(stringIn.length()) == 1)
	{
		isValid = false;
	}

	i = startNumeric;
	while (isValid && i < static_cast<int>(stringIn.length()))
	{
		if (!isdigit(stringIn.at(i)))
		{
			isValid = false;
		}
		i++;
	}
	return isValid;
}

/*********************************************************************

**		Description: slowDown()
**
**		slows down by pausing for user to press enter

*********************************************************************/
void slowDown()
{
	std::cout << std::endl;
	std::cout << "Press Enter to continue." << std::endl;
	std::cin.get();
	//std::cin.get();
}