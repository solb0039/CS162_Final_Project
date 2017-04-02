#pragma once

#ifndef BATHROOM_HPP
#define BATHROOM_HPP
#include "Room.hpp"


class Bathroom : public Room {
private:

public:
	Bathroom();

	virtual int lookUnder(int, std::string, int objType, Pocket &aPocket);
	virtual int lookOnTop(int, std::string, int objType, Pocket &aPocket);

	virtual std::string getObjectDownActionOpts(std::string);
	virtual std::string getObjectUpActionOpts(std::string);
};


#endif