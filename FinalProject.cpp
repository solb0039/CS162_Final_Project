
#include "stdafx.h"

/***************************************************************************  
** Program Filename:  FinalProject.cpp
** Author:   Sean Solberg
** Date:  6-December-2016
** Description: Program is a game where the user is looking to find keys in 
**		their apartment.
** Input:  Player choices
** Output:  Game responses
***************************************************************************/

#include "Bedroom.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "Bathroom.hpp"
#include "Foyer.hpp"
#include "Room.hpp"
#include "RoomListNode.hpp"
#include "utils.hpp"
#include <iomanip>
#include "Pocket.hpp"
#include <cstddef>

/*Function prototypes*/
void displayApartment(RoomListNode &apartment);
void linkRooms(RoomListNode &myApartment);
int getUserMovement();
void displayBoard();
void setObject(int randomInt, int randomObjInt, int randomLocInt, RoomListNode &anApartment, int type);
void pocketAction(int pocketChoice, int money, int tickets, RoomListNode &anApartment, int object, int highLow, Pocket &aPocket);
void createApartment(RoomListNode &apartment);
void displayInstructions();

/*Program enums and constants*/
enum BATHROOM_OBJECTS {Toilet, Sink, Garbage, Cabinet};
const std::string BATHROOM_OBJ_NAMES[4] = {"Toilet", "Sink", "Garbage", "Cabinet"};
enum LIVINGROOM_OBJECTS {Sofa, TV, Bookshelf, CoffeeTable};
const std::string LIVINGROOM_OBJ_NAMES[4] = {"Sofa", "TV", "Bookshelf", "Coffee Table"};
enum BEDROOM_OBJECTS {Bed, Nightstand, Closet, Dresser};
const std::string BEDROOM_OBJ_NAMES[4] = { "Bed", "Nightstand", "Closet", "Dresser" };
enum KITCHEN_OBJECTS {Table, Fridge, Counter, Cupboard};
const std::string KITCHEN_OBJ_NAMES[4] = { "Table", "Fridge", "Counter", "Cupboard" };
enum FOYER_OBJECTS {ShoeRack, KeyRack, MailRack, Stand };
const std::string FOYER_OBJ_NAMES[4] = { "ShoeRack", "KeyRack", "MailRack", "Stand" };


