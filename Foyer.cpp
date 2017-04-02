#include "stdafx.h"

#include "Foyer.hpp"


/********************************************************************************
** Function: Foyer
** Description: Class constructor
** Parameters: None
** Pre-Conditions: True
** Post-Conditions: +Class instance
** Return: N/A
*******************************************************************************/


Foyer::Foyer()
{
	roomName = "Foyer";
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


std::string Foyer::getObjectUpActionOpts(std::string objName)
{
	if (objName == "ShoeRack") { return "Look on the shoe rack."; }
	else if (objName == "KeyRack") { return  "Look on the key rack. "; }
	else if (objName == "MailRack") { return  "Look on the mail rack."; }
	else if (objName == "Stand") { return  "Look on the stand. "; }
}


/********************************************************************************
** Function: getObjectDownActionOpts
** Description: Virtual method to return unique string messages for subclass.
** Parameters: string objName- Name of Object class to match with message.
** Pre-Conditions: None
** Post-Conditions: None
** Return: String message
*******************************************************************************/


std::string Foyer::getObjectDownActionOpts(std::string objName)
{
	if (objName == "ShoeRack") { return "Look behind the shoe rack."; }
	else if (objName == "KeyRack") { return  "Look insde the key rack drawer. "; }
	else if (objName == "MailRack") { return  "Look in the mail slots."; }
	else if (objName == "Stand") { return  "Look behind the stand. "; }
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


int Foyer::lookUnder(int objNum, std::string objName, int objType, Pocket &aPocket)
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
			return object1.getTrainTicketsLow();
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


int Foyer::lookOnTop(int objNum, std::string objName, int objType, Pocket &aPocket)
{
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
			return object1.getTrainTicketsHigh();
		}
	}
}