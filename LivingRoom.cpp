#include "stdafx.h"

#include "LivingRoom.hpp"
#include "utils.hpp"


/********************************************************************************
** Function: LivingRoom
** Description: Class constructor
** Parameters: None
** Pre-Conditions: True
** Post-Conditions: +Class instance
** Return: N/A
*******************************************************************************/


LivingRoom::LivingRoom() 
{
	roomName = "LivingRoom";
	object1.setKeys(false);
	object2.setKeys(false);
	object1.setTrainTicketsLow(0);
	object1.setTrainTicketsHigh(0);
	object2.setTrainTicketsLow(0);
	object2.setTrainTicketsHigh(0);
	object1.setKeyLocation(false);
	object2.setKeyLocation(false);

}


/********************************************************************************
** Function: getObjectUpActionOpts
** Description: Virtual method to return unique string messages for subclass.
** Parameters: string objName- Name of Object class to match with message.
** Pre-Conditions: None
** Post-Conditions: None
** Return: String message
*******************************************************************************/


std::string LivingRoom::getObjectUpActionOpts(std::string objName)
{
	if (objName == "Sofa") { return "Look on the sofa."; }
	else if (objName == "TV") { return  "Look around the TV. "; }
	else if (objName == "Bookshelf") { return  "Look on top of the bookshelf."; }
	else if (objName == "Coffee Table") { return  "Look on top of the coffee table. "; }
}


/********************************************************************************
** Function: getObjectDownActionOpts
** Description: Virtual method to return unique string messages for subclass.
** Parameters: string objName- Name of Object class to match with message.
** Pre-Conditions: None
** Post-Conditions: None
** Return: String message
*******************************************************************************/


std::string LivingRoom::getObjectDownActionOpts(std::string objName)
{
	if (objName == "Sofa") { return "Look in the sofa cushions."; }
	else if (objName == "TV") { return  "Look in the TV stand. "; }
	else if (objName == "Bookshelf") { return  "Look on the book shelves."; }
	else if (objName == "Coffee Table") { return  "Look under the coffee table. "; }
}


/********************************************************************************
** Function: lookUnder
** Description: Virtual method for derived class to implement action on Object class
** Parameters: int objNum- Object number, std::string objName- nameID of Object
**	  int objType- Type of Object, Pocket &aPocket- Reference to Pocket class to modify
** Pre-Conditions: True
** Post-Conditions:
** Return: Integer parameter representing quantity of item in Object
*******************************************************************************/


int LivingRoom::lookUnder(int objNum, std::string objName, int objType, Pocket &aPocket)
{
	/*Randomly generate number for possibility finding extra train tickets*/
	int extraTickets = getRandomInteger(10); /*Number 0 to 10...20% chance*/

	/*Only add train tickets if there is enough room in your pocket*/
	if (extraTickets == 5 && ( (aPocket.getMoney() + aPocket.getTrainTickets() ) < 10 ) ) {
		
		std::cout << "What luck!! You found extra train tickets!!" << std::endl;
		/*Add 2 tickets to pocket*/
		aPocket.addTrainTixToPocket(2);
	}

	if (objType == 0) /*MONEY*/
	{
		if (objNum == 1)
		{
			if (!object1.getMoneyLocation())
				return object1.getMoney();
			else return 0;
		}
		else if (objNum == 2)
		{
			if (!object2.getMoneyLocation())
				return object2.getMoney();
			else return 0;
		}
	}
	if (objType == 1) /*TRAIN TICKETS*/
	{
		if (objNum == 1)
		{
			return object1.getTrainTicketsLow();
		}
		else if (objNum == 2)
		{
			return object2.getTrainTicketsLow();
		}
	}
}


/********************************************************************************
** Function: lookOnTop
** Description: Virtual method for derived class to implement action on Object class
** Parameters: int objNum- Object number, std::string objName- nameID of Object
**	  int objType- Type of Object, Pocket &aPocket- Reference to Pocket class to modify
** Pre-Conditions: True
** Post-Conditions:
** Return: Integer parameter representing quantity of item in Object
*******************************************************************************/


int LivingRoom::lookOnTop(int objNum, std::string objName, int objType, Pocket &aPocket)
{
	/*Randomly generate number for possibility finding extra train tickets*/
	int extraTickets = getRandomInteger(10); /*Number 0 to 10...20% chance*/

	/*Only add train tickets if there is enough room in your pocket*/
	if (extraTickets == 5 && ((aPocket.getMoney() + aPocket.getTrainTickets() ) < 10))
	{
		std::cout << "What luck!! You found extra train tickets!!" << std::endl;

		/*Add tickets to pocket*/
		aPocket.addTrainTixToPocket(2);
	}

	if (objType == 0) /*MONEY*/
	{
		if (objNum == 1)
		{
			if (object1.getMoneyLocation())
				return object1.getMoney();
			else return 0;
		}
		else if (objNum == 2)
		{
			if (object2.getMoneyLocation())
				return object2.getMoney();
			else return 0;
		}
	}
	if (objType == 1) /*TRAIN TICKETS*/
	{
		if (objNum == 1)
		{
			return object1.getTrainTicketsHigh();
		}
		else if (objNum == 2)
		{
			return object2.getTrainTicketsHigh();
		}
	}
}