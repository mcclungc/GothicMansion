/*********************************************************************

**		Author: Connie McClung

**

**		Description: LinkedList.hpp
.
**		Linked List template based on our textbook example p. 1056
**

*********************************************************************/
#include <iostream>
template <class T>
class LinkedList
{
protected:
	struct ListNode
	{
		T value;
		ListNode *next;
		ListNode(T value1, ListNode *next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};

	ListNode *front; //front pointer
public:
	LinkedList() { front = nullptr; } //constructor
	~LinkedList();
	void add(T value);
	void remove(T value);
	void displayList() const;
	bool searchList(T value);
	void clearList();

};
//
/*********************************************************************

**		Description: add()
.
**		Adds item to end of list

*********************************************************************/
template <class T>
void LinkedList<T>::add(T value)
{
	if (front == nullptr) //if list is empty
	{
		front = new ListNode(value);
		//std::cout << "address of front" << front << std::endl;
	}
	else
	{
		//if list is not empty use a pointer to traverse list
		ListNode *nodePtr = front;
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}
		//create a new node at end of list
		nodePtr->next = new ListNode(value);
		//std::cout << "address " << nodePtr->next << std::endl;
		//nodePtr = nullptr;
	}
	

}

/*********************************************************************

**		Description: searchList()
.
**		Determine if item is in list

*********************************************************************/
template<class T>
bool LinkedList<T>::searchList(T value)
{
	ListNode *nodePtr=nullptr, *previousNodePtr=nullptr;
	bool isFound = false;

	//if list is empty, nothing to remove
	if (!front)
	{
		isFound=false;
	}
	//if first node is the one that should be deleted
	if (front->value == value)
	{
		isFound = true;
	}
	else
	{
		//initialize nodePtr to be front of list
		nodePtr = front;

		//Skip the nodes whose values do not match the one to delete
		while (nodePtr != nullptr&& nodePtr->value != value)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		//link node preceding one to delete with the one after the one to delete
		if (nodePtr)
		{
			isFound = true;
		}
	}
	 
	nodePtr = nullptr;
	previousNodePtr = nullptr;
	return  isFound;
}
/*********************************************************************

**		Description: remove()
.
**		Remove specific value from list

*********************************************************************/
template<class T>
void LinkedList<T>::remove(T value)
{
	ListNode *nodePtr=nullptr, *previousNodePtr=nullptr;

	//if list is empty, nothing to remove
	if (!front) return;

	//if first node is the one that should be deleted
	if (front->value == value)
	{
		nodePtr = front;
		front = front->next;
		delete nodePtr;
	}
	else
	{
		//initialize nodePtr to be front of list
		nodePtr = front;

		//Skip the nodes whose values do not match the one to delete
		while (nodePtr != nullptr&& nodePtr->value != value)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		//link node preceding one to delete with the one after the one to delete
		if (nodePtr)
		{
			previousNodePtr->next = nodePtr->next;
			//std::cout << "address " << nodePtr << std::endl;
			delete nodePtr;
			//std::cout << "address " << nodePtr << std::endl;
		}
	}
	
	previousNodePtr = nullptr;
	nodePtr = nullptr;
}

/*********************************************************************

**		Description: displayList()
.
**		output a list of all the values currently stored in the list

*********************************************************************/
template <class T>
void LinkedList<T>::displayList() const
{
	ListNode *nodePtr = front;//set pointer to front of list
	int itemNum = 1;
	while(nodePtr)
	{
		//print value in current node
		std::cout <<itemNum<<". "<< nodePtr->value << std::endl;
		//move to next node
		nodePtr = nodePtr->next;
		itemNum++;
	}
	
	nodePtr = nullptr;
}

/*********************************************************************

**		Description: clearList()
.
**		delete all nodes in list

*********************************************************************/
template <class T>
void LinkedList<T>::clearList()
{
	ListNode *nodePtr = front; //start at front of list
							   //set garbage pointer for node to delete
	ListNode *garbage = nullptr;
	while (nodePtr != nullptr)
	{
		garbage = nodePtr;
		//move to next node
		nodePtr = nodePtr->next;
		//delete garbage node
		//std::cout << "address " << garbage << std::endl;
		delete garbage;
		//std::cout << "address " << garbage << std::endl;
	}
	delete nodePtr;
	garbage = nullptr;
	nodePtr = nullptr;

}

/*********************************************************************

**		Description: ~LinkedList()
.
**		destructor

*********************************************************************/
template <class T>
LinkedList<T>::~LinkedList()
{
	/*
	ListNode *nodePtr = front; //start at front of list
	while (nodePtr !=nullptr)
	{
		//set garbage pointer for node to delete
		ListNode *garbage = nodePtr;
		//move to next node
		nodePtr = nodePtr->next;
		//delete garbage node
		delete garbage;
	}
	
	nodePtr = nullptr;
	*/
}
