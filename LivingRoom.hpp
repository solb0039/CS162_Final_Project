#pragma once

#ifndef LIVINGROOM_HPP
#define LIVINGROOM_HPP
#include "Room.hpp"

class LivingRoom : public Room {
private:

public:
	LivingRoom();

	virtual int lookUnder(int, std::string, int objType, Pocket &aPocket);
	virtual int lookOnTop(int, std::string, int objType, Pocket &aPocket);

	virtual std::string getObjectDownActionOpts(std::string);
	virtual std::string getObjectUpActionOpts(std::string);
};


#endif