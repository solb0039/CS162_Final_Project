#pragma once

#ifndef ROOM_HPP
#define ROOM_HPP
#include "Object.hpp"
#include <string>
#include <iostream>
#include "Pocket.hpp"

class Room {

protected:
	std::string roomName;
	
	Object object1;
	Object object2;

public:
	virtual int lookUnder(int, std::string, int, Pocket&) = 0;
	virtual int lookOnTop(int, std::string, int, Pocket&) = 0;

	virtual std::string getObjectDownActionOpts(std::string) = 0;
	virtual std::string getObjectUpActionOpts(std::string) = 0;

	/*Mutator methods to pass through data to Object data member*/
	void setObject1Name(std::string name) { object1.setObjectName(name); }
	void setObject2Name(std::string name) { object2.setObjectName(name); }

	void setObject1MoneyAmount(int amt) { object1.setMoney(amt); }
	void setObject2MoneyAmount(int amt) { object2.setMoney(amt); }

	void addObject1MoneyAmount(int amt) { object1.addMoney(amt); }
	void addObject2MoneyAmount(int amt) { object2.addMoney(amt); }

	void setObject1MoneyLocation(bool loc) { object1.setMoneyLocation(loc); }
	void setObject2MoneyLocation(bool loc) { object2.setMoneyLocation(loc); }
	
	void setObject1Keys(bool aKey) { object1.setKeys(aKey); }
	void setObject2Keys(bool aKey) { object2.setKeys(aKey); }

	void incrementObjectTrainTickets(int object, int highLow);

	void setObjectTrainTickets(int object, int highLow, int value);

	void setObject1KeyLocation(bool loc) { object1.setKeyLocation(loc); }
	void setObject2KeyLocation(bool loc) { object2.setKeyLocation(loc); }

	/*Accessor methods*/
	int getObjectTrainTickets(int object, int highLow);
	
	int getObject1MoneyAmount() { return object1.getMoney(); }
	int getObject2MoneyAmount() { return object2.getMoney(); }

	bool getObject1Keys() { return object1.getKeys(); }
	bool getObject2Keys() { return object2.getKeys(); }

	bool getObject1KeysLocation() { return object1.getKeyLocation(); }
	bool getObject2KeysLocation() { return object2.getKeyLocation(); }

	std::string getRoomName() { return roomName; }
	std::string getObject1Name() { return object1.getObjectName(); }
	std::string getObject2Name() { return object2.getObjectName(); }
};

#endif