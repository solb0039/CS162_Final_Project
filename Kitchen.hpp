#pragma once

#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include "Room.hpp"

class Kitchen : public Room {
private:

public:
	Kitchen();
	~Kitchen();

	virtual int lookUnder(int, std::string, int objType, Pocket &aPocket);
	virtual int lookOnTop(int, std::string, int objType, Pocket &aPocket);

	virtual std::string getObjectDownActionOpts(std::string);
	virtual std::string getObjectUpActionOpts(std::string);
};


#endif