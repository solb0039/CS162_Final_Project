#include "stdafx.h"

#include "RoomListNode.hpp"

/********************************************************************************
** Function: RoomListNode
** Description: Class constructor
** Parameters: None
** Pre-Conditions: True
** Post-Conditions: +Class instance
** Return: N/A
*******************************************************************************/


RoomListNode::RoomListNode() 
{ 
	home = NULL;
	numBathrooms = 0;
	numBedrooms = 0;
	numLivingRooms = 0;
	numKitchens = 0;
}



/********************************************************************************
** Function: addRoom
** Description: Overloaded method to add derived class of Room to roomListNode
** Parameters: Bedroom* aBdrm- Pointer to derived class, int ID- Parameter to set
**		to roomID parameter.
** Pre-Conditions: roomListNode true
** Post-Conditions: +Room class in roomListNode
** Return: Void
*******************************************************************************/


void RoomListNode::addRoom(Bedroom* aBdrm, int ID) {

	if (home == NULL) 
	{
		home = new roomNode(aBdrm, ID);
	}
	else
	{
		roomNode *nodePtr = home;
		while (nodePtr->next != NULL)
			nodePtr = nodePtr->next;

		nodePtr->next = new roomNode(aBdrm, ID);
	
	}
	numBedrooms++;
}


/********************************************************************************
** Function: addRoom
** Description: Overloaded method to add derived class of Room to roomListNode
** Parameters: Foyer* aFoyer- Pointer to derived class, int ID- Parameter to set
**		to roomID parameter.
** Pre-Conditions: roomListNode true
** Post-Conditions: +Room class in roomListNode
** Return: Void
*******************************************************************************/


void RoomListNode::addRoom(Foyer* aFoyer, int ID) {

	if (home == NULL)
	{
		home = new roomNode(aFoyer, ID);
	}
	else
	{
		roomNode *nodePtr = home;
		while (nodePtr->next != NULL)
			nodePtr = nodePtr->next;

		nodePtr->next = new roomNode(aFoyer, ID);

	}
	numBedrooms++;
}


/********************************************************************************
** Function: addRoom
** Description: Overloaded method to add derived class of Room to roomListNode
** Parameters: Kitchen* aKitchen- Pointer to derived class, int ID- Parameter to set
**		to roomID parameter.
** Pre-Conditions: roomListNode true
** Post-Conditions: +Room class in roomListNode
** Return: Void
*******************************************************************************/


void RoomListNode::addRoom(Kitchen* aKitchen, int ID) {

	if (home == NULL)
	{
		home = new roomNode(aKitchen, ID);
	}
	else
	{
		roomNode *nodePtr = home;
		while (nodePtr->next != NULL)
			nodePtr = nodePtr->next;

		nodePtr->next = new roomNode(aKitchen, ID);
	}

	numKitchens++;
}


/********************************************************************************
** Function: addRoom
** Description: Overloaded method to add derived class of Room to roomListNode
** Parameters: LivingRoom* aLR- Pointer to derived class, int ID- Parameter to set
**		to roomID parameter.
** Pre-Conditions: roomListNode true
** Post-Conditions: +Room class in roomListNode
** Return: Void
*******************************************************************************/


void RoomListNode::addRoom(LivingRoom* aLR, int ID) {

	if (home == NULL)
	{
		home = new roomNode(aLR, ID);
	}
	else
	{
		roomNode *nodePtr = home;
		while (nodePtr->next != NULL)
			nodePtr = nodePtr->next;

		nodePtr->next = new roomNode(aLR, ID);

	}

	numLivingRooms++;
}


/********************************************************************************
** Function: addRoom
** Description: Overloaded method to add derived class of Room to roomListNode
** Parameters: Bathroom* aBR- Pointer to derived class, int ID- Parameter to set
**		to roomID parameter.
** Pre-Conditions: roomListNode true
** Post-Conditions: +Room class in roomListNode
** Return: Void
*******************************************************************************/


void RoomListNode::addRoom(Bathroom* aBR, int ID) {

	if (home == NULL)
	{
		home = new roomNode(aBR, ID);
	}
	else
	{
		roomNode *nodePtr = home;
		while (nodePtr->next != NULL)
			nodePtr = nodePtr->next;

		nodePtr->next = new roomNode(aBR, ID);

	}

	numBathrooms++;
}


/********************************************************************************
** Function: getRoomAtRoomID
** Description: Function matches ID parameter to roomListNode.
** Parameters: int ID- roomID to match to roomListNode instance
** Pre-Conditions: RoomListNode true
** Post-Conditions: None
** Return: roomNode* pointer that matches ID parameter
*******************************************************************************/


