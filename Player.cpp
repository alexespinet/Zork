#include "stdafx.h"
#include "Player.h"
#include "Room.h"
#include "Item.h"
#include <iostream>
Player::Player(const char *name, const char *description, Entity *parent):Character(name,description,parent)
{
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
	Entity *item = _inventory->FindInChildrenByName(itemName);
	if (item == NULL)
		cout << "No existeix tal element";
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
		cout << "No existeix tal element";	
	else {
		cout << "Item dropped" << endl;
		item->SetParent(_room);
		_room->OnItemIsDropped((Item*)item);
	}
}


void Player::LookInventory() const
{
	cout << "Inventory:" << endl;
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

