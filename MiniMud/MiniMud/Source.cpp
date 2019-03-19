//----------------------------------------------------------------------------
//                  CS 215 - Project 2 - MiniMud
//----------------------------------------------------------------------------
// Author:  
// Date:  
// Description:  
// Assistance: I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.I received help from no one.
// OR
// Assistance: I received help from the following:
//-----------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "gameutils.h"
#include "gameutils.cpp";
using namespace std;

//----------------------------------------------------------------------------
//							makeExitList
//----------------------------------------------------------------------------
string makeExitList(room thisRoom) {
	string exitList = "You can go:";
	if (thisRoom.north != NO_EXIT) exitList += " north,";
	if (thisRoom.south != NO_EXIT) exitList += " south,";
	if (thisRoom.east != NO_EXIT) exitList += " east,";
	if (thisRoom.west != NO_EXIT) exitList += " west.";
	exitList[exitList.length() - 1] = '.'; // change last comma to a period
	return exitList;
} // makeExitList()

//----------------------------------------------------------------------------
//							doLook
//----------------------------------------------------------------------------
void doLook(room room, bool showShort)
{
	if (showShort)
	{
		cout << room.shortDesc << endl;
	}
	else
	{
		cout << room.longDesc << endl;
	}

	if (room.numItems == 1)
	{
		cout << "You notice the following: " << room.items[0].shortDesc << "." << endl;
	}
	else if (room.numItems > 1)
	{
		cout << "You notice the following: ";
		for (int i = 0; i < room.numItems-1; i++)
		{
			cout << room.items[i].shortDesc << ", ";
		}
		cout << room.items[room.numItems-1].shortDesc << "." << endl;
	}

	cout << makeExitList(room) << endl;
}

//----------------------------------------------------------------------------
//							doLook (overloaded)
//----------------------------------------------------------------------------
void doLook(room room)
{
	doLook(room, false);
}


//----------------------------------------------------------------------------
//							doInventory
//----------------------------------------------------------------------------
// Given: the player's inventory (partial array of items)
// This is the game's response to the "inv"/"i" (inventory) command.
// Prints a message telling the player what he/she is holding.
//----------------------------------------------------------------------------
void doInventory(item item[], int numItems) {
	if (numItems == 0)
		cout << "You don't have anything.\n";
	else {
		cout << "You are holding: ";
		for (int i = 0; i < (numItems - 1); i++)		// for all but last item
			cout << item[i].shortDesc << ", ";			// print short desc with comma
		cout << item[numItems - 1].shortDesc << ".\n";  // for last item, use period and newline
	}
} // doInventory()

//----------------------------------------------------------------------------
//							goNorth
//----------------------------------------------------------------------------
// Given:    partial array of rooms
// Modifies: index of current room
// This is the game's response to the player entering the "north"/"n" command.
// When the north exit exists, changes the current room index and performs
// a "look" command with a short room description
void goNorth(int & currentRoom, room rooms[]) {
	if (rooms[currentRoom].north == NO_EXIT)
		cout << "You can't go north.\n";
	else {
		currentRoom = rooms[currentRoom].north;
		doLook(rooms[currentRoom], true); // true = show short room desc.
	}
} // goNorth()

//----------------------------------------------------------------------------
//							goSouth
//----------------------------------------------------------------------------
// Given:    partial array of rooms
// Modifies: index of current room
// This is the game's response to the player entering the "south"/"s" command.
// When the south exit exists, changes the current room index and performs
// a "look" command with a short room description
void goSouth(int & currentRoom, room rooms[]) {
	if (rooms[currentRoom].south == NO_EXIT)
		cout << "You can't go south.\n";
	else {
		currentRoom = rooms[currentRoom].south;
		doLook(rooms[currentRoom], true); // true = show short room desc.
	}
} // goSouth()

//----------------------------------------------------------------------------
//							goEast
//----------------------------------------------------------------------------
// Given:    partial array of rooms
// Modifies: index of current room
// This is the game's response to the player entering the "east"/"e" command.
// When the east exit exists, changes the current room index and performs
// a "look" command with a short room description
void goEast(int & currentRoom, room rooms[]) {
	if (rooms[currentRoom].east == NO_EXIT)
		cout << "You can't go east.\n";
	else {
		currentRoom = rooms[currentRoom].east;
		doLook(rooms[currentRoom], true); // true = show short room desc.
	}
} // goEast()

