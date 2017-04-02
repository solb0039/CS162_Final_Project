#pragma once

#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <string>

class Object {

protected:
	std::string objectName;
	bool keys;
	bool keyLocation;
	int trainTicketsLow;
	int trainTicketsHigh;
	
	int money; /*Amount*/
	bool moneyLocation; /* Up/outside (true) or down/inside (false)*/

public:
	/*Accessor methods*/
	bool getKeys() { return keys; }
	bool getKeyLocation() { return keyLocation; }
	double getMoney() { return money; }
	std::string getObjectName() { return objectName; }
	bool getMoneyLocation() { return moneyLocation; }

	int getTrainTicketsLow() { return trainTicketsLow; }
	int getTrainTicketsHigh() { return trainTicketsHigh; }

	/*Mutator methods*/
	void setKeys(bool aKey) { keys = aKey; }
	void setMoney(double value) { money = value; }
	void addMoney(double value) { money += value; }

	void setObjectName(std::string objName) { objectName = objName; }
	void setKeyLocation(bool keyL) { keyLocation = keyL; }
	
	void setMoneyLocation(bool moneyL) { moneyLocation = moneyL; }
	
	void incrementTrainTicketsLow() { trainTicketsLow += 1; }
	void incrementTrainTicketsHigh() { trainTicketsHigh += 1; }

	void decrementTrainTicketsLow(int tix) { trainTicketsLow -= tix; }
	void decrementTrainTicketsHigh(int tix) { trainTicketsHigh -= tix; }

	void setTrainTicketsLow(int tix) { trainTicketsLow = tix; }
	void setTrainTicketsHigh(int tix) { trainTicketsHigh = tix; }
};


#endif