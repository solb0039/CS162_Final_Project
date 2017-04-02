CXX = g++
CXXFLAGS = -std=c++0x

PROG1 = FinalProjectSeanSolberg
PROGS = ${PROG3}

FinalProjectSeanSolberg: utils.o Bathroom.o Bedroom.o Foyer.o Kitchen.o LivingRoom.o Object.o Pocket.o Room.o RoomListNode.o FinalProject.o
	${CXX} utils.o   Bathroom.o Bedroom.o Foyer.o Kitchen.o LivingRoom.o Object.o Pocket.o Room.o RoomListNode.o FinalProject.o -o FinalProjectSeanSolberg

utils.o: utils.cpp
	${CXX} -c utils.cpp

Bathroom.o: Bathroom.cpp
	${CXX} -c Bathroom.cpp

Bedroom.o: Bedroom.cpp
	${CXX} -c Bedroom.cpp

Foyer.o: Foyer.cpp
	${CXX} -c Foyer.cpp

Kitchen.o: Kitchen.cpp
	${CXX} -c Kitchen.cpp

LivingRoom.o: LivingRoom.cpp
	${CXX} -c LivingRoom.cpp

Object.o: Object.cpp
	${CXX} -c Object.cpp

Pocket.o: Pocket.cpp
	${CXX} -c Pocket.cpp

Room.o: Room.cpp
	${CXX} -c Room.cpp

RoomListNode.o: RoomListNode.cpp
	${CXX} -c RoomListNode.cpp

FinalProject.o: FinalProject.cpp
	${CXX} -c FinalProject.cpp

debug:  
	valgrind --leak-check=full FinalProjectSeanSolberg

clean:
	rm -f FinalProjectSeanSolberg  *.o

