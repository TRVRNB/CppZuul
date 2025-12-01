#ifndef ROOM
#define ROOM
// room class for zuul
#include <iostream>
#include <map>
#include <cstring>
class room {
 public:
  // exits
  char NORTH[81] = "NONE";
  char EAST[81] = "NONE";
  char SOUTH[81] = "NONE";
  char WEST[81] = "NONE";
  // other data
  char name[81] = "room"; // room name that is displayed, used as an "identifier"
  bool explored = false;
  char undiscovered_name[81] = "door"; // what to call the room before it has been explored
  char description[401] = "You enter a room."; // this appears upon room entry
  char detailed_description[401] = "There is nothing noteworthy in this room."; // appears if SEARCH command is used
  char item[81] = "NONE"; // use the PICK command to get items in a room
  char key[81] = "NONE"; // item required to enter this room
 private:
};




#endif
