/*************************************************************************************************************
**
**		Name:			Connie McClung
**
**
**		Date:			
**
**
**		Description:	This is the main program file.
**
**
**
**************************************************************************************************************/

#include "Room.hpp"
#include "Kitchen.hpp"
#include "GuestRoom.hpp"
#include "MasterSuite.hpp"
#include "Attic.hpp"
#include "Cellar.hpp"
#include "Roof.hpp"
#include "Library.hpp"
#include "Game.hpp"

#include "Being.hpp"
#include "Heroine.hpp"

//function prototypes
void runGothicMansion();
void displayProgramMenu();
int getMenuChoice(int menuMin, int menuMax);
void processMenu(int menuChoice);

int main()
{
	
	runGothicMansion();	
	return 0;
	
}


/*********************************************************************

**
	Description: runGothicMansion()
.
**		This function displays menu, calls getMenuchoice, and
		calls processMenu to act on input.

**

*********************************************************************/

void runGothicMansion()
{
	
	//Menu functions
	int menuChoice;
	int menuMin = 1;
	int menuMax = 2;
	do
	{
		displayProgramMenu();//show main menu options
		menuChoice = getMenuChoice(menuMin, menuMax);

		if (menuChoice != menuMax)
		{
			processMenu(menuChoice);
		}

	} while (menuChoice != menuMax);

}


/*********************************************************************

**			Description:  displayProgramMenu()
**
**			This function displays main  menu choices

*********************************************************************/
void displayProgramMenu()
{
	//display menu
	//std::cout << std::endl;
	std::cout << "GAME TITLE: GOTHIC MANSION" << std::endl;
	std::cout << "1. Play Game." << std::endl;
	std::cout << "2. Quit." << std::endl;
	std::cout << std::endl;
}

/*********************************************************************

**			Description:  getMenuChoice()
**
**			This function inputs, validates, and returns user's menu choice

*********************************************************************/
int getMenuChoice(int menuMin, int menuMax)
{
	//std::cout << "in getMenuChoice" << std::endl;
	std::string choice;
	int numberChoice;

	std::cin >> choice;

	//validate integer data type
	bool isValidNumber = isInt(choice);
	while (!isValidNumber)
	{
		std::cout << "The only valid menu choices are " << menuMin << "-" << menuMax << std::endl;
		std::cin >> choice;
		isValidNumber = isInt(choice);
	}
	numberChoice = strToInt(choice);

	//validate choice
	while (numberChoice <menuMin || numberChoice > menuMax)
	{
		std::cout << "The only valid menu choices are " << menuMin << "-" << menuMax << std::endl;
		std::cin >> choice;
		isValidNumber = isInt(choice);
		while (!isValidNumber)
		{
			std::cout << "The only valid menu choices are " << menuMin << "-" << menuMax << std::endl;
			std::cin >> choice;
			isValidNumber = isInt(choice);
		}
		numberChoice = strToInt(choice);
	}

	return numberChoice;

}

/*********************************************************************

**		Description: processMenu
**
**		This function receives member choice and calls appropriate functions in response

*********************************************************************/

void processMenu(int menuChoice)
{

	//std::cout << "In processMenu function." << std::endl;
	switch (menuChoice)
	{
	case 1:
	{
		std::cout << std::endl;
		//std::cout << "You chose Play Game." << std::endl;
		std::cout << std::endl;
		Game mygame;
		mygame.gameIntro();
		mygame.play();

		std::cout << std::endl;
		std::cout << "Press Enter to return to main menu." << std::endl;
		std::cin.get();
		std::cin.get();

		break;
	}

	}

}