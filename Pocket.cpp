#include "stdafx.h"

#include "Pocket.hpp"
#include <iostream>
#include "utils.hpp"


/********************************************************************************
** Function: Pocket
** Description: Class constructor
** Parameters: None
** Pre-Conditions: True
** Post-Conditions: +Class instance
** Return: N/A
*******************************************************************************/


Pocket::Pocket()
{
	money = 0;
	trainTickets = 0;
	time = 0;
	timeLimit = 20;
	moneyNeeded = 20;
	trainTicketsNeeded = 4;
}

/********************************************************************************
** Function: pocketChoices
** Description: Function to display options to user and get input.
** Parameters: None
** Pre-Conditions: True
** Post-Conditions: None
** Return: Integer option 
*******************************************************************************/


int Pocket::pocketChoices() 
{
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "1. Pick up money?" << std::endl;
	std::cout << "2. Pick up train tickets?" << std::endl << std::endl;
	std::cout << "3. Empty pockets of money" << std::endl;
	std::cout << "4. Empty pockets of tickets" << std::endl << std::endl;
	std::cout << "5. Check your pockets" << std::endl;
	std::cout << "6. Do nothing" << std::endl << std::endl;

	return getInteger("Select your choice:", 1, 6);
}


/********************************************************************************
** Function: lookInPocket
** Description: Display values of Pocket member variables. Aslo, changes time 
**		variable and randomly changes money variables.
** Parameters: None
** Pre-Conditions: True
** Post-Conditions: 
** Return: Void
*******************************************************************************/


void Pocket::lookInPocket() 
{
	std::cout << "Contents of you pocket:" << std::endl;
	std::cout << money << " cents" << std::endl;
	std::cout << trainTickets << " train tickets" << std::endl << std::endl;

	/*Checking pockets wastes time*/
	incrementTime(1);

	/*Random probability that money is already in your pocket.*/
	int checkPockets = getRandomInteger(10);
	
	if (checkPockets == 1) 
	{
		int moneyToAdd = getRandomInteger(10);
		std::cout << "You found " << moneyToAdd << " cents extra in your pockets!!!" << std::endl;
		addMoneyToPocket(moneyToAdd);
	}

}



/********************************************************************************
** Function: addMoneyToPocket
** Description: Mutator method for money member variable. Also enforces restrictions
**			on sum of money + trainTickets.
** Parameters: int newMoney- Quantity to add to money variable.
** Pre-Conditions: True
** Post-Conditions: None
** Return: Void
*******************************************************************************/


void Pocket::addMoneyToPocket(int newMoney) 
{ 
	/*If your pockets have mixed contents, then restrict total quantity*/
	if (money && trainTickets)
	{
		if (money + trainTickets >= 15)
		{
			std::cout << std::endl;
			std::cout << "You don't have enough room in your pockets!!  Remove some items first!" << std::endl;
			std::cout << "Press ENTER to continue....." << std::endl << std::endl;
			std::cin.ignore(1);
		}
		else
		{
			money += newMoney;
		}
	}
	else /*If pockets are only one object then allow any quantity */
	{
		money += newMoney;
	}
}