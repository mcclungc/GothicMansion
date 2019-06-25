/*************************************************************************************************************
**
**		Name:			Connie McClung

**
**		Description:	This is the item header file.
**
**
**
**************************************************************************************************************/

#ifndef ITEM_HPP 
#define ITEM_HPP
#include <string>

class Item
{
protected:
	//item properties
	std::string itemName;
	std::string description;

	//not sure if I will use these, creating just in case
	bool strengthens; //does this increases strength of being who obtains it?
	bool weakens;//does this cost strength points to obtain?
	bool isRequiredToWin; //is this required to win game?


public:
	Item() { itemName = ""; description = ""; strengthens = false;weakens = false; isRequiredToWin = false; };//constructor
	Item(std::string itemNameIn, std::string descriptionIn) { itemName = itemNameIn; description = descriptionIn; strengthens = false;weakens = false; isRequiredToWin = false; }
	~Item(){};//destructor
		
	//getter functions:
	std::string getName() const { return itemName; }
	std::string getDescription() const { return description; }
	
	//not sure if needed, just in case
	bool getStrengthens() const { return strengthens; }
	bool getWeakens() const { return weakens; }
	bool getIsRequiredToWin() const { return isRequiredToWin; }
	

	//setter functions:
	void setItemName(std::string nameIn) { itemName = nameIn; }
	void setDescription(std::string descriptionIn) { description = descriptionIn; }

	//not sure if needed, just in case
	void setStrengthens(bool valueIn) { strengthens = valueIn; }
	void setWeakens(bool valueIn) { weakens = valueIn; }
	void setIsRequiredToWin(bool valueIn) {	isRequiredToWin = valueIn;}

};

#endif
