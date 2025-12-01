#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include "room.h"
using namespace std;

char room_data[20][10][401] = { // definitions of rooms, excluding special logic
  {"Name", "Undiscovered Name", "Description", "Detailed Description", "Item", "Key", "NORTH", "EAST", "SOUTH", "WEST"}, // example
  {"old bedroom", "old bedroom", "You are in an empty, dusty bedroom.", "The light flickers. A dark key is on the mattress.", "grey key", "NONE", "NONE", "thin hallway", "NONE", "NONE"},
  {"thin hallway", "dusty door", "The hallway is so thin, the walls seem to be shifting...", "There is nothing noteworthy in this room.", "NONE", "grey key", "NONE", "NONE", "NONE", "old bedroom"},
};
int ROOM_COUNT = 3;

// search for room using the name
room* search_for_room(vector<room*>& ROOMS, char* room_name){
  for (room* current_room : ROOMS){
    if (strcmp(current_room->name, room_name) == 0){
      return current_room;
    }
  }
  return ROOMS[0]; // edge case, return the default room
}

// main function
int main(){
  // first, build the ROOMS vector
  vector<room*> ROOMS;
  room* current_room;
  for (int i = 1; i < ROOM_COUNT; i++){ // starts at 1 to exclude the 'example' room
    current_room = new room;
    // room variables are defined here rather than through an initializer
    strcpy(current_room->name, room_data[i][0]); // name
    strcpy(current_room->undiscovered_name, room_data[i][1]); // undiscovered name
    strcpy(current_room->description, room_data[i][2]); // description
    strcpy(current_room->detailed_description, room_data[i][3]); // detailed description
    strcpy(current_room->item, room_data[i][4]); // item to pick up
    strcpy(current_room->key, room_data[i][5]); // key required for entry
    // exits
    strcpy(current_room->NORTH, room_data[i][6]); // NORTH
    strcpy(current_room->EAST, room_data[i][7]); // EAST
    strcpy(current_room->SOUTH, room_data[i][8]); // SOUTH
    strcpy(current_room->WEST, room_data[i][9]); // WEST
    ROOMS.push_back(current_room);
  }
  // other variables
  vector<const char*> ITEMS = {"NONE"};
  room* c_room = ROOMS[0];
  c_room->explored = true;
  // opening message
  cout << "\nYou are locked in an empty, dark bedroom.\nYou have no idea where you came from or where you'll go.\nThere is a locked door to the east.\nTo see a list of commands, type 'HELP'.\n" << flush;
  char input[81] = ""; // input string, start empty
  char input1[81] = "";
  char input2[81] = "";
  char input3[81] = "";
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
      cout << c_room->detailed_description << '\n' << flush;
    } else if (strcmp(input, "MOVE") == 0){ // MOVE
      cout << "$ Which direction ('NORTH', 'SOUTH', 'EAST', 'WEST')?: " << flush;
      cin >> input1;
      char go_to[81] = "NONE"; // default case, do nothing
      if (strcmp(input1, "NORTH") == 0){
	strcpy(go_to, c_room->NORTH);
      } else if (strcmp(input1, "EAST") == 0){
	strcpy(go_to, c_room->EAST);
      } else if (strcmp(input1, "SOUTH") == 0){
	strcpy(go_to, c_room->SOUTH);
      } else if (strcmp(input1, "WEST") == 0){
	strcpy(go_to, c_room->WEST);
      }
      // move room, if a room was found
      if (strcmp(go_to, "NONE") != 0){
	char* go_to1 = go_to;
	room* to_visit = search_for_room(ROOMS, go_to1);
	
      }
    } else if (strcmp(input, "PICK") == 0){ // PICK

    } else if (strcmp(input, "USE") == 0){ // USE

    }
  }
  return 0;
}