int main()
{
	bool foundKeys = false;
	Pocket myPocket;

	/*Seed random number generator for use in program*/
	unsigned seed;
	seed = time(0);
	srand(seed);

	/*Creature instance of RoomListNode object*/
	RoomListNode myApartment;

	/*Populate the rooms with objects and hide money and keys*/
	createApartment(myApartment);

	/*Link all the rooms together to create the apartment*/
	linkRooms(myApartment);

	/*Print user instructions*/
	displayInstructions();
	system("CLS"); /*system("clear); cout << "\033[2J\033[1;1H";*/
	
	/*Print apartment layout*/
	displayApartment(myApartment);
	
	/*Variable to get user movement*/
	int movement;

	/*Display options and get user choice*/
	std::cout << "Currently you are in the " <<
		myApartment.getRoomName(myApartment.getRoomAtPlayerLocation()) << std::endl << std::endl;

	movement = getUserMovement();
	system("CLS"); /*system("clear); cout << "\033[2J\033[1;1H";*/

	/*Main loop*/
	while ( (movement != 7) && (myPocket.getMoney() < myPocket.getMoneyNeeded() ) && (myPocket.getTime() < myPocket.getTimeLimit() ) && (foundKeys == false) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded() ) )
	{
		switch (movement)
		{
		case 1: /*Move Up*/
		{
			if (myApartment.canMoveUp(myApartment.getRoomAtPlayerLocation()))
			{
				myApartment.moveUp(myApartment.getRoomAtPlayerLocation());
			}
			else
				std::cout << "Hit a wall!" << std::endl << std::endl;;
		}
			break;
		case 2: /*Move Down*/
		{
			if (myApartment.canMoveDown(myApartment.getRoomAtPlayerLocation()))
			{
				myApartment.moveDown(myApartment.getRoomAtPlayerLocation());
			}
			else
				std::cout << "Hit a wall!" << std::endl << std::endl;;
		}
			break;
		case 3: /*Move Right*/
		{
			if (myApartment.canMoveRight(myApartment.getRoomAtPlayerLocation()))
			{
				myApartment.moveRight(myApartment.getRoomAtPlayerLocation());
			}
			else
				std::cout << "Hit a wall!" << std::endl << std::endl;;
		}
			break;
		case 4: /*Move Left*/
		{
			if (myApartment.canMoveLeft(myApartment.getRoomAtPlayerLocation()))
			{
				myApartment.moveLeft(myApartment.getRoomAtPlayerLocation());
			}
			else
				std::cout << "Hit a wall!" << std::endl << std::endl;;
		}
			break;
		case 5: /*Enter room*/
		{
			system("CLS"); 
			/*cout << "\033[2J\033[1;1H";*/

			Room* roomPtr;
			roomPtr = myApartment.getRoomAtPlayerLocation()->aRoom;

			std::cout << "The time is " << myPocket.getTime() << " minutes past the hour. " << std::endl << std::endl;
			std::cout << "You are in the " << myApartment.getRoomName(myApartment.getRoomAtPlayerLocation()) << std::endl << std::endl;
			std::cout << "In the " << myApartment.getRoomName(myApartment.getRoomAtPlayerLocation()) <<
				" there is a " << roomPtr->getObject1Name() << " and a " << roomPtr->getObject2Name()
				<< std::endl;

			int roomChoice;
			std::cout << "1. Look at " << roomPtr->getObject1Name() << std::endl;
			std::cout << "2. Look at " << roomPtr->getObject2Name() << std::endl << std::endl;
			std::cout << "3. Leave room" << std::endl << std::endl;
			roomChoice = getInteger("What would you like to do?", 1, 3);
			
			system("CLS"); 
			/*cout << "\033[2J\033[1;1H";*/
			
			int actionChoice;
			
			/*Inner loop to check for player interaction with object*/
			while ((roomChoice != 3) && (foundKeys == false) && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()) )
			{
				/*Object 1*/
				if ( (roomChoice == 1) && (foundKeys == false) && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()))
				{
					/*Display options*/
					std::cout << std::endl;
					std::cout << "What would you like to do with the " << roomPtr->getObject1Name() << "?" << std::endl << std::endl;
					std::cout << "1." << roomPtr->getObjectDownActionOpts( roomPtr->getObject1Name() ) << std::endl;
					std::cout << "2." << roomPtr->getObjectUpActionOpts( roomPtr->getObject1Name() ) << std::endl << std::endl;
					std::cout << "3. Do nothing" << std::endl << std::endl;
					actionChoice = getInteger("Choose an option.", 1, 3);

					system("CLS"); 
					/*cout << "\033[2J\033[1;1H";*/

					/*Inner-inner loop to handle player interaction with selected object*/
					while ((actionChoice != 3) && (foundKeys == false) && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()))
					{
						/*Look UNDER/BEHIND/INSIDE the object*/
						if ((actionChoice == 1) && (foundKeys == false) && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()))
						{ 
							/*If keys found, then end, else look for money*/
							if (roomPtr->getObject1Keys() && !roomPtr->getObject1KeysLocation() ) 
							{ 
								foundKeys = true; 
							}
							else /*Money or train tickets*/
							{
								/*Check for money*/		
								int money = roomPtr->lookUnder(1, roomPtr->getObject1Name(), 0, myPocket);
								std::cout << "There is " << money << " cents in the " <<
									roomPtr->getObject1Name() << std::endl << std::endl;
								
								/*Check for tickets*/  /*0 is MONEY, 1 is train*/
								int tickets = roomPtr->lookUnder(1, roomPtr->getObject1Name(), 1, myPocket);
								std::cout << "There is " << tickets << " train tickets in the " <<
									roomPtr->getObject1Name() << std::endl << std::endl;

								/*Decide what to put into pocket*/
								/*1- Put money, 2-Put tickets, 3-Take out money, 4-Take out tickets*/
								int pocketChoice = myPocket.pocketChoices();
								
								/*object =1, highLow = 0*/
								pocketAction(pocketChoice, money, tickets, myApartment, 1, 0, myPocket);

							}
						}
						/*Look above or on top of object*/
						else if ((actionChoice == 2) && (foundKeys == false) && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()))
						{ 
							/*If keys found, then end, else look for money*/
							if (roomPtr->getObject1Keys() && roomPtr->getObject1KeysLocation() )
							{ 
								foundKeys = true; 
							}
							else /*Money or train tickets*/
							{
								int money = roomPtr->lookOnTop(1, roomPtr->getObject1Name(), 0, myPocket);
								std::cout << "There is " << money << " cents in the " <<
									roomPtr->getObject1Name() << std::endl << std::endl;

								/*Check for tickets*/  
								int tickets = roomPtr->lookOnTop(1, roomPtr->getObject1Name(), 1, myPocket);
								std::cout << "There is " << tickets << " train tickets in the " <<
									roomPtr->getObject1Name() << std::endl << std::endl;

								/*Decide what to put into pocket*/
								/*1- Put money, 2-Put tickets, 3-Take out money, 4-Take out tickets*/
								int pocketChoice = myPocket.pocketChoices();

								/*object =1, highLow = 1*/
								pocketAction(pocketChoice, money, tickets, myApartment, 1, 1, myPocket);

							}
						}
						if (!foundKeys && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()))
						{
							/*Display options again*/
							std::cout << "What would you like to do with the " << roomPtr->getObject1Name() << "?" << std::endl << std::endl;
							std::cout << "1." << roomPtr->getObjectDownActionOpts(roomPtr->getObject1Name()) << std::endl;
							std::cout << "2." << roomPtr->getObjectUpActionOpts(roomPtr->getObject1Name()) << std::endl << std::endl;
							std::cout << "3. Do nothing" << std::endl << std::endl;
							actionChoice = getInteger("Choose an option.", 1, 3);

							system("CLS"); 
							/*cout << "\033[2J\033[1;1H";*/
						}
					} 
				}
				/*Object 2. (This is repetitive code and could be simplified into one function)*/
				else if ( (roomChoice == 2) && (foundKeys == false) && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()))
				{
					/*Display options*/
					std::cout << std::endl;
					std::cout << "What would you like to do with the " << roomPtr->getObject2Name() << "?" << std::endl << std::endl;
					std::cout << "1." << roomPtr->getObjectDownActionOpts(roomPtr->getObject2Name()) << std::endl;
					std::cout << "2." << roomPtr->getObjectUpActionOpts(roomPtr->getObject2Name()) << std::endl << std::endl;
					std::cout << "3. Do nothing" << std::endl << std::endl;
					actionChoice = getInteger("Choose an option.", 1, 3);

					system("CLS"); 
					/*cout << "\033[2J\033[1;1H";*/

					while ((actionChoice != 3) && (foundKeys == false) && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()) )
					{
						/*Look under*/
						if ((actionChoice == 1) && (foundKeys == false) && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()))
						{
							/*If keys found, then end, else look for money*/
							if ( roomPtr->getObject2Keys() && !roomPtr->getObject2KeysLocation() )
							{ 
								foundKeys = true; 
							}
							else
							{
								/*Money*/
								int money = roomPtr->lookUnder(2, roomPtr->getObject2Name(), 0, myPocket );
								std::cout << "There is " << money << " cents in the " <<
									roomPtr->getObject1Name() << std::endl << std::endl;

								/*Tickets*/
								int tickets = roomPtr->lookUnder(2, roomPtr->getObject1Name(), 1, myPocket);
								std::cout << "There is " << tickets << " train tickets in the " <<
									roomPtr->getObject1Name() << std::endl << std::endl;

								/*Decide what to put into pocket*/
								/*1- Put money, 2-Put tickets, 3-Take out money, 4-Take out tickets*/
								int pocketChoice = myPocket.pocketChoices();

								/*object =2, highLow = 0*/
								pocketAction(pocketChoice, money, tickets, myApartment, 2, 0, myPocket);

							}
						}
						/*Look above*/
						else if ((actionChoice == 2) && (foundKeys == false) && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()))
						{
							/*If keys found, then end, else look for money*/
							if (roomPtr->getObject2Keys() && roomPtr->getObject2KeysLocation())
							{ 
								foundKeys = true; 
							}
							else
							{
								/*Money*/
								int money = roomPtr->lookOnTop(2, roomPtr->getObject2Name(), 0, myPocket);
							
								std::cout << "There is " << money << " cents in the " <<
									roomPtr->getObject1Name() << std::endl << std::endl;

								/*Tickets*/
								int tickets = roomPtr->lookOnTop(2, roomPtr->getObject1Name(), 1, myPocket);
								std::cout << "There is " << tickets << " train tickets in the " <<
									roomPtr->getObject1Name() << std::endl << std::endl;

								/*Decide what to put into pocket*/
								/*1- Put money, 2-Put tickets, 3-Take out money, 4-Take out tickets*/
								int pocketChoice = myPocket.pocketChoices();

								/*object =2, highLow = 1*/
								pocketAction(pocketChoice, money, tickets, myApartment, 2, 1, myPocket);

							}
						}

						
						if (!foundKeys && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()))
						{
							/*Redisplay options*/
							std::cout << std::endl;
							std::cout << "What would you like to do with the " << roomPtr->getObject2Name() << "?" << std::endl << std::endl;
							std::cout << "1." << roomPtr->getObjectDownActionOpts(roomPtr->getObject2Name()) << std::endl;
							std::cout << "2." << roomPtr->getObjectUpActionOpts(roomPtr->getObject2Name()) << std::endl << std::endl;
							std::cout << "3. Do nothing" << std::endl << std::endl;
							actionChoice = getInteger("Choose an option.", 1, 3);
						}
						system("CLS"); 
						/*cout << "\033[2J\033[1;1H";*/

					}/*End of obj 2 while*/

				}/*End of obj 2*/
				system("CLS"); 
				/*cout << "\033[2J\033[1;1H";*/

				if (!foundKeys && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()))
				{
					std::cout << "The time is " << myPocket.getTime() << " minutes past the hour. " << std::endl << std::endl;
					std::cout << "You are in the " << myApartment.getRoomName(myApartment.getRoomAtPlayerLocation()) << std::endl << std::endl;
					std::cout << "In the " << myApartment.getRoomName(myApartment.getRoomAtPlayerLocation()) <<
						" there is a " << roomPtr->getObject1Name() << " and a " << roomPtr->getObject2Name()
						<< std::endl;

					std::cout << std::endl;
					std::cout << "1. Look at " << roomPtr->getObject1Name() << std::endl;
					std::cout << "2. Look at " << roomPtr->getObject2Name() << std::endl << std::endl;
					std::cout << "3. Leave room" << std::endl;
					roomChoice = getInteger("What would you like to do?", 1, 3);
				}
				system("CLS"); 
				/*cout << "\033[2J\033[1;1H";*/
			} 

		}
			break;
		case 6: myPocket.lookInPocket();
			break;
		};

		if (!foundKeys && (myPocket.getMoney() < myPocket.getMoneyNeeded()) && (myPocket.getTime() < myPocket.getTimeLimit()) && (myPocket.getTrainTickets() < myPocket.getTrainTicketsNeeded()) )
		{
			std::cout << "Currently you are in the " <<
				myApartment.getRoomName(myApartment.getRoomAtPlayerLocation()) << std::endl << std::endl;;

			/*Print apartment layout*/
			displayApartment(myApartment);

			movement = getUserMovement();

			system("CLS"); 
			/*system("clear);*/ 
			/*cout << "\033[2J\033[1;1H";*/

			/*Increment steps*/
			myPocket.incrementTime(1);
		}
	} 

	/*Display final outcome amongst 3 possibilities*/
	if (foundKeys == true) std::cout << "YOU FOUND YOUR KEYS!!! " << std::endl;

	else if (myPocket.getTime() >= myPocket.getTimeLimit() ) { std::cout << "You lose!! The bus already left (Too much time has passed.)" << std::endl; }

	else if (myPocket.getMoney() >= myPocket.getMoneyNeeded() ) { std::cout << "You win!!  You found enough money to take the bus." << std::endl; }

	else if (myPocket.getTrainTickets() >= myPocket.getTrainTicketsNeeded() ) { std::cout << "You win!!  You found enough train tickets to take the train." << std::endl; }

	return 0;
}


