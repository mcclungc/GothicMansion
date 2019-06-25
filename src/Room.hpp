/*************************************************************************************************************
**
**		Name:			Connie McClung
**
**		Description:	This is the room header file. Abstract base class for different rooms in the hours.
**
**
**
**************************************************************************************************************/

#ifndef ROOM_HPP 
#define ROOM_HPP

#include "Being.hpp"
#include "Item.hpp"
#include <string>


class Room
{

public:

	Room();//constructor
	virtual ~Room() = 0; //to make this an abstract class

	// virtual functions
	virtual char menu() = 0;
	virtual void searchRoom() = 0;
	virtual void fightDanger(Being *opponent);

	//getter functions

	//return room pointers
	Room* getRight() const;
	Room* getLeft() const;
	Room* getUpstairs() const;
	Room* getDownstairs() const;

	//return info about room and objects, clues inside it
	virtual void getDescription();
	std::string getName()const;
	Item getItem();
	std::string getClue();
	
	//return status variables
	bool getGotItem() const;
	bool getGotClue() const;
	//bool getEnemyActive() const;
	bool getVillainVanquished();


	//setter functions
	//set room connections and name
	void setDirection(char, Room*);
	void setName(std::string nameIn);
	
	//setter functions to change status after room has been illuminated and explored
	void setGotItem(bool valueIn) { this->gotItem = valueIn; }
	void setGotClue(bool valueIn) { this->gotClue = valueIn; }
	//void setEnemyActive(bool valueIn) { this->enemyActive = valueIn; }
	void setIsIlluminated(bool valueIn) { this->isIlluminated = valueIn; }

	//set status for required objects for final showdown
	void setHasDagger(bool valueIn) { hasDagger = valueIn; }
	void setHasFlask(bool valueIn) { hasFlask = valueIn; }
	void setHasLocket(bool valueIn) { hasLocket = valueIn; }
	void setHasSignetRing(bool valueIn) { hasSignetRing = valueIn; }


protected:
	//direction pointers to navigate from this room to next
	Room* right;
	Room* left;
	Room* upstairs;
	Room* downstairs;

	//danger, items, clues
	Being* enemy;
	Item item;
	std::string clue;


	//room properties
	std::string name;       //room name
	std::string description; //Short description of room layout
	bool gotItem;        //has the item been obtained 
	bool gotClue;		//has clue been obtained
	bool isIlluminated; //does the Heroine have a candle to light the room

	//bool variables to help final showdown logic
	bool hasDagger;
	bool hasFlask;
	bool hasSignetRing;
	bool hasLocket;
	bool villainVanquished;
	

private:




};

#endif