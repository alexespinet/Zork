#include "stdafx.h"
#include "Player.h"
#include "Room.h"
#include "Item.h"
#include <iostream>
Player::Player(const char *name, const char *description, Entity *parent):Character(name,description,parent)
{
	_room = (Room*)parent;
	_inventory = new Entity("Inventory", "Inventory of the player", this);
}


Player::~Player()
{
}
void Player::EnterRoom(const Direction & direction)
{
	Room *exitRoom = _room->GetExit(direction);
	if (exitRoom == NULL) {
		cout << "This direction does not exist"<<endl;
	}
	else {
		if (!exitRoom->IsLocked()) {
			_room = exitRoom;
			SetParent(exitRoom);
			cout << "You have entered to the room" << endl;
			exitRoom->Look();
		}
		else
			cout << "This room is locked" << endl;
	}
}

void Player::TakeItem(const char *itemName)
{
	Entity *item =_room->FindInChildrenByName(itemName);
	if (item == NULL)
		cout << "You can not take a non existent item"<<endl;
	else {
		cout << "Item taked" << endl;
		item->SetParent(_inventory);
		_room->OnItemIsTaked((Item*)item);
	}
}

void Player::DropItem(const char *itemName)
{
	Entity *item = _inventory->FindInChildrenByName(itemName);
	if (item == NULL)
		cout << "You can not drop a non existent item"<<endl;	
	else {
		cout << "Item dropped" << endl;
		item->SetParent(_room);
		_room->OnItemIsDropped((Item*)item);
	}
}


void Player::LookInventory() const
{
	_inventory->LookChilds();

}



void Player::UseItem(const char * itemName)
{
	Entity *item=_inventory->FindInChildrenByName(itemName);
	if (item != NULL) {
		Item *itemEntity = (Item*)item;
		itemEntity->Use();
	}
	else {
		cout << "Item not found" << endl;
	}
}

const Room *  Player::ActualRoom() const
{
	return _room;
}

