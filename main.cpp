#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include "room.h"
using namespace std;

char room_data[20][10][401] = { // definitions of rooms, excluding special logic
  {"Name", "Undiscovered Name", "Description", "Detailed Description", "Item", "Key", "NORTH", "EAST", "SOUTH", "WEST"}, // example
  {"old bedroom", "NONE", "You are in an empty, dusty bedroom.", "The light flickers. A dark key is on the mattress.", "grey key", "NONE", "NONE", "thin hallway", "NONE", "NONE"},
  {"thin hallway", "dusty door", "The hallway is so thin, the walls seem to be shifting...", "There is nothing noteworthy in this room.", "NONE", "grey key", "NONE", "NONE", "NONE", "old bedroom"},
};
int ROOM_COUNT = 3;

// main function
int main(){
  // first, build the ROOMS vector
  vector<room*> ROOMS;
  for (int i = 1; i < ROOM_COUNT; i++){ // starts at 1 to exclude the 'example' room
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
  // ITEMS array
  std::vector<const char*> ITEMS = {"NONE"};
  // opening message
  cout << "You are locked in an empty, dark bedroom.\nYou have no idea where you came from or where you'll go.\nYou need some sort of key to get out of here.\nTo see a list of commands, type 'HELP'.\n" << flush;
  char input[81] = ""; // input string, start empty
  char input2[81] = "";
  char input3[81] = "";
  char input4[81] = "";
  while (strcmp(input, "QUIT") != 0){ // QUIT
    cout << "$ Enter a command: " << flush;
    cin >> input;
    if (strcmp(input, "HELP") == 0){ // HELP
      cout << "HELP: return a list of commands\n" << flush;
      cout << "QUIT: quit the game prematurely\n" << flush;
      cout << "SEARCH: look through this room\n" << flush;
      cout << "MOVE: move to a nearby room\n" << flush;
      cout << "PICK: pick up an item in the room (if one exists)\n" << flush;
      cout << "USE: use one item on another\n";
    } else if (strcmp(input, "SEARCH") == 0){ // SEARCH
      
    } else if (strcmp(input, "MOVE") == 0){ // MOVE

    } else if (strcmp(input, "PICK") == 0){ // PICK

    } else if (strcmp(input, "USE") == 0){ // USE

    }
  }

  
  return 0;
}
