#pragma once


#ifndef FOYER_HPP
#define FOYER_HPP
#include "Room.hpp"

class Foyer : public Room {
private:

public:
	Foyer();

	virtual int lookUnder(int, std::string, int objType, Pocket &aPocket);
	virtual int lookOnTop(int, std::string, int objType, Pocket &aPocket);

	virtual std::string getObjectDownActionOpts(std::string);
	virtual std::string getObjectUpActionOpts(std::string);
};


#endif