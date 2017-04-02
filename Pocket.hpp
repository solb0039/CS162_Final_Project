#pragma once

#ifndef POCKET_HPP
#define POCKET_HPP

class Pocket 
{
private:
	int money;
	int trainTickets;
	int time;
	int timeLimit;
	int moneyNeeded;
	int trainTicketsNeeded;

public:
	Pocket();

	/*Accessor methods*/
	int getMoney() { return money; }

	int getTime() { return time; }
	int getTrainTickets() { return trainTickets; }
	int getTimeLimit() { return timeLimit; }
	int getMoneyNeeded() { return moneyNeeded; }
	int getTrainTicketsNeeded() { return trainTicketsNeeded; }

	/*Mutator methods*/
	void incrementTime(int timeStep) { time += timeStep; }
	void addMoneyToPocket(int newMoney);

	void removeMoneyFromPocket(int newMoney) { money -= newMoney; }

	void addTrainTixToPocket(int newTix) { trainTickets += newTix; }
	void removeTrainTixFromPocket(int newTix) { trainTickets -= newTix; }
	
	/*Other methods*/
	void lookInPocket();
	int pocketChoices();
};

#endif