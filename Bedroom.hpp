#pragma once

#ifndef BEDROOM_HPP
#define BEDROOM_HPP
#include "Room.hpp"

class Bedroom : public Room {
private:

public:
	Bedroom();

	virtual int lookUnder(int, std::string, int objType, Pocket &aPocket);
	virtual int lookOnTop(int, std::string, int objType, Pocket &aPocket);

	virtual std::string getObjectDownActionOpts(std::string);
	virtual std::string getObjectUpActionOpts(std::string);
};


#endif