//----------------------------------------------------------------------------
//							goWest
//----------------------------------------------------------------------------
// Given:    partial array of rooms
// Modifies: index of current room
// This is the game's response to the player entering the "west"/"w" command.
// When the west exit exists, changes the current room index and performs
// a "look" command with a short room description
void goWest(int & currentRoom, room rooms[]) {
	if (rooms[currentRoom].west == NO_EXIT)
		cout << "You can't go west.\n";
	else {
		currentRoom = rooms[currentRoom].west;
		doLook(rooms[currentRoom], true); // true = show short room desc.
	}
} // goWest()

//--------------------
//    Print logo
//--------------------
// Prints logo on screen for game start
void printLogo()
{
	cout << "--------------------------" << endl;
	cout << "       Project 2          " << endl;
	cout << "     By: Ryan Bezold      " << endl;
	cout << "--------------------------" << endl;
}

//----------------------------
//     getInputFileName
//----------------------------
//Returns: the name of the game input file
//Gets user input for the name of the game to play.
string getInputFile()
{
	string gameName;
	cout << "Enter name of game to play: ";
	cin >> gameName;
	return gameName;
}

//-------------------------
//       initItems        
//-------------------------
//Modifies: A partial array of item Structures
//This function initializes a list of items for future use. It should set the short and long descriptions of all
//elements of the array to empty string, and sets the number of items to 0
void initItems(int & numItems, item items[])
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		items[i].shortDesc = "";
		items[i].longDesc = "";
	}
	numItems = 0;
}

//-------------------------
//       initRooms        
//-------------------------
//Modifies: A partial array of room Structures
//This function initializes a list of rooms for future use. It should sets the short and long descriptions of all
//elements of the array to empty string, the north / south / east / west exits values to NO_EXIT, and invoke
//initItems() on the room’s item list.
void initRooms(room rooms[])
{
	for (int i = 0; i < MAX_ROOMS; i++)
	{
		rooms[i].shortDesc = "";
		rooms[i].longDesc = "";
		rooms[i].north = NO_EXIT;
		rooms[i].south = NO_EXIT;
		rooms[i].east = NO_EXIT;
		rooms[i].west = NO_EXIT;
		initItems(rooms[i].numItems, rooms[i].items);
	}

}

//--------------------
//    initWinData    
//--------------------
//Modifies: a winDataStruct structure
//This function initializes the win data of the game. It should set the win message to an empty string, set
//the win room index to NO_EXIT, and invoke initItems() on the list of win items.
void initWinData(winDataStruct & winData)
{
	winData.winMessage = "";
	winData.winRoom = NO_EXIT;
	initItems(winData.numWinItems, winData.winItem);
}

//--------------------
//    removeItem    
//--------------------
//Given: Index into the item list of the item to remove
//Modifies: a partial array of items
//Returns: the item removed
//The function should check that the given index is valid. If not, it invokes gameAbort() with the message:
//removeItem: invalid index = n where n is the given index.It should remove the indexed item from the
//list by “sliding down” items in the list of a higher index.It should return a copy of the removed item.
item removeItem(int index, item items[], int & numItems)
{
	item rem;
	if (index < 0 || index > MAX_ITEMS)
	{
		string errorMessage = "removeItem: invalid index = " + index;
		gameAbort(errorMessage);
		
	}
	rem = items[index];
	for (int i = index; i < numItems; i++)
	{
		items[i] = items[i + 1];
	}
	
	numItems--;
	return rem;
}

//--------------------
//    addItem    
//--------------------
void addItem(item newItem, item items[], int & numItems)
{
	if (numItems > MAX_ITEMS)
	{
		string errorMessage = "addItem: maximum number of items exceeded!";
		gameAbort(errorMessage);
	}
	numItems++;
	
	items[numItems-1] = newItem;
}

//---------------------------
//    addItem (overloaded)    
//---------------------------
void addItem(string shortDesc, string longDesc, item items[], int & numItems)
{
	item newItem;
	newItem.shortDesc = shortDesc;
	newItem.longDesc = longDesc;
	addItem(newItem, items, numItems);
}


//--------------------
//    getCmd    
//--------------------
string getCmd(string & remainder)
{
	string input;
	cout << "====> ";
	if (cin.peek() == '\n') cin.ignore();
	getline(cin, input);
	input = split(input, remainder);
	
	return input;
}

