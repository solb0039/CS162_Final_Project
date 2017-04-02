#include "stdafx.h"

#include "Room.hpp"


/********************************************************************************
** Function: incrementObjectTrainTickets
** Description: Method to access and mutate member variables in Object Class
** Parameters: int object- Object number, int highLow- Position of item in Object
** Pre-Conditions: True
** Post-Conditions: None
** Return: Void
*******************************************************************************/


void Room::incrementObjectTrainTickets(int object, int highLow)
{
	if (object == 1)
	{
		if (highLow == 0) { object1.incrementTrainTicketsLow(); } /*Low*/
		else { object1.incrementTrainTicketsHigh(); }
	}
	else if (object == 2)
	{
		if (highLow == 1) { object2.incrementTrainTicketsLow(); } /*High*/
		else { object2.incrementTrainTicketsHigh(); }
	}
}


/********************************************************************************
** Function: getObjectTrainTickets
** Description: Method to access member variables in Object Class
** Parameters: int object- Object number, int highLow- Position of item in Object
** Pre-Conditions: True
** Post-Conditions: None
** Return: Integer of the number of Items in Object
*******************************************************************************/


int Room::getObjectTrainTickets(int object, int highLow)
{
	if (object == 1)
	{
		if (highLow == 0) { return object1.getTrainTicketsLow(); } /*Low*/
		else { return object1.getTrainTicketsHigh(); }
	}
	else if (object == 2)
	{
		if (highLow == 1) { return object2.getTrainTicketsLow(); } /*High*/
		else { return object2.getTrainTicketsHigh(); }
	}
}


/********************************************************************************
** Function: setObjectTrainTickets
** Description: Method to access and mutate member variables in Object Class
** Parameters: int object- Object number, int highLow- Position of item in Object
**			int value- Number of items to add to Object
** Pre-Conditions: True
** Post-Conditions: None
** Return: Void
*******************************************************************************/


void Room::setObjectTrainTickets(int object, int highLow, int value)
{
	if (object == 1)
	{
		if (highLow == 0) { object1.setTrainTicketsLow(value); } /*Low*/
		else { object1.setTrainTicketsHigh(value); }
	}
	else if (object == 2)
	{
		if (highLow == 1) { object2.setTrainTicketsLow(value); } /*High*/
		else { object2.setTrainTicketsHigh(value); }
	}
}