/********************************************************************************  
** Function:  displayBoard
** Description:  Output display of user options to move in the apartment.
** Parameters:  None
** Pre-Conditions:  True
** Post-Conditions:  None
** Return:  Void
*******************************************************************************/


void displayBoard() 
{
	std::cout << "1. Move up " << std::endl;
	std::cout << "2. Move down " << std::endl ;
	std::cout << "3. Move right " << std::endl ;
	std::cout << "4. Move left " << std::endl << std::endl;
	std::cout << "5. Look for your keys " << std::endl << std::endl;
	std::cout << "6. Check your pockets" << std::endl;
	std::cout << "7. Give up and stay home!! (Quit)" << std::endl << std::endl;
}


/********************************************************************************
** Function: getUserMovement
** Description: Simple function that get user input for the menu.
** Parameters: None
** Pre-Conditions: True
** Post-Conditions: displayBoard true, valid user input.
** Return: integer representing the option selected.
*******************************************************************************/


int getUserMovement()
{
	displayBoard();
	return  getInteger("Enter your choice: ", 1, 7);
}


/********************************************************************************
** Function: linkRooms
** Description: Function is hard programed to set the pointers of the roomNode
**		object to create the apartment grid.
** Parameters: RoomListNode &myApartment- Reference to RoomListNode that is to be
**			linked together.
** Pre-Conditions: RoomListNode is true
** Post-Conditions: RoomListNode + pointers 
** Return: Void
*******************************************************************************/


