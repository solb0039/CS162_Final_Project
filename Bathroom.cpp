#include "stdafx.h"

#include "Bathroom.hpp"
#include "utils.hpp"


/********************************************************************************
** Function: Bathroom
** Description: Class constructor
** Parameters: None
** Pre-Conditions: True
** Post-Conditions: +Class instance
** Return: N/A
*******************************************************************************/


Bathroom::Bathroom() 
{
	roomName = "Bathroom";
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


std::string Bathroom::getObjectUpActionOpts(std::string objName) 
{
	if (objName == "Toilet") { return "Look on top of toilet."; }
	else if (objName == "Sink") { return  "Look on the sink counter. "; }
	else if (objName == "Garbage") { return  "Look around garbage can."; }
	else if (objName == "Cabinet") { return  "Look on top of cabinet. "; }
}


/********************************************************************************
** Function: getObjectDownActionOpts
** Description: Virtual method to return unique string messages for subclass.
** Parameters: string objName- Name of Object class to match with message.
** Pre-Conditions: None
** Post-Conditions: None
** Return: String message
*******************************************************************************/


std::string Bathroom::getObjectDownActionOpts(std::string objName)
{
	if (objName == "Toilet") { return "Look behind toilet bowl."; }
	else if (objName == "Sink") { return  "Look under the sink. "; }
	else if (objName == "Garbage") { return  "Look inside the garbage."; }
	else if (objName == "Cabinet") { return  "Look inside the cabinets. "; }
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


int Bathroom::lookUnder(int objNum, std::string objName, int objType, Pocket &aPocket)
{
	/*Randomly generate number for possibility of slipping and dropping moeny*/
	int slip = getRandomInteger(6); /*Number 0 to 6...16% chance*/
	if (slip == 5) {
		std::cout << "Opps!! You slipped on the bathroom floor and dropped some money"
			<< std::endl;

		/*Get a random amount of money, with the max being 1/2 of what in your pocket*/
		int droppedMoney = getRandomInteger( aPocket.getMoney() + 1 );
		aPocket.removeMoneyFromPocket( droppedMoney/2  );
	}

	if (objType == 0) /*MONEY*/
	{
		/*Object 1*/
		if (objNum == 1)
		{
			if (object1.getMoneyLocation() == 0) /*under/inside*/
			{
				return object1.getMoney();
			}
			else return 0;
		}
		else if (objNum == 2)
		{
			if (object2.getMoneyLocation() == 0)
			{
				return object2.getMoney();
			}
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


int Bathroom::lookOnTop(int objNum, std::string objName, int objType, Pocket &aPocket)
{
	/*Randomly generate number for possibility of slipping and dropping moeny*/
	int slip = getRandomInteger(6); /*Number 0 to 5...XX% chance*/
	if (slip == 5) {
		std::cout << "Opps!! You slipped on the bathroom floor and dropped some money"
			<< std::endl;
		/*Get a random amount of money, with the max being 1/2 of what in your pocket*/
		int droppedMoney = getRandomInteger(aPocket.getMoney()+1);
		aPocket.removeMoneyFromPocket(droppedMoney / 2);
	}

	if (objType == 0) /*MONEY*/
	{
		if (objNum == 1)
		{
			if (object1.getMoneyLocation() == 1)
				return object1.getMoney();
			else return 0;
		}
		else if (objNum == 2)
		{
			if (object2.getMoneyLocation() == 1)
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