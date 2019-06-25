/*********************************************************************

**		Author: Connie McClung

**		Date:

**		Description: GuestRoom.cpp
.
**		This is the GuestRoom child class implemntation file.


*********************************************************************/
#include "GuestRoom.hpp"
#include "Raven.hpp"
#include "Game.hpp"


/*********************************************************************

**

**		Description: GuestRoom()
.
**		default constructor


*********************************************************************/
GuestRoom::GuestRoom()
{
	this->name = "GUEST SUITE";
	enemy = new Raven;
	//isIlluminated = true;
	isIlluminated = false;
	this->item.setItemName("SIGNET RING");
	this->item.setDescription("JANE'S engagement ring, Lord Tarreyton's signet ring, may come in handy...");
	this->item.setIsRequiredToWin(true);
	isDressed = false;
}


/*********************************************************************

**

**		Description: virtual char menu()
*		displays menu for this room and passes selection back to main game loop
.
**

*********************************************************************/

char GuestRoom::menu()
{
	//std::cout << description << std::endl;
	std::cout << "What would JANE like to do?" << std::endl;
	if (isDressed == false)
	{
		std::cout << "1. Get Dressed and look around for useful objects." << std::endl;
	}
	else if(isDressed == true)
	{
		std::cout << "1. Look around for useful objects." << std::endl;
	}
	std::cout << "2. Read the note." << std::endl;
	std::cout << "3. Leave room." << std::endl;
	std::cout << "4. Manage Objects and Clues." << std::endl;
	std::cout << "5. Quit Game." << std::endl;
	std::cout << std::endl;

	//input validation
	int choice = getAnInt("Enter  choice:");

	while (choice < 1|| choice > 5)
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
		return 'I'; //manage items and objects
		break;
	}
	case 5:
	{
		return 'Q'; //quit game
		break;
	}
	default:
		return 'S';
		break;
	}
	
}

/*********************************************************************

**

**		Description: virtual getDescription
.
**


*********************************************************************/

void GuestRoom::getDescription()
{
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "JANE is in the guest suite." << std::endl;
	std::cout << "The room contains a bed, the wardrobe holding her belongings, \n";
	std::cout << "and a dresser with some of her personal items on top." << std::endl;
	std::cout << "The window is open because she wanted fresh air while sleeping." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	

}



/*********************************************************************

**

**		Description: virtual searchRoom()
.
**


*********************************************************************/

void GuestRoom::searchRoom()
{
	
	if(isIlluminated && !gotClue)
	{
		std::cout << std::endl;
		std::cout << "The note is addressed to JANE in unfamiliar handwriting." << std::endl;
		std::cout<< "She reads..." << std::endl;
		std::cout << "\"I have taken your fiance and will have revenge for the past!" << std::endl;
		std::cout << "All the servants have abandoned this forsaken house." << std::endl;
		std::cout << "Run away, little orphan! Or try to rescue your beloved if you dare.\"" << std::endl;
		std::cout << std::endl;
		std::cout << "There is a drop of blood on the page. Lord Tarreyton has been injured!" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		clue = "ABDUCTOR'S NOTE";
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
		//offer random chance to light candle temporarily
		std::cout << "It's too dark in here and the fire is out. Does JANE have a candle or other light source?" << std::endl;
		std::cout << "There's a chance JANE could light her candle with an ember from the fireplace." << std::endl;
		std::cout << "Press enter to try." << std::endl;
		std::cin.get();
		std::cin.get();
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
			std::cout << "No luck. JANE needs a lighted candle. She could light her spare candle in the kitchen hearth..." << std::endl;
		
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

void GuestRoom::fightDanger(Being *opponent1)
{
	if (isIlluminated && !gotItem)
	{
		if (!isDressed)//only show text about getting dressed once
		{
			std::cout << "JANE goes to the wardrobe to dress and get her reticule (old-timey word for handbag)." << std::endl;
			std::cout << "She tucks an unlighted CANDLE and special health tonic into the reticule just in case." << std::endl;
			std::cout << "Now there is only room for 5 more objects, but she can collect unlimited clues." << std::endl;
			std::cout << std::endl;
		}
		
		std::cout << std::endl;
		std::cout << "JANE looks on the dresser for any useful objects." << std::endl;
		std::cout << "She sees the " << item.getName() <<"."<< std::endl;
		std::cout << item.getDescription() << "." << std::endl;
		std::cout << "Suddenly a huge "<<enemy->getName()<<" flies through the window." << std::endl;
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
			std::cout << opponent1->getName() << " has vanquished the " <<enemy->getName()<< "." << std::endl;
			if (roundCounter > 5)//if fight takes too long, it weakens Heroine
			{
				std::cout << opponent1->getName() << " is feeling a bit weaker, however." << std::endl;
				opponent1->setStrength(opponent1->getStrength() - 2);
			}
			std::cout << opponent1->getName() << " can now collect the " << item.getName() << "." << std::endl;
			std::cout <<item.getDescription() << std::endl;
			setGotItem(true);
			isDressed = true;

		}
		else if (enemy->getStrength() > (*opponent1).getStrength())
		{
			std::cout << opponent1->getName()<< "has been killed by " << enemy->getName() << "." << std::endl;
		}
		else //just in case for testing
		{
			std::cout << "ERROR! WINNER IS UNDETERMINED." << std::endl;
		}
	
	}
	else if(isIlluminated && gotItem)
	{
		std::cout << std::endl;
		std::cout << "JANE has obtained all items available in this room." << std::endl;
		std::cout << "Don't waste time while Lord Tarreyton is injured!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		//offer random chance to light candle temporarily
		std::cout << "It's too dark in here and the fire is out. Does JANE have a candle or other light source?" << std::endl;
		std::cout << "There's a chance JANE could light her candle with an ember from the fireplace." << std::endl;
		std::cout << "Press enter to try her luck." << std::endl;
		std::cin.get();
		std::cin.get();
		//bool chanceOfLight = false;
		int changeChance =rand() %3 + 1;
		if (changeChance == 1)
		{
			std::cout << "Lucky JANE. There is a burning ember in the fireplace, so she can light her candle." << std::endl;
			std::cout << "JANE should hurry before the candle goes out and she must re-light it in the kitchen." << std::endl;
			isIlluminated = true;
		}
		else
		{
			std::cout << "No luck. JANE must dress in the dark, then light her candle at the kitchen hearth..." << std::endl;
			std::cout << std::endl;
			std::cout << "JANE stumbles to the wardrobe in the dark to dress and get her reticule (old-timey word for handbag)." << std::endl;
			std::cout << "She tucks an unlighted CANDLE into her reticule just in case." << std::endl;
			std::cout << "Now there is only room for 5 more objects, but she can collect unlimited clues." << std::endl;
			std::cout << "JANE takes a swig of her special health tonic. She needs the strength to bounce back from adversity." << std::endl;
			std::cout << std::endl;
			std::cout << "HINT: JANE should return and read the note so she will understand her quest!" << std::endl;
			isDressed = true;
		}

		
	}
	slowDown();
}

/*********************************************************************

**

**		Description: ~GuestRoom()
.
**		destructor


*********************************************************************/
GuestRoom::~GuestRoom()
{
	delete enemy;
	enemy = nullptr;
}