//------------------
//     findItem
//------------------
int findItem(string itemName, item items[], int numItems)
{
	for (int i = 0; i <= numItems; i++)//For every item
	{
		if (items[i].shortDesc == itemName)//the item is the item we are looking for
		{

			return i;
		}
	}
	return NOT_FOUND;
}

//------------------
//     doExamine
//------------------
void doExamine(string itemName, item roomInventory[], item playerInventory[], int numItems, int numRoomItems)
{
	int itemNdx = findItem(itemName, roomInventory, numRoomItems);
	if (itemNdx > -1)//Item is found in room
		cout << roomInventory[itemNdx].longDesc << endl;
	else//Item is not found in room
	{
		itemNdx = findItem(itemName, playerInventory, numItems);
		if (itemNdx != -1)//Item is found in playerInventory
			cout << playerInventory[itemNdx].longDesc << endl;
		else //Item is not found in playerInventory
			cout << "You see no " << itemName << endl;
	}
	
}

//-----------
// doTake
//-----------
void doTake(string itemName, item roomInventory[], item playerInventory[], int & numItems, int & numRoomItems)
{
	int itemNdx = findItem(itemName, roomInventory, numRoomItems);
	item Item;
	//cout << "Item is at: " << itemNdx << endl; // <-----DEBUG TOOLS-----
	if (itemNdx != -1) //Item is found
	{
		//cout << "Item is found" << endl; <-----DEBUG TOOLS-----
		if (numItems < MAX_ITEMS) //Player inventory is not full
		{
			Item = removeItem(itemNdx, roomInventory, numRoomItems);
			addItem(Item, playerInventory, numItems);
			cout << "You take the " << itemName << endl;
		}
		else //Player inventory is full
		{
			cout << "Your hands are full, you can't take that." << endl;
		}
	}
	else //Item is not found
	{
		itemNdx = findItem(itemName, playerInventory, numItems);
		if (itemNdx != -1) //Item found in player inventory
		{
			cout << "You already have the " << itemName << endl;
		}
		else //Item not found in player inventory
		{
			cout << "You see no " << itemName << endl;
		}
	}
}

//-------------
//   doDrop
//-------------
void doDrop(string itemName, item roomInventory[], item playerInventory[], int & numItems, int & numRoomItems)
{
	int itemNdx = findItem(itemName, playerInventory, numItems);
	item Item;
	if (itemNdx != -1) //Item is found
	{
		if (numRoomItems <= MAX_ITEMS) //Room's inventory is not full
		{
			Item = removeItem(itemNdx, playerInventory, numItems);
			addItem(Item.shortDesc, Item.longDesc, roomInventory, numRoomItems);
			cout << "You drop the " << itemName << endl;
		}
		else //Room inventory is full
		{
			cout << "The room is full of junk; you can't drop that." << endl;
		}
	}
	else //Item is not found
	{
		itemNdx = findItem(itemName, roomInventory, numRoomItems);
		if (itemNdx != -1) //Item found in room inventory
		{
			cout << "You don't have the " << itemName << endl;
		}
		else //Item not found in room inventory
		{
			cout << "You have no " << itemName << endl;
		}
	}
}

//----------------
//    gameWon  
//----------------
bool gameWon(winDataStruct winData, room rooms[])
{
	int itemNdex = -1;
	int collected = 0;
	for (int i = 0; i < winData.numWinItems; i++)//For each item in winData
	{
		itemNdex = findItem(winData.winItem[i].shortDesc, rooms[winData.winRoom].items, rooms[winData.winRoom].numItems); //Give the index of the item in the win room... -1 if not found
		if (itemNdex != -1)//Item is found
		{
			collected++;
		}

	}
	if (collected == winData.numWinItems)
		return true;
	else
		return false;
}

