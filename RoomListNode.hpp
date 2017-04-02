#pragma once

#ifndef ROOMLISTNODE_HPP
#define ROOMLISTNODE_HPP
#include "Room.hpp"
#include "Bedroom.hpp"
#include "Kitchen.hpp"
#include "Bathroom.hpp"
#include "LivingRoom.hpp"
#include "Foyer.hpp"


class RoomListNode {
protected:

	struct roomNode {
		friend class RoomListNode;
		Room *aRoom;

		int roomID;

		roomNode *up;
		roomNode *down;
		roomNode *left;
		roomNode *right;
		roomNode *next;

		/*Constructors*/
		roomNode(Bedroom *bdrm, int aID, roomNode *next1 = NULL)
		{
			aRoom = bdrm;
			roomID = aID;

			up = NULL;
			down = NULL;
			left = NULL;
			right = NULL;
			next = next1;
		}
		roomNode(Kitchen *kitch, int aID, roomNode *next1 = NULL)
		{
			aRoom = kitch;
			roomID = aID;

			up = NULL;
			down = NULL;
			left = NULL;
			right = NULL;
			next = next1;
		}
		roomNode(LivingRoom *LvR, int aID, roomNode *next1 = NULL)
		{
			aRoom = LvR;
			roomID = aID;

			up = NULL;
			down = NULL;
			left = NULL;
			right = NULL;
			next = next1;
		}
		roomNode(Bathroom *bath, int aID, roomNode *next1 = NULL)
		{
			aRoom = bath;
			roomID = aID;

			up = NULL;
			down = NULL;
			left = NULL;
			right = NULL;
			next = next1;
		}
		roomNode(Foyer *fyr, int aID, roomNode *next1 = NULL)
		{
			aRoom = fyr;
			roomID = aID;

			up = NULL;
			down = NULL;
			left = NULL;
			right = NULL;
			next = next1;
		}

	};

	/*Member variables to count number of rooms in apartment*/
	int numBathrooms;
	int numBedrooms;
	int numLivingRooms;
	int numKitchens;

	/*Pointers to other nodes*/
	roomNode *home;
	roomNode *playerLocation;

public:
	/*Constructor and destructors*/
	RoomListNode();
	~RoomListNode();

	void addRoom(Bedroom*, int);
	void addRoom(Kitchen*, int);
	void addRoom(Bathroom*, int);
	void addRoom(LivingRoom*, int);
	void addRoom(Foyer*, int);

	int getNumBathrooms() { return numBathrooms; }
	int getNumKitchens() { return numKitchens; }
	int getNumLivingRooms() { return numLivingRooms; }
	int getNumBedrooms() { return numBedrooms; }

	roomNode* getRoomAtPlayerLocation() { return playerLocation; }
	void setPlayerLocation(roomNode* inRoom) { playerLocation = inRoom; }
	roomNode* getRoomAtRoomID(int ID);
	std::string getRoomName(roomNode* inRoom) { return inRoom->aRoom->getRoomName(); }
	int getRoomIDAtNode(roomNode* inNode) { return inNode->roomID; }

	bool canMoveUp(roomNode*);
	bool canMoveDown(roomNode*);
	bool canMoveRight(roomNode*);
	bool canMoveLeft(roomNode*);
	void moveUp(roomNode*);
	void moveDown(roomNode*);
	void moveRight(roomNode*);
	void moveLeft(roomNode*);

	void setUpLink(roomNode* roomD, roomNode* roomU) { roomD->up = roomU; }
	void setDownLink(roomNode* roomU, roomNode* roomD) { roomU->down = roomD; }
	void setRightLink(roomNode* roomL, roomNode* roomR) { roomL->right = roomR; }
	void setLeftLink(roomNode* roomR, roomNode* roomL) { roomR->left = roomL; }
	
};

#endif