void linkRooms(RoomListNode &myApartment) 
{
	myApartment.setUpLink(myApartment.getRoomAtRoomID(1), myApartment.getRoomAtRoomID(6));
	myApartment.setUpLink(myApartment.getRoomAtRoomID(2), myApartment.getRoomAtRoomID(5));
	myApartment.setUpLink(myApartment.getRoomAtRoomID(3), myApartment.getRoomAtRoomID(4));
	myApartment.setUpLink(myApartment.getRoomAtRoomID(6), myApartment.getRoomAtRoomID(NULL));
	myApartment.setUpLink(myApartment.getRoomAtRoomID(5), myApartment.getRoomAtRoomID(NULL));
	myApartment.setUpLink(myApartment.getRoomAtRoomID(4), myApartment.getRoomAtRoomID(NULL));

	myApartment.setDownLink(myApartment.getRoomAtRoomID(6), myApartment.getRoomAtRoomID(1));
	myApartment.setDownLink(myApartment.getRoomAtRoomID(5), myApartment.getRoomAtRoomID(2));
	myApartment.setDownLink(myApartment.getRoomAtRoomID(4), myApartment.getRoomAtRoomID(3));
	myApartment.setDownLink(myApartment.getRoomAtRoomID(1), myApartment.getRoomAtRoomID(NULL));
	myApartment.setDownLink(myApartment.getRoomAtRoomID(2), myApartment.getRoomAtRoomID(NULL));
	myApartment.setDownLink(myApartment.getRoomAtRoomID(3), myApartment.getRoomAtRoomID(NULL));

	myApartment.setRightLink(myApartment.getRoomAtRoomID(6), myApartment.getRoomAtRoomID(5));
	myApartment.setRightLink(myApartment.getRoomAtRoomID(5), myApartment.getRoomAtRoomID(4));
	myApartment.setRightLink(myApartment.getRoomAtRoomID(1), myApartment.getRoomAtRoomID(2));
	myApartment.setRightLink(myApartment.getRoomAtRoomID(2), myApartment.getRoomAtRoomID(3));
	myApartment.setRightLink(myApartment.getRoomAtRoomID(4), myApartment.getRoomAtRoomID(NULL));
	myApartment.setRightLink(myApartment.getRoomAtRoomID(3), myApartment.getRoomAtRoomID(NULL));

	myApartment.setLeftLink(myApartment.getRoomAtRoomID(5), myApartment.getRoomAtRoomID(6));
	myApartment.setLeftLink(myApartment.getRoomAtRoomID(4), myApartment.getRoomAtRoomID(5));
	myApartment.setLeftLink(myApartment.getRoomAtRoomID(3), myApartment.getRoomAtRoomID(2));
	myApartment.setLeftLink(myApartment.getRoomAtRoomID(2), myApartment.getRoomAtRoomID(1));
	myApartment.setLeftLink(myApartment.getRoomAtRoomID(6), myApartment.getRoomAtRoomID(NULL));
	myApartment.setLeftLink(myApartment.getRoomAtRoomID(1), myApartment.getRoomAtRoomID(NULL));

}


