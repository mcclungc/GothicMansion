/*********************************************************************

**		Author: Connie McClung

**		Date:

**		Description: Cellar.cpp
.
**		This is the Kitchen child class implemntation file.


*********************************************************************/
#include "Cellar.hpp"
#include "Armor.hpp"
#include "Helpers.hpp"


/*********************************************************************

**

**		Description: Cellar()
.
**		default constructor


*********************************************************************/
Cellar::Cellar()
{
	this->name = "CELLAR";
	enemy = new Armor;
	isIlluminated = false;
	this->item.setItemName("DAGGER");
	this->item.setDescription("The suit of armor holds a silver dagger. JANE could use this for self-defense.");
	this->item.setIsRequiredToWin(true);
}


/*********************************************************************

**

**		Description: virtual char menu()
*		displays menu for this room and passes selection back to main game loop
.
**

*********************************************************************/

char Cellar::menu()
{
	//std::cout << description << std::endl;
	std::cout << "What would JANE like to do?" << std::endl;
	std::cout << "1. Look for useful objects (beware of danger!)." << std::endl;
	std::cout << "2. Search for clues." << std::endl;
	std::cout << "3. Leave room." << std::endl;
	std::cout << "4. Manage Objects and Clues." << std::endl;
	std::cout << "5. Quit Game." << std::endl;
	std::cout << std::endl;

	//input validation
	int choice = getAnInt("Enter  choice:");

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
		return 'S';//search for clues
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


/*********************************************************************

**

**		Description: virtual searchRoom()
.
**


*********************************************************************/

void Cellar::searchRoom()
{
	if (isIlluminated && !gotClue)
	{
		std::cout << std::endl;
		std::cout << "JANE decides to look behind the brick wall." << std::endl;
		std::cout << "To her horror, JANE discovers a man's handkerchief in the grip of a skeleton hand!" << std::endl;
		std::cout << "JANE bravely picks up the hand." << std::endl;
		std::cout << "Unfortunately, the bones crumble to dust and the rotted handkerchief shreds beyond recognition." << std::endl;
		std::cout << "Too bad, but JANE will remember what she has seen." << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		clue = "SIGHT OF SKELETON HAND";
		std::cout << "CLUE OBTAINED: " << clue << std::endl;
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
		//offer random chance to light room temporarily
		std::cout << "It's too dark in here. Does JANE have a candle or other light source?" << std::endl;
		std::cout << "There's a chance JANE could light her candle with an ember from the fireplace." << std::endl;
		std::cout << "Press enter to try." << std::endl;
		//bool chanceOfLight = false;
		int changeChance = rand() % 3 + 1;
		if (changeChance == 1)
		{
			std::cout << "Lucky JANE. There is a burning ember in the fireplace, so she can light her candle." << std::endl;
			std::cout << "JANE should hurry before the candle goes out and she must re-light it in the kitchen." << std::endl;
			isIlluminated = true;
		}
		else
		{
			std::cout << "No Luck. JANE needs a lighted candle. She could light her spare candle in the kitchen hearth..." << std::endl;
		}
	}
	slowDown();
}

/*********************************************************************

**

**		Description: virtual fightDanger()
.
**


*********************************************************************/
void Cellar::fightDanger(Being *opponent1)
{

	if (isIlluminated && !gotItem)
	{

		std::cout << "JANE looks around the cellar." << std::endl;
		std::cout << "She sees the " << item.getName() << "." <<std::endl;
		std::cout << item.getDescription() << std::endl;
		std::cout << std::endl;
		std::cout << "Suddenly the " << enemy->getName() << " moves toward JANE." << std::endl;
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
		//offer random chance to light room temporarily
		std::cout << "It's too dark in here. Does JANE have a candle or other light source?" << std::endl;
		std::cout << "There's a chance JANE could re-light her candle by blowing in it." << std::endl;
		std::cout << "Press enter to try." << std::endl;
		//bool chanceOfLight = false;
		int changeChance = rand() % 3 + 1;
		if (changeChance == 1)
		{
			std::cout << "Lucky JANE. Her candle is lit again for now, but she should light it by the kitchen fire as soon as possible." << std::endl;
			std::cout << "JANE should hurry before the candle goes out and she must re-light it in the kitchen." << std::endl;
			isIlluminated = true;
		}
		else
		{
			std::cout << "No Luck. JANE needs a lighted candle. She could light her spare candle in the kitchen hearth..." << std::endl;
		}
	}
	slowDown();
}

/*********************************************************************

**

**		Description: virtual getDescription
.
**


*********************************************************************/

void Cellar::getDescription()
{

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "JANE is in the cellar." << std::endl;
	std::cout << "This room contains a brick wall with a number of loose bricks exposing \n";
	std::cout << "the space behind it, and a rusty old suit of armor." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;



}
/*********************************************************************

**

**		Description: ~Kitchen()
.
**		destructor


*********************************************************************/
Cellar::~Cellar()
{
	delete enemy;
	enemy = nullptr;
}