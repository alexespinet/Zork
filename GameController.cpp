#include "stdafx.h"
#include "GameController.h"
#include "Definitions.h"
#include <iostream>
#include "Key.h"
#include "Room.h"
GameController::GameController()
{
	GenerateWorld();

}


GameController::~GameController()
{
	for (std::vector<Room*>::const_iterator it = _rooms.begin(); it != _rooms.end(); ++it) 
		delete *it;
	_rooms.clear();
	for (std::vector<Item*>::const_iterator it = _items.begin(); it != _items.end(); ++it) 
		delete *it;

	_items.clear();

	delete _player;
}

bool GameController::ManageInput(const std::vector<std::string>& inputs)
{
	bool r = false;
	
	bool recognizedAction = true;
	bool isMoved = true;
	if (inputs.size() > 0) {
		std::string action = inputs.at(0);
		std::size_t size = 1;
		if (action.compare("Take") == 0 && inputs.size()>1) {
			_player->TakeItem(inputs.at(1).c_str());
			isMoved = false;
		}
		else if ((action.compare("Drop") == 0 || action.compare("d")==0) && inputs.size() > 1) {
			_player->DropItem(inputs.at(1).c_str());
		}
		else if (action.compare("Look") == 0 || action.compare("look") == 0) {
			_player->Parent()->LookChilds(_player);
		}
		else if (action.compare("u") == 0 || action.compare("up") == 0) {
			_player->EnterRoom(Direction::UP);
		}
		else if (action.compare("l") == 0 || action.compare("left") == 0) {
			_player->EnterRoom(Direction::LEFT);

		}
		else if (action.compare("r") == 0 || action.compare("right") == 0) {
			_player->EnterRoom(Direction::RIGHT);
		}
		else if (action.compare("d") == 0 || action.compare("down") == 0) {
			_player->EnterRoom(Direction::DOWN);
		}
		else if (action.compare("Use") == 0 && inputs.size()>1) {
			_player->UseItem(inputs.at(1).c_str());
			isMoved = false;
		}
		else if (action.compare("Inventory") == 0 || action.compare("i") == 0) {
			_player->LookInventory();
		}
		else if (action == "exit") {
			isMoved = false;
			r=true;
		}
		else
			recognizedAction = false;

	}
	else {
		recognizedAction = false;
	}
	if (!recognizedAction) {
		cout << "Not recognized action" << endl;
	}
	else if (isMoved) {
		r = _player->ActualRoom() == _exitRoom;
		if (r) {
			cout << "You have complete the game!!!!!" << endl;
		}
	}

	return r;


}

void GameController::GenerateWorld()
{
	Room *initRoom =new Room("Main", "Initial room", NULL, false);
	Room *secondRoom = new Room("Second Room", "I hope you the best bro, I do not think there's anything here..", NULL, false);
	Room *thirdRoom = new Room("Third Room", "Hi bro are you sure you are going in the right path?...", NULL,false);
	Room *fourthRoom = new Room("Fourth Room", "It may have cost you to get here, no problem bro you are a machine", NULL,false);
	Room * fifthRoom = new Room("Fifth Room", "Not bad man, you are near the exit", NULL, true);
	Room * sixthRoom = new Room("Sixth Room", "I am impressed with you my bro", NULL, false);
	Room * eighthRoom = new Room("Eighth Room", "Man... you are amazing..., this is the exit:)", NULL, true);
	Room *seventhRoom = new Room("Seventh Room", "Maybe you find something interesting here, take a look..", NULL, true);
	_exitRoom = eighthRoom;
	_rooms.resize(8);
	_rooms[0] = initRoom;
	_rooms[1] = secondRoom;
	_rooms[2] = thirdRoom;
	_rooms[3] = fourthRoom;
	_rooms[4] = fifthRoom;
	_rooms[5] = sixthRoom;
	_rooms[6] = seventhRoom;
	_rooms[7] = eighthRoom;



	initRoom->SetExit(Direction::UP, secondRoom);
	initRoom->SetExit(Direction::RIGHT, thirdRoom);
	initRoom->SetExit(Direction::DOWN, fourthRoom);
	secondRoom->SetExit(Direction::LEFT, initRoom);
	secondRoom->SetExit(Direction::DOWN, thirdRoom);
	thirdRoom->SetExit(Direction::LEFT, initRoom);
	thirdRoom->SetExit(Direction::UP, secondRoom);
	thirdRoom->SetExit(Direction::DOWN, fourthRoom);
	thirdRoom->SetExit(Direction::RIGHT, fifthRoom);
	fourthRoom->SetExit(Direction::LEFT, initRoom);
	fourthRoom->SetExit(Direction::DOWN, seventhRoom);
	fourthRoom->SetExit(Direction::UP, thirdRoom);
	fifthRoom->SetExit(Direction::LEFT, thirdRoom);
	fifthRoom->SetExit(Direction::DOWN, sixthRoom);
	seventhRoom->SetExit(Direction::UP, fourthRoom);
	eighthRoom->SetExit(Direction::UP, sixthRoom);
	sixthRoom->SetExit(Direction::UP, fifthRoom);
	sixthRoom->SetExit(Direction::DOWN, eighthRoom);

	Item *fifthRoomKey = new Key("Seventh_Room_Key", "This key opens the seventh room", fifthRoom,seventhRoom);
	Item *seventhRoomKey = new Key("Eighth_Room_Key", "This key opens the eighth room", seventhRoom, eighthRoom);
	Item * thirdRoomKey = new Key("Fifth_Room_Key", "This key opens the fifth room", thirdRoom, fifthRoom);
	Item *uselessItem = new Item("Non usable item", "Just a non usable item :)",thirdRoom,-1);
	fifthRoom->OnItemIsDropped(fifthRoomKey);
	seventhRoom->OnItemIsDropped(seventhRoomKey);
	thirdRoom->OnItemIsDropped(thirdRoomKey);
	_items.resize(4);
	_items[0] = fifthRoomKey;
	_items[1] = seventhRoomKey;
	_items[2] = thirdRoomKey;
	_items[3] = uselessItem;
	
	_player = new Player("Player", "I am the main character", initRoom);
	
}