/*********************************************************************************************
** Function: setObject
** Description: 
** Parameters: int randomInt - the room ID, int randomObjInt - Object number to be set, 
**		int randomLocInt- high or low location to be set , RoomListNode &anApartment- RoomListNode
**		to be modified, int type - item type to set
** Pre-Conditions: RoomListNode true
** Post-Conditions: None
** Return: Void
**********************************************************************************************/


void setObject(int randomInt, int randomObjInt, int randomLocInt, RoomListNode &anApartment, int type)
{
	/*If object 1*/
	if (randomObjInt == 0)
	{
		if (randomLocInt == 0) /*If location is below*/
		{
			if (type == 0) /*Key*/ 
			{ 
				anApartment.getRoomAtRoomID(randomInt)->aRoom->setObject1KeyLocation(false); 
				anApartment.getRoomAtRoomID(randomInt)->aRoom->setObject1Keys(true);
			}
			else if (type == 1) /*Train tix*/
			{ 
				anApartment.getRoomAtRoomID(randomInt)->aRoom->incrementObjectTrainTickets(1, 0);
			}
		}
		/*Location is above*/
		else if (randomLocInt == 1)
		{
			if (type == 0) 
			{
				anApartment.getRoomAtRoomID(randomInt)->aRoom->setObject1KeyLocation(true);
				anApartment.getRoomAtRoomID(randomInt)->aRoom->setObject1Keys(true);
			}
			else /*Train tix*/
			{ 
				anApartment.getRoomAtRoomID(randomInt)->aRoom->incrementObjectTrainTickets(1, 1);
			}
		}
	}
	/*If object 2*/
	else
	{
		if (randomLocInt == 0) /*If location is below*/
		{
			if (type == 0) /*Key*/
			{
				anApartment.getRoomAtRoomID(randomInt)->aRoom->setObject2KeyLocation(false);
				anApartment.getRoomAtRoomID(randomInt)->aRoom->setObject2Keys(true);
			}
			else /*Train tix*/
			{
				anApartment.getRoomAtRoomID(randomInt)->aRoom->incrementObjectTrainTickets(2, 0);
			}
		}
		/*Location is above*/
		else if (randomLocInt == 1)
		{
			if (type == 0)
			{
				anApartment.getRoomAtRoomID(randomInt)->aRoom->setObject2KeyLocation(true);
				anApartment.getRoomAtRoomID(randomInt)->aRoom->setObject2Keys(true);
			}
			else if (type == 1)/*Train tix*/
			{
				anApartment.getRoomAtRoomID(randomInt)->aRoom->incrementObjectTrainTickets(2, 1);
			}
		}
	}
}


