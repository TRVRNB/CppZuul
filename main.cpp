#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include "room.h"
using namespace std;

char room_data[20][10][401] = { // definitions of rooms, excluding special logic
  {"Name", "Undiscovered Name", "Description", "Detailed Description", "Item", "Key", "NORTH", "EAST", "SOUTH", "WEST"}, // example
  {"old bedroom", "NONE", "You are in an empty, dusty bedroom.", "The light flickers. A dark key is on the mattress.", "Grey key", "NONE", "NONE", "thin hallway", "NONE", "NONE"},
  {"thin hallway", "dusty door", "The hallway is so thin, the walls seem to be shifting...", "There is nothing noteworthy in this room.", "NONE", "Grey key", "NONE", "NONE", "NONE", "old bedroom"},
};
int ROOM_COUNT = 3;

// main function
int main(){
  vector<room*> ROOMS;
  for (int i = 1; i < ROOM_COUNT; i++){ // starts at 1 to exclude the 'example' room
    cout << "Reading " << room_data[i][0] << endl;
    static room current_room;
    // room variables are defined here rather than through an initializer
    strcpy(current_room.name, room_data[i][0]); // name
    strcpy(current_room.undiscovered_name, room_data[i][1]); // undiscovered name
    strcpy(current_room.description, room_data[i][2]); // description
    strcpy(current_room.detailed_description, room_data[i][3]); // detailed description
    strcpy(current_room.item, room_data[i][4]); // item to pick up
    strcpy(current_room.key, room_data[i][5]); // key required for entry
    // exits
    strcpy(current_room.NORTH, room_data[i][6]); // NORTH
    strcpy(current_room.EAST, room_data[i][7]); // EAST
    strcpy(current_room.SOUTH, room_data[i][8]); // SOUTH
    strcpy(current_room.WEST, room_data[i][9]); // WEST
    room* room1 = &current_room;
    ROOMS.push_back(room1);
  }
  return 0;
}
