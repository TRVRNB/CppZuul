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
  {"thin hallway", "dusty door", "You are in a hallway. The hallway is so thin, the walls seem to be shifting...", "There is nothing noteworthy in this room.", "NONE", "grey key", "NONE", "NONE", "NONE", "old bedroom"},
};
int ROOM_COUNT = 3;

namespace zuul{ // this is so ROOMS can be used across functions without passing by reference
  vector<room*> ROOMS;
};


// search for room using the name
room* search_for_room(char* room_name){
  using namespace zuul;
  for (room* current_room : ROOMS){
    if (strcmp(current_room->name, room_name) == 0){
      return current_room;
    }
  }
  return ROOMS[0]; // edge case, return the default room
}

// main function
int main(){
  // first, build ROOMS
  using namespace zuul;
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
  vector<const char*> ITEMS = {"NONE"}; // inventory
  room* c_room = ROOMS[0];
  c_room->explored = true;
  // opening message
  cout << "\nYou are locked in an empty, dark bedroom.\nYou have no idea where you came from or where you'll go.\nTo the east, there is a locked door.\nTo see a list of commands, type 'HELP'.\n" << flush;
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
      cout << "DROP: drop an item into this room, if it is empty\n" << flush;
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
	room* to_visit = search_for_room(go_to1);
	// search for key in inventory
	bool has_key = false;
	for (int i = 0; i < ITEMS.size(); i++){ // iterate over every item, check for equality
	  if (strcmp(ITEMS[i], to_visit->key) == 0){ // NONE is the first item in the ITEMS vector by default. this should prevent a crash here if the player has no items, and allow entry into any room with no key; i need to prevent the player from dropping this NONE item later
	    has_key = true;
	    strcpy(to_visit->key, ITEMS[i]); // remove the key requirement permanently, which should prevent the player from softlocking themselves by leaving the keys in the wrong room
	    // break would be nice here, but it's against the rules
	  }
	}
	if (has_key){
	  c_room = to_visit;
	  c_room->explored = true; // in the future, this will be described based on the interior rather than exterior when looking at neighboring rooms
	  cout << '\n';
	  cout << c_room->description << "." << endl;;
	  // describe neighboring rooms
	  if (strcmp(c_room->NORTH, "NONE") != 0){ // NORTH
	    room* to_describe = search_for_room(c_room->NORTH);
	    if (to_describe->explored){
	      cout << "To the north, there is the " << to_describe->name << '.' << endl; 
	    } else {
	      cout << "To the north, there is a " << to_describe->undiscovered_name << '.' << endl;
	    }
	  }
	  if (strcmp(c_room->EAST, "NONE") != 0){ // EAST
	    room* to_describe = search_for_room(c_room->EAST);
	    if (to_describe->explored){
	      cout << "To the east, there is the " << to_describe->name << '.' << endl; 
	    } else {
	      cout << "To the east, there is a " << to_describe->undiscovered_name << '.' << endl;
	    }
	  }
	  if (strcmp(c_room->SOUTH, "NONE") != 0){ // SOUTH
	    room* to_describe = search_for_room(c_room->SOUTH);
	    if (to_describe->explored){
	      cout << "To the south, there is the " << to_describe->name << '.' << endl; 
	    } else {
	      cout << "To the south, there is a " << to_describe->undiscovered_name << '.' << endl;
	    }
	  }
	  if (strcmp(c_room->WEST, "NONE") != 0){ // WEST
	    room* to_describe = search_for_room(c_room->WEST);
	    if (to_describe->explored){
	      cout << "To the west, there is the " << to_describe->name << '.' << endl; 
	    } else {
	      cout << "To the west, there is a " << to_describe->undiscovered_name << '.' << endl;
	    }
	  }
	} else { // hasn't key
	  cout << "The door won't budge." << endl;
	}
      }
    } else if (strcmp(input, "PICK") == 0){ // PICK
      // check for item, then add it to inventory
      if (strcmp(c_room->item, "NONE") != 0){
	static char item1[81]; // need to make a static char array since the room item will quickly change to NONE
	strcpy(item1, c_room->item);
	const char* item = item1;
	ITEMS.push_back(item);
	cout << "Picked up " << item << "." << endl;
	strcpy(c_room->item, "NONE"); // get rid of this item from the room
      } else {
	cout << "There is nothing to pick up." << endl;
      }
    } else if (strcmp(input, "DROP") == 0){ // DROP
      // drop an item on the ground, if there is space
      if (strcmp(c_room->item, "NONE") == 0){
	// both of the for loops start at 1 to exclude the NONE item
	for (int i = 1; i < ITEMS.size(); i++){
	  cout << ITEMS[i] << endl;
	}
	cout << "What item do you want to drop?: " << flush;
	cin.ignore();
	cin.getline(input1, 80);
	bool dropped = false;
	for (int i = 1; i < ITEMS.size(); i++){
	  if (strcmp(input1, ITEMS[i]) == 0){
	    dropped = true;
	    strcpy(c_room->item, ITEMS[i]);
	    ITEMS.erase(ITEMS.begin() + i);
	    cout << "Dropped " << c_room->item << '.' << endl;
	  }
	}
	if (!dropped){
	  cout << "Item not found." << endl;
	}
      } else { // if there is no room
	cout << "This room already has an item. How could a room possibly fit two items?" << endl;
      }
    }
  }
  return 0;
}
