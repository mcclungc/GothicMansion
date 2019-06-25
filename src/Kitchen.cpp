/*********************************************************************

**		Author: Connie McClung

**		Description: Kitchen.cpp
.
**		This is the Kitchen child class implementation file.


*********************************************************************/
#include "Kitchen.hpp"
#include "Hound.hpp"
#include "Helpers.hpp"
#include <string>


/*********************************************************************

**

**		Description: Kitchen()
.
**		default constructor


*********************************************************************/
Kitchen::Kitchen()
{
	this->name = "KITCHEN";
	enemy = new Hound;
	isIlluminated = true;
	//isIlluminated = false;
	this->item.setItemName("HOUSEKEEPER'S MEDICINE BOX");
	this->item.setDescription("The housekeeper keeps bandages and herbal tonics in this box.");
	this->item.setIsRequiredToWin(false);
	lightObtained = false;
}


/*********************************************************************

**

**		Description: virtual char menu()
*		displays menu for this room and passes selection back to main game loop
.
**

*********************************************************************/

char Kitchen::menu()
{
	{
		std::cout << "What would JANE like to do?" << std::endl;
		std::cout << "1. Search for useful objects (beware of danger!)" << std::endl;
		std::cout << "2. Light a candle and look around for clues." << std::endl;
		std::cout << "3. Leave room." << std::endl;
		std::cout << "4. Manage Objects and Clues." << std::endl;
		std::cout << "5. Quit Game." << std::endl;
		std::cout << std::endl;

		//input validation
		int choice = getAnInt("Enter choice:");

		while (choice < 1 || choice > 5)
			choice = getAnInt("Invalid choice. Enter a valid menu option:");

		std::cout << std::endl;

		switch (choice)
		{
		case 1:
		{
			return 'F';//fight enemy for objects
			break;
		}
		case 2:
		{
			return 'S';//search room for clues
			break;
		}
		case 3:
		{
			return 'M';//move to another room
			break;
		}
		case 4:
		{
			return 'I';//manage objects and clues
			break;
		}
		case 5:
		{
			return 'Q';//quit game
			break;
		}
		default:
			return 'S';
			break;
		}

	}

}


/*********************************************************************

**

**		Description: virtual searchRoom()
.
**		


*********************************************************************/

void Kitchen::searchRoom()
{
	if (isIlluminated && !gotClue)
	{

		std::cout << "Go to the hearth. JANE can re-light her candle if she needs to." << std::endl;
		std::cout << "As JANE looks into the fire, she spots a scrap of paper..." << std::endl;
		std::cout << std::endl;
		std::cout << "\"I meant no harm. I was only trying to help the little one's cough." << std::endl;
		std::cout << "If Lord Tarreyton ever finds out...\"" << std::endl;
		std::cout << "The rest of the letter is burned and unreadable." << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		clue = "BURNT LETTER";
		std::cout << "CLUE OBTAINED: " << clue << std::endl;
		std::cout << "OBJECT OBTAINED: LIGHTED CANDLE" << std::endl;
		gotClue = true;
		std::cout << std::endl;
	}
	else if (isIlluminated && gotClue)
	{
		std::cout << std::endl;
		std::cout << "JANE has discovered all the clues available in this room." << std::endl;
		std::cout << "Don't waste time while Lord Tarreyton is injured!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "JANE needs a lighted candle. She could light her spare candle in the kitchen hearth..." << std::endl;
	
	}
	slowDown();
}

/*********************************************************************

**

**		Description: virtual fightDanger()
.
**


*********************************************************************/

