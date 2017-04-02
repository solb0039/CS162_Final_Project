#include "stdafx.h"

#include "Bedroom.hpp"
#include "utils.hpp"


/********************************************************************************
** Function: Bedroom
** Description: Class constructor
** Parameters: None
** Pre-Conditions: True
** Post-Conditions: +Class instance
** Return: N/A
*******************************************************************************/


Bedroom::Bedroom() 
{
	roomName = "Bedroom";
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


std::string Bedroom::getObjectUpActionOpts(std::string objName)
{
	if (objName == "Bed") { return "Look on top of the bed."; }
	else if (objName == "Nightstand") { return  "Look on the night stand. "; }
	else if (objName == "Closet") { return  "Look on the closet shelves."; }
	else if (objName == "Dresser") { return  "Look on top of the dresser. "; }
}


/********************************************************************************
** Function: getObjectDownActionOpts
** Description: Virtual method to return unique string messages for subclass.
** Parameters: string objName- Name of Object class to match with message.
** Pre-Conditions: None
** Post-Conditions: None
** Return: String message
*******************************************************************************/


std::string Bedroom::getObjectDownActionOpts(std::string objName)
{
	if (objName == "Bed") { return "Look under the bed."; }
	else if (objName == "Nightstand") { return  "Look in the nightstand drawers. "; }
	else if (objName == "Closet") { return  "Look on the closet foor."; }
	else if (objName == "Dresser") { return  "Look inside the dresser. "; }
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



int Bedroom::lookUnder(int objNum, std::string objName, int objType, Pocket &aPocket)
{
	/*Randomly generate number for possibility of falling asleep in the bed*/
	int fallAsleep = getRandomInteger(8)+1; /*Number 1 to 8...12% chance*/
	if (fallAsleep == 5) {
		std::cout << "The bed was so comfortable that you fell asleep and wasted a lot of time!"
			<< std::endl << std::endl;
		int timeWasted = getRandomInteger(20);
		std::cout << "You lost " << timeWasted << " minutes!!" << std::endl;
		aPocket.incrementTime(timeWasted);
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


int Bedroom::lookOnTop(int objNum, std::string objName, int objType, Pocket &aPocket)
{
	/*Randomly generate number for possibility of falling asleep in the bed*/
	int fallAsleep = getRandomInteger(8) + 1; /*Number 1 to 8...12% chance*/
	if (fallAsleep == 5) { 
		std::cout << "The bed was so comfortable that you fell asleep and wasted a lot of time!"
			<< std::endl << std::endl;

		int timeWasted = getRandomInteger(20);
		std::cout << "You lost " << timeWasted << " minutes!!" << std::endl;
		aPocket.incrementTime(timeWasted);
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