//----------------------------------------------------------------------------
//							loadData
//----------------------------------------------------------------------------
void loadData(room rooms[], int & numRooms, winDataStruct & winData) {
	// variable declarations
	ifstream f;				// input file handle
	string tag;				// first word extracted from each line
	string filename;		// name of input file
	string data;			// data read from file using cleanGetline()
	int roomNdx = -1;		// index of the "current room" being read/populated
							// this should always be numRooms-1 

	// initialize the rooms and winData
	initRooms(rooms);
	initWinData(winData);

	// get input file name and open the input file; abort on failure
	filename = getInputFile() + ".txt";
	f.open(filename);
	if (f.fail())
	{
		string message = "File not found: " + filename;
		gameAbort(message);
	}

	// read line-by-line and store data in the game data structures
	f >> tag;
	while (tag != "END:") {
		if (tag == "ROOM:") {
			numRooms++;		// starting a new room
			roomNdx++;		// increment every time numRooms is incremented
			cleanGetline(f, rooms[roomNdx].shortDesc); // short desc on remainder of ROOM: line
			cleanGetline(f, rooms[roomNdx].longDesc);  // long desc on next line by itself (no tag)
		}
		else if (tag == "ITEM:") {
			string shortDesc, longDesc;
			cleanGetline(f, shortDesc);
			cleanGetline(f, longDesc);
			addItem(shortDesc, longDesc, rooms[roomNdx].items, rooms[roomNdx].numItems);
		}
		else if (tag == "WIN_ITEM:") {

			cleanGetline(f, data);
			addItem(data, "", winData.winItem, winData.numWinItems);
		}
		else if (tag == "NORTH:")
			f >> rooms[roomNdx].north;
		else if (tag == "SOUTH:")
			f >> rooms[roomNdx].south;
		else if (tag == "EAST:")
			f >> rooms[roomNdx].east;
		else if (tag == "WEST:")
			f >> rooms[roomNdx].west;
		else if (tag == "WIN_ROOM:")
			f >> winData.winRoom;
		else if (tag == "REMARK:")
			cleanGetline(f, data);		// data is junk, throw it away
		else if (tag == "WIN_TEXT:")
			cleanGetline(f, winData.winMessage);
		else if (tag == "END:")
			f.close();
		else
			gameAbort("Unknown tag in " + filename + ": " + tag);

		// check for read failure and read the next tag
		if (f.fail())
			gameAbort("Failure while reading input file " + filename);
		f >> tag;
	}
} // loadData()

//----------------------------------
//			startup
//----------------------------------
void startup(room rooms[], item inventory[], winDataStruct & winData, int & numRooms, int & numItems)
{
	printLogo();
	cout << endl;
	printHelp();
	loadData(rooms, numRooms, winData);
	initItems(numItems, inventory);
	cout << "You fall asleep and dream of a place far away..." << endl;
	doLook(rooms[START_ROOM], false);
}


//----------------------------------------------------------------------------
//							main
//----------------------------------------------------------------------------
int main() {
	// declare data structures
	room rooms[MAX_ROOMS];
	item items[MAX_ITEMS];
	winDataStruct winData;
	// declare other variables
	string cmd;					// command entered by user (first word of input)
	string remainder;			// remainder of command entered by user
	bool gameWasWon = false;	// check with gameWon() as needed
	int numItems, numRooms = 0, roomNdx=0;

	// start up: load game data from file and initialize player inventory
	startup(rooms, items, winData, numRooms, numItems);
	
	// get first command input
	cmd = getCmd(remainder);
	// repeat until "exit" entered or the game is won
	while (cmd != "exit" && !gameWasWon) {
		if (cmd == "help")
			printHelp();
		// add cases for other commands and invocations
		else if (cmd == "look" || cmd == "l")
			doLook(rooms[roomNdx], false);
		else if (cmd == "inv" || cmd == "i")
			doInventory(items, numItems);
		else if (cmd == "exa" || cmd == "x")
			doExamine(remainder, rooms[roomNdx].items, items, numItems, rooms[roomNdx].numItems);
		else if (cmd == "take" || cmd == "t")
			doTake(remainder, rooms[roomNdx].items, items, numItems, rooms[roomNdx].numItems);
		else if (cmd == "drop" || cmd == "t")
		{
			doDrop(remainder, rooms[roomNdx].items, items, numItems, rooms[roomNdx].numItems);
		}
		else if (cmd == "north" || cmd == "n")
			goNorth(roomNdx, rooms);
		else if (cmd == "south" || cmd == "s")
			goSouth(roomNdx, rooms);
		else if (cmd == "east" || cmd == "e")
			goEast(roomNdx, rooms);
		else if (cmd == "west" || cmd == "w")
			goWest(roomNdx, rooms);
		else // the user entered an unrecognized command
			cout << "What??\n";

		// check if game was won and print win message or get next user input
		gameWasWon = gameWon(winData, rooms);
		
		if (gameWasWon)
			cout << winData.winMessage << endl;
		else
			cmd = getCmd(remainder);

	}

	system("pause");
	return 0;
}
