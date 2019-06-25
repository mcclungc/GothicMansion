/*********************************************************************

**		Author: Connie McClung

**		Date:

**		Description: Roof.cpp
.
**		This is the Roof child class implementation file. 
*		This is where the identity of the villain is discovered and rescue is possible.


*********************************************************************/
#include "Roof.hpp"
#include "Helpers.hpp"


/*********************************************************************

**

**		Description: Roof()
.
**		default constructor


*********************************************************************/
Roof::Roof()
{
	this->name = "ROOF";
	villainIsKnown = false;
	//hasDagger = false;
	//hasFlask = false;
	//hasLocket = false;
	//hasSignetRing = false;
	

}


/*********************************************************************

**

**		Description: virtual char menu()
.
**

*********************************************************************/

char Roof::menu()
{
	//std::cout << description << std::endl;
	std::cout << "What would JANE like to do?" << std::endl;
	std::cout << "1. Look for useful objects." << std::endl;
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
		return 'F';//fight enemy for object
		break;
	}
	case 2:
	{
		return 'S';//search for clue
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

void Roof::searchRoom()
{
	if (!gotClue)
	{
		std::cout << "JANE has found Lord Tarreyton! " << std::endl;
		std::cout << std::endl;
		std::cout << "Her fiance is tied to the chimney. His shirt is red with blood!" << std::endl;
		std::cout << "He cries out, \"Run, you little fool. Find help before this maniac kills me!\"" << std::endl;
		std::cout << "Clearly, he has underestimated JANE's rescuing ability." << std::endl;
		std::cout << "A person is standing beside Lord Tarreyton, but JANE can't see clearly from this distance." << std::endl;
		std::cout << "If JANE is prepared to face danger, she should approach, looking for useful objects as she goes." << std::endl;
		std::cout << std::endl;
		clue = "TARREYTON FOUND";
		std::cout << "CLUE OBTAINED: " << clue << std::endl;
		gotClue = true;
		std::cout << std::endl;
		slowDown();
	}
	else if (gotClue)
	{
		std::cout << std::endl;
		std::cout << "JANE has alreay discovered that Lord Tarreyton is on the roof." << std::endl;
		std::cout << "No time to stand around gawking!" << std::endl;
		std::cout << std::endl;
	}


}
/*********************************************************************

**

**		Description: virtual fightDanger()
.
**


*********************************************************************/

void Roof::fightDanger(Being *opponent1)
{
	if ( !villainVanquished)
	{

		std::cout << "JANE bravely approaches Lord T and the unknown villain." << std::endl;
		std::cout << "As she gets closer, the villain turns to face her. "  << std::endl;
		std::cout << "What a shock! Lord Tarreyton's abductor is..." << std::endl;
		slowDown();
		std::cout << std::endl;
		
		//There are 5 possible villains, determined randomly each time
		//The clues have suggested each possible villain
		//Heroine must have a different object to defeat different villains

		std::string rescueItem;
		std::string rescueItem2;
		//bool readyToWin;
		int villainNum = rand() % 5 + 1;
		switch (villainNum)
		{
		case 1:
		{
			std::cout << "Lord Tarreyton was abducted by his nephew, the true Lord Tarreyton." << std::endl;
			std::cout << "Lord Tarreyton killed his brother to gain the title, and sent his nephew to a prison colony in the South Seas." << std::endl;
			std::cout << std::endl;
			std::cout << "The imprisoned true heir has returned to avenge his father and reclaim the title." << std::endl;
			std::cout << std::endl;
			std::cout << "JANE's fiance is wicked and dishonest! But he still needs to be rescued." << std::endl;
			rescueItem = "SIGNET RING";
			std::cout << std::endl;
			std::cout <<"To rescue her fiance, JANE must have the " << rescueItem<<"."<<std::endl;
			if (hasSignetRing)
			{
				std::cout << std::endl;
				std::cout << "JANE HAS RESCUED LORD TARREYTON!" << std::endl;
				villainVanquished = true;
			}
			else 
			{
				std::cout << std::endl;
				std::cout << "JANE does not have the required object!" << std::endl;
				std::cout << "JANE should flee and search the house again!" << std::endl;
				std::cout << "However, many people hate her fiance!" << std::endl;
				std::cout << "There is no guarantee JANE will encounter the same villain next time!" << std::endl;
				std::cout << std::endl;
			}
			break;
		}
		case 2:
		{
			std::cout << "Lord Tarreyton was abducted by his psychotic wife." << std::endl;
			std::cout << "She did not die in a fire; she set the fire after her child died after a chest cold." << std::endl;
			std::cout << std::endl;
			std::cout << "Mad with grief, she blamed her indifferent husband and his drafty mansion." << std::endl;
			std::cout << "Your fiance survived and told everyone she died in the fire." << std::endl;
			std::cout << "For years she has been locked in the attic with a cruel servant." << std::endl;
			std::cout << std::endl;
			std::cout << "JANES's despicable fiance planned to commit bigamy! But he still needs to be rescued." << std::endl;
			rescueItem = "LOCKET";
			std::cout << "To rescue her fiance, JANE must have the " << rescueItem << "." << std::endl;
			if (hasLocket)
			{
				std::cout << std::endl;
				std::cout << "JANE HAS RESCUED LORD TARREYTON!" << std::endl;
				villainVanquished = true;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "JANE does not have the required object!" << std::endl;
				std::cout << "JANE should flee and search the house again!" << std::endl;
				std::cout << "However, many people hate her fiance!" << std::endl;
				std::cout << "There is no guarantee JANE will encounter the same villain next time!" << std::endl;
				std::cout << std::endl;
			}
			break;
		}
		case 3:
		{
			std::cout << "Lord Tarreyton was abducted by a business associate." << std::endl;
			std::cout << "Your fiance killed his own brother and cheated the other investor in their shipping endeavor." << std::endl;
			std::cout << std::endl;
			std::cout << "The associate is now penniless." << std::endl;
			std::cout << "He couldn't find proof of your fiance's fraud and murder, so he must settle for revenge." << std::endl;
			std::cout << std::endl;
			std::cout << "JANE's despicable fiance is a murdering cheat! But he still needs to be rescued." << std::endl;
			rescueItem = "DAGGER";
			std::cout << "To rescue her fiance, JANE must have the " << rescueItem << "." << std::endl;
			if (hasDagger)
			{
				std::cout << std::endl;
				std::cout << "JANE HAS RESCUED LORD TARREYTON!" << std::endl;
				villainVanquished = true;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "JANE does not have the required object!" << std::endl;
				std::cout << "JANE should flee and search the house again!" << std::endl;
				std::cout << "However, many people hate her fiance!" << std::endl;
				std::cout << "There is no guarantee JANE will encounter the same villain next time!" << std::endl;
				std::cout << std::endl;
			}
			break;
		}
		case 4:
		{
			std::cout << "Lord Tarreyton was abducted by the housekeeper." << std::endl;
			std::cout << "This poor woman gave a tonic to Lord T's son when he was sick." << std::endl;
			std::cout << "But the potion killed the child." << std::endl;
			std::cout << std::endl;
			std::cout << "For years, Lord T thought his wife kiled their child." << std::endl;
			std::cout << "But last night, he found a letter the housekeeper wrote confessing to her sin!" << std::endl;
			std::cout << "JANE's cruel fiance turned her out in the cold with no references after 30 years of service." << std::endl;
			rescueItem = "FLASK";
			std::cout << std::endl;
			std::cout << "JANE's  fiance is heartless! But he still needs to be rescued." << std::endl;
			std::cout << "JANE must offer the housekeeper health tonic dosed with laudanum from the " << rescueItem << " to sedate her." << std::endl;
			if (hasFlask)
			{
				std::cout << std::endl;
				std::cout << "JANE HAS RESCUED LORD TARREYTON!" << std::endl;
				villainVanquished = true;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "JANE does not have the required object!" << std::endl;
				std::cout << "JANE should flee and search the house again!" << std::endl;
				std::cout << "However, many people hate her fiance!" << std::endl;
				std::cout << "There is no guarantee JANE will encounter the same villain next time!" << std::endl;
				std::cout << std::endl;
			}
			break;
		}
		case 5:
		{
			std::cout << "Lord Tarreyton was abducted by his valet." << std::endl;
			std::cout << std::endl;
			std::cout << "After years of faithful service, his valet was going to be dismissed." << std::endl;
			std::cout << "Lord T couldn't risk the valet revealing secrets to JANE, his new bride." << std::endl;
			std::cout << "But the valet had no intention of leaving quietly!" << std::endl;
			std::cout << std::endl;
			std::cout << "JANE's fiance treats people terribly, but he still needs rescuing." << std::endl;
			rescueItem = "LORD TARREYTON'S FLASK";
			rescueItem2 = "DAGGER";
			std::cout << "To rescue her fiance, JANE must have the " << rescueItem <<" or the "<<rescueItem2<< "." << std::endl;
			if (hasDagger)
			{
				std::cout << std::endl;
				std::cout << "JANE HAS RESCUED LORD TARREYTON!" << std::endl;
				villainVanquished = true;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "JANE does not have the required object!" << std::endl;
				std::cout << "JANE should flee and search the house again!" << std::endl;
				std::cout << "However, many people hate her fiance!" << std::endl;
				std::cout << "There is no guarantee JANE will encounter the same villain next time!" << std::endl;
				std::cout << std::endl;
			}
			break;
		}
		
		}
		
	}
	else if (villainVanquished) //this should not occur in my current game structure
	{
		std::cout << std::endl;
		std::cout << "Are you still up here on the roof? " << std::endl;
		std::cout << "Now the villain has been defeated, you must find a physician for Lord Tarreyton!" << std::endl;
		std::cout << std::endl;
	}
	else//this is just in case logic goes wrong
	{
		std::cout << "JANE has a sudden fit of the vapors. Time to flee the roof and regain her composure." << std::endl;
		
	}
}



/*********************************************************************

**

**		Description: virtual getDescription
.
**


*********************************************************************/

void Roof::getDescription()
{

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "JANE follows the narrow staircase to the Roof." << std::endl;
	std::cout << "Due to the medieval design of the house," << std::endl;
	std::cout << "The roof is flat. \n";
	std::cout << "A shocking sight appears before her eyes." << std::endl;
	std::cout << std::endl;
	if(!gotClue)
	{
		std::cout << "HINT: JANE should search for clues before she does anything else!" << std::endl;
		std::cout << std::endl;
	}



}
/*********************************************************************

**

**		Description: ~Roof()
.
**		destructor


*********************************************************************/
Roof::~Roof()
{

}