void Kitchen::fightDanger(Being *opponent1)
{
	if (isIlluminated && !gotItem)
	{

		std::cout << "JANE looks around the kitchen for any useful objects." << std::endl;
		std::cout << "She sees the "<< item.getName() <<"."<< std::endl;
		std::cout << item.getDescription() << std::endl;
		std::cout << std::endl;
		std::cout << "Suddenly a huge " << enemy->getName() << " rushes through the door and lunges at JANE." << std::endl;
		slowDown();
		std::cout << std::endl;


		//Heroine always goes first
		bool isO1Turn = true;
		//int whoseTurn = 1;

		std::cout << opponent1->getName() << " VS." << enemy->getName() << ":" << std::endl;
		std::cout << std::endl;
		std::cout << opponent1->getName() << " starting strength is " << opponent1->getStrength() << "." << std::endl;
		std::cout << enemy->getName() << " starting strength is " << enemy->getStrength() << "." << std::endl;
		std::cout << std::endl;
		std::cout << opponent1->getName() << " will attack first." << std::endl;
		int roundCounter = 0;
		int attackOppScore;
		std::cout << std::endl;


		while (opponent1->getStrength() > 0 && enemy->getStrength() > 0)
		{
			roundCounter++;
			std::cout << "Round " << roundCounter << ":" << std::endl;
			std::cout << std::endl;
			if (isO1Turn)
			{
				std::cout << opponent1->getName() << " attacks." << std::endl;
				attackOppScore = (*opponent1).attack(enemy);
				std::cout << std::endl;
				(*enemy).defense(attackOppScore);
			}
			else
			{
				std::cout << enemy->getName() << " attacks." << std::endl;
				attackOppScore = (*enemy).attack(opponent1);
				std::cout << std::endl;
				(*opponent1).defense(attackOppScore);
			}
			std::cout << std::endl;
			std::cout << "Round " << roundCounter << " results: " << std::endl;
			std::cout << std::endl;
			std::cout << opponent1->getName() << " strength: " << (*opponent1).getStrength() << std::endl;
			std::cout << enemy->getName() << " strength: " << enemy->getStrength() << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			isO1Turn = !isO1Turn;
			//pause after each round, can be commented out for speed of play

			if (opponent1->getStrength() > 0 && enemy->getStrength() > 0)
			{
				std::cout << "Press Enter to play the next round." << std::endl;
				std::cin.get();
				std::cin.get();
			}

		}
		std::cout << std::endl;
		//std::cout << "Fight Over." << std::endl;
		std::cout << std::endl;
		if ((*opponent1).getStrength() > enemy->getStrength())
		{
			std::cout << opponent1->getName() << " has vanquished the " << enemy->getName() << "." << std::endl;
			if (roundCounter > 5)//if fight takes too long, it weakens Heroine
			{
				std::cout << opponent1->getName() << " is feeling a bit weaker, however." << std::endl;
				opponent1->setStrength(opponent1->getStrength() - 2);
			}
			std::cout << opponent1->getName() << " can now collect the " << item.getName() << "." << std::endl;
			//std::cout << item.getDescription() << std::endl;
			setGotItem(true);

		}
		else if (enemy->getStrength() > (*opponent1).getStrength())
		{
			std::cout << opponent1->getName() << "has been killed by " << enemy->getName() << "." << std::endl;
		}
		else //just in case for testing
		{
			std::cout << "ERROR! WINNER IS UNDETERMINED." << std::endl;
		}

	}
	else if (isIlluminated && gotItem)
	{
		std::cout << std::endl;
		std::cout << "JANE has obtained all items available in this room." << std::endl;
		std::cout << "Don't waste time while Lord Tarreyton is injured!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "JANE needs a lighted candle. She could light her spare candle in the kitchen hearth..." << std::endl;
		std::cout << "Luckily, JANE can see everything in the kitchen by the light of the hearth fire." << std::endl;
		std::cout << std::endl;
	}
	slowDown();
}

/*********************************************************************

**

**		Description: virtual getDescription
.
**


*********************************************************************/

void Kitchen::getDescription()
{

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "JANE is in the kitchen." << std::endl;
	std::cout << "This room contains a hearth, an oven, \n";
	std::cout << "and a shelf containing the housekeeper's supplies." << std::endl;
	std::cout << "The door to the garden is open as if someone left in a hurry." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;



}
/*********************************************************************

**

**		Description: ~Kitchen()
.
**		destructor


*********************************************************************/
Kitchen::~Kitchen()
{
	delete enemy;
	enemy = nullptr;
}