/********************************************************************************
** Function: pocketAction
** Description: Function executes action from player to interact with object and item
** Parameters: int pocketChoice- item type (money, tickets), int money- money amount, 
**		int tickets- number of ticket, RoomListNode &anApartment- reference to RoomListNode
**		to be modified, int object-Object 1 or 2, int highLow- Location of item in object, 
**		Pocket &aPocket- Reference to player's pocket to put and remove items. 
** Pre-Conditions: RoomListNode exists, Pocket exists.
** Post-Conditions: None
** Return: Void
*******************************************************************************/


void pocketAction(int pocketChoice, int money, int tickets, RoomListNode &anApartment, int object, int highLow, Pocket &aPocket)
{
	if (pocketChoice == 1)  /*Pick up money*/
	{
		/*Add money to pocket*/
		aPocket.addMoneyToPocket(money);

		/*Reduce money from object*/
		if (object == 1) { anApartment.getRoomAtPlayerLocation()->aRoom->setObject1MoneyAmount(0); }
		else if (object == 2) {anApartment.getRoomAtPlayerLocation()->aRoom->setObject2MoneyAmount(0);
	}
	}
	else if (pocketChoice == 2) /*Pick up train tix*/
	{
		aPocket.addTrainTixToPocket(tickets);
		anApartment.getRoomAtPlayerLocation()->aRoom->setObjectTrainTickets(object, highLow, 0);
	}
	else if (pocketChoice == 3)
	{
		/*Get money to remove from pocket and remove money from pocket*/
		/*Use function call as parameter to set max money to remove as current money in pocket*/
		/*Add the money back to the current object*/
		if (object == 1) {
			int moneyToRemove = getInteger("How much money to remove from pocket?", 0, aPocket.getMoney() );
			aPocket.removeMoneyFromPocket(moneyToRemove);

			/*Add money back to room object*/
			anApartment.getRoomAtPlayerLocation()->aRoom->addObject1MoneyAmount(moneyToRemove);
			anApartment.getRoomAtPlayerLocation()->aRoom->setObject1MoneyLocation(highLow);
		}
		else if (object == 2) {
			int moneyToRemove = getInteger("How much money to remove from pocket?", 0, aPocket.getMoney() );
			aPocket.removeMoneyFromPocket(moneyToRemove);

			/*Add money back to room object*/
			anApartment.getRoomAtPlayerLocation()->aRoom->addObject2MoneyAmount(moneyToRemove);
			anApartment.getRoomAtPlayerLocation()->aRoom->setObject2MoneyLocation(highLow);
		}
	}
	else if (pocketChoice == 4) /*Remove train tickets*/
	{
		/*Get tix to remove, set max as the current number of tickets.
				Use function call as parameter to avoid creating stale variable*/
		int tixToRemove = getInteger("How many tickets to remove from pocket?", 0, aPocket.getTrainTickets() );
		aPocket.removeTrainTixFromPocket(tixToRemove);

		/*Add back to pocket using a loop to avoid having to make new method*/
		for (int i = 0; i < tixToRemove; i++) {
			anApartment.getRoomAtPlayerLocation()->aRoom->incrementObjectTrainTickets(object, highLow);
		}
	}
	else if (pocketChoice == 5) 
	{
		aPocket.lookInPocket();
		std::cout << "press enter to continue" << std::endl;
		std::cin.get();
	}
	else if (pocketChoice == 6)
	{
		
		/*Do nothing*/
	}

	system("CLS"); 
	/*cout << "\033[2J\033[1;1H";*/
}


/***************************************************************************************
** Function: displayApartment
** Description: Function steps through linked list and displays ID variable of each room
** Parameters: RoomListNode &apartment- Reference to RoomListNode to modify
** Pre-Conditions: True
** Post-Conditions: None
** Return: Void
****************************************************************************************/


