/*********************************************************************

**		Author: Connie McClung

**

**		Description: Game.cpp
.
**		


*********************************************************************/
#include "Game.hpp"
#include <string>
#include <iostream>


/*********************************************************************

**

**		Description: Game()
.
**		default constructor
*		creates and connects room child objects, creates heroine object and implements container for objects/clues


*********************************************************************/
Game::Game()
{
	//create Rooms
	guestroom = new GuestRoom;
	attic = new Attic;
	masterSuite = new MasterSuite;
	kitchen = new Kitchen;
	cellar = new Cellar;
	library = new Library;
	roof = new Roof;

	
	//set pointers to link rooms together
	guestroom->setDirection('L', kitchen);
	guestroom->setDirection('R', masterSuite);
	guestroom->setDirection('D', cellar);
	guestroom->setDirection('U', attic);

	masterSuite->setDirection('L', guestroom);
	masterSuite->setDirection('R', library);
	masterSuite->setDirection('D', cellar);
	masterSuite->setDirection('U', attic);

	kitchen->setDirection('L', library);
	kitchen->setDirection('R', guestroom);
	kitchen->setDirection('D', cellar);
	kitchen->setDirection('U', attic);

	library->setDirection('L', masterSuite );
	library->setDirection('R', kitchen);
	library->setDirection('D', cellar);
	library->setDirection('U', attic);

	attic->setDirection('D', masterSuite);
	attic->setDirection('U', roof);

	cellar->setDirection('U', kitchen);
	roof->setDirection('D', attic);

	
	//create Heroine
	myHeroine = new Heroine;

	//give Heroine an unlit candle
	reticule.add("CANDLE");
	
	currentLocation = guestroom;//start game in Heroine's bedroom
	
	//initialize game and heroine variables
	deadLord = false;
	isWinner = false;

	lordLifeStrength = 50;
	itemsCollected =0;
	

	//seed the random number generator for the game
	unsigned seed;
	seed = static_cast<unsigned int>(time(0));
	srand(seed);

}

/*********************************************************************

**

**		Description: gameIntro()
.		introduces situation and gives game objective
**


*********************************************************************/
void Game::gameIntro()
{
	std::cout << "GOTHIC MANSION" << std::endl;
	std::cout << "Objective: Heroine must battle danger, collect objects, and find clues to rescue her abducted fiance." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "GAME INTRO:" << std::endl;
	std::cout << "A soft noise awakens our heroine " << myHeroine->getName() << "."<<std::endl;
	std::cout << "It is the morning of her wedding to Lord Tarreyton." << std::endl;
	std::cout << std::endl;
	std::cout << "Imagine a penniless orphan becoming engaged to " << std::endl;
	std::cout << "a rich, handsome lord she met in the flower market!" << std::endl;
	std::cout << std::endl;
	std::cout << "His tragic past as a widower who lost his wife and son "<< std::endl;
	std::cout << "in a fire is so romantic! \n";
	std::cout << std::endl;
	std::cout << "Granted, he lives in a creepy Gothic mansion shaped like a pentagon, " << std::endl;
	std::cout << "but nobody's perfect." << std::endl;
	std::cout << std::endl;
	std::cout << "JANE rings for a servant but no one arrives." << std::endl;
	std::cout << "In the dim light she sees a note on her pillow... " << std::endl;
	std::cout << "The only words she can make out are \"I have taken your fiance..\"" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	slowDown();
}



/*********************************************************************

**

**		Description: play()
*		Idea to use a menu-based loop adapted from example project by Christopher Merill,
*		because it worked best with my game concept of a heroine who has to rescue someone in a creepy mansion.
*		I tried other mechanisms, but this was the one that worked best. In order to avoid copying someone else's work,
*		I used different menu options, wrote the menu choice structure differently with switch statements, and
*		organized / wrote the room functions differently. Also added battles between player object and
*		enemy objects, added multiple ways for time element to take effect and heroine strength to be affected,
*		and set up different room experiences for my heroine.Also added random element for villain.
.
**		


*********************************************************************/