RoomListNode::roomNode* RoomListNode::getRoomAtRoomID(int ID) 
{
	roomNode *roomPtr = home;

	if (ID == 0)
		return NULL;
	
	else {
		while (roomPtr->roomID != ID)
			roomPtr = roomPtr->next;

		return roomPtr;
	}
}


/********************************************************************************
** Function: canMoveUp
** Description: Method to check if roomNode at Up pointer is NULL or not.
** Parameters: roomNode* aNode- Node to check if NULL
** Pre-Conditions: None
** Post-Conditions: None
** Return: True if aNode is not NULL, false otherwise
*******************************************************************************/


bool RoomListNode::canMoveUp(roomNode* aNode) 
{
	if (aNode->up != NULL) return true;
	else return false;
}


/********************************************************************************
** Function: canMoveDown
** Description: Method to check if roomNode at Down pointer is NULL or not.
** Parameters: roomNode* aNode- Node to check if NULL
** Pre-Conditions: None
** Post-Conditions: None
** Return: True if aNode is not NULL, false otherwise
*******************************************************************************/


bool RoomListNode::canMoveDown(roomNode* aNode)
{
	if (aNode->down != NULL) return true;
	else return false;
}


/********************************************************************************
** Function: canMoveRight
** Description: Method to check if roomNode at Right pointer is NULL or not.
** Parameters: roomNode* aNode- Node to check if NULL
** Pre-Conditions: None
** Post-Conditions: None
** Return: True if aNode is not NULL, false otherwise
*******************************************************************************/


bool RoomListNode::canMoveRight(roomNode* aNode)
{
	if (aNode->right != NULL) return true;
	else return false;
}


/********************************************************************************
** Function: canMoveUp
** Description: Method to check if roomNode at Left pointer is NULL or not.
** Parameters: roomNode* aNode- Node to check if NULL
** Pre-Conditions: None
** Post-Conditions: None
** Return: True if aNode is not NULL, false otherwise
*******************************************************************************/


bool RoomListNode::canMoveLeft(roomNode* aNode)
{
	if (aNode->left != NULL) return true;
	else return false;
}


/********************************************************************************
** Function: moveUp
** Description: Resets playerLocation pointer in roomListNode to location of Up pointer 
** Parameters: roomNode* aNode- roomNode* of current pointer to be moved.
** Pre-Conditions: roomNode parameter is not NULL. 
** Post-Conditions: None
** Return: Voide
*******************************************************************************/


void RoomListNode::moveUp(roomNode* aNode) 
{
	playerLocation = aNode->up;
}


/********************************************************************************
** Function: moveDown
** Description: Resets playerLocation pointer in roomListNode to location of Down pointer
** Parameters: roomNode* aNode- roomNode* of current pointer to be moved.
** Pre-Conditions: roomNode parameter is not NULL.
** Post-Conditions: None
** Return: Void
*******************************************************************************/


void RoomListNode::moveDown(roomNode* aNode) 
{
	playerLocation = aNode->down;
}


/********************************************************************************
** Function: moveRight
** Description: Resets playerLocation pointer in roomListNode to location of Right pointer
** Parameters: roomNode* aNode- roomNode* of current pointer to be moved.
** Pre-Conditions: roomNode parameter is not NULL.
** Post-Conditions: None
** Return: Void
*******************************************************************************/


void RoomListNode::moveRight(roomNode* aNode) 
{
	playerLocation = aNode->right;
}


/********************************************************************************
** Function: moveLeft
** Description: Resets playerLocation pointer in roomListNode to location of Left pointer
** Parameters: roomNode* aNode- roomNode* of current pointer to be moved.
** Pre-Conditions: roomNode parameter is not NULL.
** Post-Conditions: None
** Return: Voide
*******************************************************************************/


void RoomListNode::moveLeft(roomNode* aNode) 
{
	playerLocation = aNode->left;
}



/********************************************************************************
** Function: ~RoomListNode
** Description: Class destructor. Deletes all instances of Room Objects and roomNodes
** Parameters: None
** Pre-Conditions: True
** Post-Conditions: - all instances of nodes and Room objects in nodes
** Return: N/A
*******************************************************************************/


RoomListNode::~RoomListNode() 
{
	roomNode *roomPtr = home;

	while (roomPtr != NULL)
	{
		/*Extra node to follow behind*/
		roomNode *lagPtr = roomPtr;
		
		/*Step ahead room ptr*/
		roomPtr = roomPtr->next;
		
		/*Delete previous node*/
		delete lagPtr->aRoom;
		delete lagPtr;
	}
	
}