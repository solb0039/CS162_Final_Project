#include "stdafx.h"

#include "Kitchen.hpp"
#include "utils.hpp"


/********************************************************************************
** Function: Kitchen
** Description: Class constructor
** Parameters: None
** Pre-Conditions: True
** Post-Conditions: +Class instance
** Return: N/A
*******************************************************************************/


Kitchen::Kitchen() 
{
	roomName = "Kitchen";
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


std::string Kitchen::getObjectUpActionOpts(std::string objName)
{
	if (objName == "Table") { return "Look on top of the table."; }
	else if (objName == "Fridge") { return  "Look on top of the fridge. "; }
	else if (objName == "Counter") { return  "Look on the counter."; }
	else if (objName == "Cupboard") { return  "Look on the cupboard rack. "; }
}


/********************************************************************************
** Function: getObjectDownActionOpts
** Description: Virtual method to return unique string messages for subclass.
** Parameters: string objName- Name of Object class to match with message.
** Pre-Conditions: None
** Post-Conditions: None
** Return: String message
*******************************************************************************/


std::string Kitchen::getObjectDownActionOpts(std::string objName)
{
	if (objName == "Table") { return "Look under the table."; }
	else if (objName == "Fridge") { return  "Look inside the fridge. "; }
	else if (objName == "Counter") { return  "Look under the counter."; }
	else if (objName == "Cupboard") { return  "Look under the cupboard rack. "; }
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


int Kitchen::lookUnder(int objNum, std::string objName, int objType, Pocket &aPocket)
{
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


int Kitchen::lookOnTop(int objNum, std::string objName, int objType, Pocket &aPocket)
{
	/*Randomly generate number for possibility of falling asleep in the bed*/
	int messyKitchen = getRandomInteger(10); /*Number 0 to 5...20% chance*/
	if (messyKitchen == 5) {
		std::cout << "What a mess the kitchen! You can't find anything here and lost an extra 5 minutes"
			<< std::endl;
		aPocket.incrementTime(5);
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