void Game::play()
{
	char menuChoice;

	do
		{
		if (!currentLocation->getVillainVanquished())
		{
			currentLocation->getDescription();//play description of current room before each menu appearance
		}
			//run the room menu
			menuChoice = currentLocation->menu();
			
			if (menuChoice == 'F')
			{
				//call the fightDanger function
				if (searchReticule("LIGHTED CANDLE")&& currentLocation != kitchen)
				{
					currentLocation->setIsIlluminated(true);
					std::cout << "Since JANE has a lighted candle, she can see to look around." << std::endl;
					std::cout << std::endl;
				}
				if (currentLocation == roof)//if heroine gets to roof, she needs to know if she has necessary rescue object
				{
					if(searchReticule("LOCKET"))
					{
						currentLocation->setHasLocket(true);
					}
					if (searchReticule("SIGNET RING"))
					{
						currentLocation->setHasSignetRing(true);
					}
					if (searchReticule("DAGGER"))
					{
						currentLocation->setHasDagger(true);
					}
					if (searchReticule("FLASK"))
					{
						currentLocation->setHasFlask(true);
					}
				}
				currentLocation->fightDanger(myHeroine);
				if (currentLocation->getGotItem()&& !searchReticule(currentLocation->getItem().getName()))
				{
					if (itemsCollected < MAX_OBJECTS)//only add items if there is room
					{
						reticule.add(currentLocation->getItem().getName());
						itemsCollected++;
					}
					else
					{
						std::cout << "RETICULE IS FULL - JANE MUST REMOVE SOMETHING BEFORE SHE CAN ADD ANYTHING." << std::endl;
						currentLocation->setGotItem(false);
					}
				}
				if (currentLocation->getVillainVanquished())//don't show menu again if heroine has won
				{
					isWinner = true;
				}
			}
			else if (menuChoice == 'S')
			{
				//call the searchRoom function
				if (searchReticule("LIGHTED CANDLE"))
				{
					currentLocation->setIsIlluminated(true);
					std::cout << "Since Jane has a lighted candle, she can see to look around." << std::endl;
				}

				currentLocation->searchRoom();

				
				if (currentLocation->getGotClue())
				{
					clues.add(currentLocation->getClue());//add clue if this is first time in room
					if ((currentLocation ==kitchen)&& !searchReticule("LIGHTED CANDLE"))
					{
						reticule.remove("CANDLE");
						reticule.add("LIGHTED CANDLE");
						currentLocation->setIsIlluminated(true);
					}
				}
			}
			else if (menuChoice == 'I')
			{	//manage objects and clues
				manageItems();
			}

			else if (menuChoice == 'M')//move to a new room
			{
				//run submenu to get choice of direction, adapt choices for attic, cellar, and roof
				if ((currentLocation->getName() != "ATTIC") && (currentLocation->getName() != "CELLAR") && (currentLocation->getName() != "ROOF"))
				{
					std::cout << "Where does JANE want to go?" << std::endl;
					std::cout << "1. Right to " << currentLocation->getRight()->getName() << "." << std::endl;
					std::cout << "2. Left to " << currentLocation->getLeft()->getName() << "." << std::endl;
					std::cout << "3. Down to " << currentLocation->getDownstairs()->getName() << "." << std::endl;
					std::cout << "4. Up to " << currentLocation->getUpstairs()->getName() << "." << std::endl;
					std::cout << std::endl;

					//input validation
					int choice = getAnInt("Enter choice:");

					while (choice < 1 || choice > 5)
						choice = getAnInt("Invalid choice. Enter a valid menu option:");

					std::cout << std::endl;

					if (choice == 1)
					{
						currentLocation = currentLocation->getRight();
					}
					else if (choice == 2)
					{
						currentLocation = currentLocation->getLeft();
					}
					else if (choice == 3)
					{
						currentLocation = currentLocation->getDownstairs();
					}
					else if (choice == 4)
					{
						currentLocation = currentLocation->getUpstairs();
					}
				}
				else if ((currentLocation->getName() == "ATTIC"))
				{
					//change room options:
					std::cout << "Where does JANE want to go?" << std::endl;
					std::cout << "1. Up to " << currentLocation->getUpstairs()->getName() << "." << std::endl;
					std::cout << "2. Down to " << currentLocation->getDownstairs()->getName() << "." << std::endl;
					std::cout << std::endl;


					//input validation
					int choice = getAnInt("Enter choice:");

					while (choice < 1 || choice > 3)
						choice = getAnInt("Invalid choice. Enter a valid menu option:");

					std::cout << std::endl;

					if (choice == 1)
					{
						currentLocation = currentLocation->getUpstairs();
					}
					else if (choice == 2)
					{
						currentLocation = currentLocation->getDownstairs();
					}
				}
				else if ((currentLocation->getName() == "CELLAR"))
				{
					//exit room options:
					std::cout << "Where does JANE want to go?" << std::endl;
					std::cout << "1. Up to " << currentLocation->getUpstairs()->getName() << "." << std::endl;
					std::cout << std::endl;

					//input validation
					int choice = getAnInt("Enter choice:");

					while (choice <1 || choice > 1)
						choice = getAnInt("Invalid choice. Enter a valid menu option:");

					std::cout << std::endl;

					if (choice == 1)
					{
						currentLocation = currentLocation->getUpstairs();
					}
					
				}
				else if ((currentLocation->getName() == "ROOF"))
				{
					//exit room options:
					std::cout << "Where does JANE want to go?" << std::endl;
					std::cout << "1. Down to " << currentLocation->getDownstairs()->getName() << "." << std::endl;
					std::cout << std::endl;

					//input validation
					int choice = getAnInt("Enter choice:");

					while (choice <1 || choice > 1)
						choice = getAnInt("Invalid choice. Enter a valid menu option:");

					std::cout << std::endl;

					if (choice == 1)
					{
						currentLocation = currentLocation->getDownstairs();
					}

				}
			}

			//after each menu option routine is run, check if Heroine has died
			if (myHeroine->getStrength() <=0)
			{
				std::cout << std::endl;
				std::cout << "All the adventure and battles have been too much! JANE is dying..." << std::endl;
				//revive Heroine if she is on first life
				if ((myHeroine->getIsFirstLife()) ||(searchReticule(currentLocation->getItem().getName())))
				{
					myHeroine->setStrength(12);
					std::cout << myHeroine->getName() << " has miraculously revived. But don't count on it happening again." << std::endl;
				}
				else//otherwise, she is dead and game is over
				{
					std::cout << myHeroine->getName() << "is dead, and all hope is gone for Lord Tarreyton." << std::endl;
					deadLord = true;
				}
				
			}

			//Lord Tarreyton is losing blood, decrease his strength by 1 each time menu loop runs
			lordLifeStrength=lordLifeStrength -1;

			//warn JANE that time is running out
			if (lordLifeStrength == 45 && !currentLocation->getVillainVanquished())
			{
				std::cout << std::endl;
				std::cout << "WARNING: NO TIME TO LOSE!" << std::endl;
				std::cout << std::endl;
				std::cout << "There are drops of blood on the ground..." << std::endl;
				std::cout << "JANE must hurry before Lord Tarreyton dies of blood loss!" << std::endl;
				
			}
			else if ((lordLifeStrength == 35 || lordLifeStrength == 25)&& ( !currentLocation->getVillainVanquished()))//more serious warning that heroine needs to hurry
			{
				std::cout << std::endl;
				std::cout << "WARNING: TIME IS RUNNING OUT!" << std::endl;
				std::cout << std::endl;
				std::cout << "Oh no, more bloodstains..." << std::endl;
				std::cout << "Hurry! If JANE doesn't find Lord Tarreyton soon, her wedding day will never be." << std::endl;
				
			}
			else if (lordLifeStrength <= 1 && !currentLocation->getVillainVanquished())//it's too late, heroine can't win before Lord T bleeds to death.
			{
				std::cout << std::endl;
				std::cout << "JANE hears a bloodcurdling scream and a maniacal laugh. It's too late! Her fiance is dead." << std::endl;;
				deadLord = true;
				
			}

		} while (menuChoice != 'Q' && !deadLord && !isWinner);

		//display the win or lose message depending on the outcome
		if (isWinner)
		{
			std::cout << std::endl;
			std::cout << "JANE has saved her fiance, but now she knows he is a terrible person. She is leaving this horrid  mansion." << std::endl;
			std::cout << "A true heroine can make her own fortune in the world." << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "GAME OVER" << std::endl;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "JANE failed to save Lord Tarreyton, and she is out of strength. At least she died fighting..." << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "GAME OVER" << std::endl;
		}
		
		//empty linked lists	
		reticule.clearList();
		discardedObjects.clearList();
		clues.clearList();


		//delete and free dynamically allocated memory
		delete guestroom;
		delete masterSuite;
		delete library;
		delete kitchen;
		delete cellar;
		delete attic;
		delete roof;

		delete myHeroine;
		

		myHeroine = nullptr;
		currentLocation = nullptr;

		guestroom = nullptr;
		kitchen = nullptr;
		library = nullptr;
		cellar = nullptr;
		masterSuite = nullptr;
		attic = nullptr;
		roof = nullptr;
		


	}