void displayApartment(RoomListNode &apartment)
{
	for (int index = 6; index > 3; index--)
	{
		std::cout << std::left << std::setw(12);
		std::cout << apartment.getRoomAtRoomID(index)->aRoom->getRoomName() << " ";
	}

	std::cout << std::endl;

	/*If room is the current room, then highlight for user to see*/
	for (int index = 6; index > 3; index--)
	{
		if (apartment.getRoomIDAtNode(apartment.getRoomAtPlayerLocation()) == index)
		{
			std::cout << std::right << std::setw((7 - index) * 12) << "------------" << std::endl;
			std::cout << std::setw((7 - index) * 12) << "You are here" << std::endl;
		}
	}

	std::cout << std::endl;

	for (int index = 1; index < 4; index++)
	{
		std::cout << std::left << std::setw(12);
		std::cout << apartment.getRoomAtRoomID(index)->aRoom->getRoomName() << " ";
	}
	std::cout << std::endl;

	/*If room is the current room, then highlight for user to see*/
	for (int index = 1; index < 4; index++)
	{
		if (apartment.getRoomIDAtNode(apartment.getRoomAtPlayerLocation()) == index)
		{
			std::cout << std::right << std::setw((index + 1 - 1) * 12) << "------------" << std::endl;
			std::cout << std::setw((index + 1 - 1) * 12) << "You are here" << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}


/********************************************************************************
** Function: createApartment
** Description: Function to create the linked list of randomlly choosen Room objects
** Parameters: RoomListNode &apartment- Reference to the RoomListNode to be modified.
** Pre-Conditions: RoomListNode true
** Post-Conditions: RoomListNode + 6 Nodes
** Return: None
*******************************************************************************/


void createApartment(RoomListNode &apartment)
{
	int moneyAmt;
	bool moneyLocation;
	int roomType; /*Type of room*/
	int objectType1, objectType2; /*Type of object to put in room*/
	int index = 1; /*Counter for number of rooms in apartment*/

	/*Create apartment with 6 rooms, but limit to 1 kitchen, 1 livingroom, and 2 bathrooms*/

	while (index < 7)
	{
		/*Generate random number between 1 and 4 to select room type*/
		roomType = getRandomInteger(4) + 1;

		/*First room is always the foyer*/
		if (index == 1)
		{
			Foyer *aFoyer = new Foyer();
			apartment.addRoom(aFoyer, index);

			/*Set objects in room
				Randomly generate object types and set names*/
			objectType1 = getRandomInteger(4);
			aFoyer->setObject1Name(FOYER_OBJ_NAMES[objectType1]);

			/*Enfore object 2 to be different*/
			objectType2 = getRandomInteger(4);
			while (objectType2 == objectType1) { objectType2 = getRandomInteger(4); }
			aFoyer->setObject2Name(FOYER_OBJ_NAMES[objectType2]);

			/*Generate money amount for objects and hide in object. Money hidden in
				Foyer is less compared to other rooms*/
			/*Object 1*/
			moneyAmt = getRandomInteger(5);
			moneyLocation = getRandomInteger(2); /*0 or 1*/
			aFoyer->setObject1MoneyAmount(moneyAmt);
			aFoyer->setObject1MoneyLocation(moneyLocation);

			/*Object 2*/
			moneyAmt = getRandomInteger(5);
			moneyLocation = getRandomInteger(2); /*0 or 1*/
			aFoyer->setObject2MoneyAmount(moneyAmt);
			aFoyer->setObject2MoneyLocation(moneyLocation);

			index++;
		}
		/*If index is not == 1*/
		else
		{
			switch (roomType)
			{
			case 1: /*Bedroom*/
			{
				Bedroom *aBdrm = new Bedroom();
				apartment.addRoom(aBdrm, index);

				/*Set objects in room
					Randomly generate object types and set names*/
				/*Object 1*/
				objectType1 = getRandomInteger(4);
				aBdrm->setObject1Name(BEDROOM_OBJ_NAMES[objectType1]);

				/*Object 2*/
				objectType2 = getRandomInteger(4);
				while (objectType2 == objectType1) { objectType2 = getRandomInteger(4); }
				aBdrm->setObject2Name(BEDROOM_OBJ_NAMES[objectType2]);

				/*Generate money amount for objects and hide in object*/
				moneyAmt = getRandomInteger(10);
				moneyLocation = getRandomInteger(2); /*0 is below/inside, 1 is above/outside*/
				aBdrm->setObject1MoneyAmount(moneyAmt);
				aBdrm->setObject1MoneyLocation(moneyLocation);

				moneyAmt = getRandomInteger(10);
				moneyLocation = getRandomInteger(2);
				aBdrm->setObject2MoneyAmount(moneyAmt);
				aBdrm->setObject2MoneyLocation(moneyLocation);

				index++;
			}
			break;
			case 2: /*Kitchen*/
			{
				/*Restrict number of kitchens to 1*/
				if (apartment.getNumKitchens() < 1)
				{
					Kitchen *aKitchen = new Kitchen();
					apartment.addRoom(aKitchen, index);

					/*Randomly generate object types and set names*/
					/*Object 1*/
					objectType1 = getRandomInteger(4);
					aKitchen->setObject1Name(KITCHEN_OBJ_NAMES[objectType1]);

					/*Object 2*/
					objectType2 = getRandomInteger(4);
					while (objectType2 == objectType1) { objectType2 = getRandomInteger(4); }
					aKitchen->setObject2Name(KITCHEN_OBJ_NAMES[objectType2]);

					/*Generate money amount for objects and hide in object*/
					moneyAmt = getRandomInteger(10);
					moneyLocation = getRandomInteger(2); /*0 or 1*/

					aKitchen->setObject1MoneyAmount(moneyAmt);
					aKitchen->setObject1MoneyLocation(moneyLocation);

					moneyAmt = getRandomInteger(10);
					moneyLocation = getRandomInteger(2); /*Generate a 0 or 1*/

					aKitchen->setObject2MoneyAmount(moneyAmt);
					aKitchen->setObject2MoneyLocation(moneyLocation);

					index++;
				}
			}
			break;
			case 3:  /*Living Room*/
			{
				/*Restrict number of living rooms to 1*/
				if (apartment.getNumLivingRooms() < 1)
				{
					LivingRoom *aLvR = new LivingRoom();
					apartment.addRoom(aLvR, index);

					/*Randomly generate object types and set names*/
					/*Object 1*/
					objectType1 = getRandomInteger(4);
					aLvR->setObject1Name(LIVINGROOM_OBJ_NAMES[objectType1]);

					/*Object 2*/
					objectType2 = getRandomInteger(4);
					while (objectType2 == objectType1) { objectType2 = getRandomInteger(4); }
					aLvR->setObject2Name(LIVINGROOM_OBJ_NAMES[objectType2]);

					moneyAmt = getRandomInteger(10);
					moneyLocation = getRandomInteger(2); 

					aLvR->setObject1MoneyAmount(moneyAmt);
					aLvR->setObject1MoneyLocation(moneyLocation);

					moneyAmt = getRandomInteger(10);
					moneyLocation = getRandomInteger(2); /*Generate 1 or 0*/

					aLvR->setObject2MoneyAmount(moneyAmt);
					aLvR->setObject2MoneyLocation(moneyLocation);

					index++;
				}
			}
			break;
			case 4: /*Bathroom*/
			{
				/*Restrict number of bathrooms to 2*/
				if (apartment.getNumBathrooms() < 2)
				{
					Bathroom *aBathR = new Bathroom();
					apartment.addRoom(aBathR, index);

					/*Randomly generate object types and set names*/
					/*Object 1*/
					objectType1 = getRandomInteger(4);
					aBathR->setObject1Name(BATHROOM_OBJ_NAMES[objectType1]);

					/*Object 2*/
					objectType2 = getRandomInteger(4);
					while (objectType2 == objectType1) { objectType2 = getRandomInteger(4); }
					aBathR->setObject2Name(BATHROOM_OBJ_NAMES[objectType2]);

					/*Generate money amount for objects*/

					moneyAmt = getRandomInteger(10);
					moneyLocation = getRandomInteger(2); /*0 or 1*/

					aBathR->setObject1MoneyAmount(moneyAmt);
					aBathR->setObject1MoneyLocation(moneyLocation);

					moneyAmt = getRandomInteger(10);
					moneyLocation = getRandomInteger(2); /*0 or 1*/

					aBathR->setObject2MoneyAmount(moneyAmt);
					aBathR->setObject2MoneyLocation(moneyLocation);

					index++;
				}
			}
			break;
			};
		}
	}

	/*Initialize starting location to Room ID = 1*/
	apartment.setPlayerLocation(apartment.getRoomAtRoomID(1));

	/*Hide the keys by generating random room and location, bias toward bedroom*/
	int randomInt = getRandomInteger(6) + 1; /*Random room*/

	/*If bedroom not choosen on first time, reject and draw again.
		This will help bias the key to be hidden in the bedrooms*/
	if (apartment.getRoomAtRoomID(randomInt)->aRoom->getRoomName() != "Bedroom") {
		randomInt = getRandomInteger(6) + 1;
	}

	int randomObjInt = getRandomInteger(2); /*Random object in room*/
	int randomLocInt = getRandomInteger(2); /*Random location in object*/
	
	int type = 0; /*Indicates keys, for use with setObject function call*/
	setObject(randomInt, randomObjInt, randomLocInt, apartment, type);

	/*Hide 6 train tickets randomly*/
	type = 1; /*Indicates train tickets*/
	for (int index = 1; index <= 10; index++)
	{
		randomInt = getRandomInteger(6) + 1; /*Random room*/
		randomObjInt = getRandomInteger(2); /*Random object in room*/
		randomLocInt = getRandomInteger(2); /*Random location in object*/

		setObject(randomInt, randomObjInt, randomLocInt, apartment, type);
	}
}


/********************************************************************************
** Function: displayInstructions
** Description: Display output to user giving basic instructions on program purpose.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: Void
*******************************************************************************/


void displayInstructions() 
{
	std::cout << "Oh no!!  Class is starting in soon and you have misplaced your keys in the apartment." << std::endl << std::endl;
	std::cout << "You have 20 minutes to locate your keys by searching the rooms in your apartment." << std::endl << std::endl;
	std::cout << "You can also collect 4 train tickets or 20 cents for a bus ticket." << std::endl << std::endl;
	std::cout << "      (but not both, because your pockets are not big enough)" << std::endl << std::endl;
	std::cout << "press enter to continue" << std::endl;
	std::cout << std::endl;
	std::cin.get();
}

