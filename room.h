#ifndef ROOM
#define ROOM
// room class for zuul
#include <iostream>
#include <map>
#include <cstring>
class room {
 public:
  std::map<int, int> exits;
  // NORTH: 1
  // EAST: 2
  // SOUTH: 3
  // WEST: 4
  char name[81] = "room"; // room name that is displayed, used as an "identifier"
  char description[401] = "You enter a room."; // this appears upon room entry
  char detailed_description[401] = "There is nothing noteworthy in this room."; // appears if SEARCH command is used
  char item_simple[81] = "NONE"; // use the PICK command to get items in a room
  char item_detailed[81] = "NONE"; // this requires the search check to succeed
  room(); // the variables will be defined in main() rather than through a constructor
 private:
};




#endif