/*********************************************************************

**

**		Description: searchReticule()
.
**


*********************************************************************/
bool Game::searchReticule(std::string itemName)//check to see if item name input is already in reticule
{
	return reticule.searchList(itemName);
}

/*********************************************************************

**

**		Description: searchClues()
.
**


*********************************************************************/
bool Game::searchClues(std::string itemName)//check to see if item name input is already in reticule
{
	return clues.searchList(itemName);
}

/*********************************************************************

**

**		Description: manageItems()
.
**


*********************************************************************/
void Game::manageItems()
{
	std::cout << "1. View contents of reticule." << std::endl;
	std::cout << "2. Discard an item." << std::endl;
	std::cout << "3. View list of discarded items." << std::endl;
	std::cout << "4. View list of clues obtained." << std::endl;
	std::cout << "5. Exit this menu." << std::endl;
	std::cout << std::endl;

	//input validation
	int choice = getAnInt("Enter choice:");

	while (choice < 1 || choice > 5)
		choice = getAnInt("Invalid choice. Enter a valid menu option:");

	std::cout << std::endl;

	if (choice == 1)
	{
		//display items
		std::cout << std::endl;
		std::cout << "The items in JANE's reticule are:" << std::endl;
		std::cout << std::endl;
		reticule.displayList();
	}
	else if (choice == 2)
	{
		removeItem();
	}
	else if (choice == 3)
	{
		//display items
		std::cout << std::endl;
		std::cout << "The items JANE has discarded are:" << std::endl;
		std::cout << std::endl;
		discardedObjects.displayList();
		std::cout << std::endl;
		std::cout << "Too bad they are gone forever." << std::endl;
	}
	else if (choice == 4)
	{
		//display items
		std::cout << std::endl;
		std::cout << "The clues JANE has collected are:" << std::endl;
		std::cout << std::endl;
		clues.displayList();
	}

}

