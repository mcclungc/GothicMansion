/*********************************************************************

**		Author: Connie McClung

**

**		Description: Game.hpp
.
**		This is the Game class header file. It contains the member variables and member variable declarations
**

*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Attic.hpp"
#include "Cellar.hpp"
#include "Library.hpp"
#include "Kitchen.hpp"
#include "MasterSuite.hpp"
#include "GuestRoom.hpp"
#include "Roof.hpp"

#include "Heroine.hpp"
#include "Helpers.hpp"

#include "LinkedList.hpp"

#include <cstdlib> 
#include <ctime>   

//#include <vector>


class Game
{
private:
	
	//pointers to room objects to create the hous
	Room* guestroom = nullptr;
	Room* kitchen =nullptr;
	Room* library =nullptr;
	Room* cellar=nullptr;
	Room* masterSuite =nullptr;
	Room* attic = nullptr;
	Room* roof =nullptr;


	//heroine and properties
	Heroine* myHeroine;
	Room* currentLocation;     
	
	//use linked lists to store objects and clues, so I can remove from any position
	LinkedList<std::string> reticule;
	LinkedList<std::string> discardedObjects;
	LinkedList<std::string> clues;

	
	const int MAX_OBJECTS =5;//set limit for objects in reticule
	int itemsCollected;//set counter for objects obtained
	
	int lordLifeStrength; //to decrement as game progresses so game has time limti
	bool deadLord;//if Lord T is dead, Heroine is out of time                        
	bool isWinner;//if Heroine achieves game goal                    
	

public:
	Game();//constructor
	~Game();//destructor
	void gameIntro();
	void play();
	

	//functions to manage containers of objects and clues
	void manageItems();
	bool searchReticule(std::string itemName);
	bool searchClues(std::string itemName);
	bool searchDiscardedItems(std::string itemName);
	void removeItem();



	
};

#endif