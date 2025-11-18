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
  int id; // this will be automatically set in main(), to be unique from all others
  char special[81] = "NONE"; // change this to apply special logic to the room in main()
  char name[81] = "ROOM"; // room name that is displayed
  char description[401] = "ROOM DESCRIPTION"; // this appears if you use the SEARCH command
  char detailed_description[401] = "DETAILED ROOM DESCRIPTION"; // appears if room search is successful
  int difficulty = 7; // the minimum roll needed to succeed a search
  bool extra_detail = false; // not all rooms have something special to be discovered
  char item_simple[81] = "NONE"; // use the PICK command to get items in a room
  char item_detailed[81] = "NONE"; // this requires the search check to succeed
  room(); // the variables will be defined in main() rather than through a constructor
 private:
  bool detailed_search = false; // update to true if the player successfully searches
  
};




#endif