/*********************************************************************

**

**		Description: searchDiscardedItems()
.
**


*********************************************************************/
bool Game::searchDiscardedItems(std::string itemName)
{
	return discardedObjects.searchList(itemName);
}

/*********************************************************************

**

**		Description: removeItem()
.
**


*********************************************************************/
void Game::removeItem()
{
	//display list of objects in reticule
	std::cout << std::endl;
	std::cout << "The items in JANE's reticule are:" << std::endl;
	std::cout << std::endl;
	reticule.displayList();
	std::cout << std::endl;
	std::cout << "Which item would JANE like to remove?" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Enter item name in ALL CAPS." << std::endl;
	std::string deleteObjectName;
	std::cin.ignore();
	std::getline(std::cin, deleteObjectName);
	

	if (deleteObjectName == "CANDLE" || deleteObjectName == "LIGHTED CANDLE")
	{
		std::cout << "You'll need a candle to light  each room you visit!" << std::endl;
		std::cout << "This object does not count against limit of objects in reticule! Object not removed." << std::endl;
	}
	//don't let Heroine throw away an item that is needed for final showdown
	else if(deleteObjectName == "LOCKET" || deleteObjectName == "SIGNET RING"|| deleteObjectName == "DAGGER" || deleteObjectName == "FLASK")
	{
		std::cout << deleteObjectName << " will be needed to rescue Lord Tarreyton. Item not removed." << std::endl;
	}
		//if the item is not necessary to win, remove it and add it to the discardedObjects list
		else
		{
			bool itemFound = searchReticule(deleteObjectName);
			if (itemFound)
			{
				reticule.remove(deleteObjectName);
				discardedObjects.add(deleteObjectName);
				std::cout << "Item " << deleteObjectName << " has been removed." << std::endl;
				itemsCollected--;//increase capacity for reticule by 1
			}
			else
			{
				std::cout << "Object not found." << std::endl;
			}
		}
	}


/*********************************************************************

**

**		Description: ~Game()
.
**


*********************************************************************/
Game::~Game()
{
	
	

}