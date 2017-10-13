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
void Player::EnterRoom(Room * room)
{
	if (!room->IsLocked()) {
		cout<<"You have entered to the room"<<endl;
		SetParent(room);
		room->Look();
	}
	else {
		cout << "This room is locked"<<endl;
	}
}

void Player::TakeItem(Item * item)
{
	cout << "Item taked"<<endl;
	item->SetParent(_inventory);
	_room->OnItemIsTaked(item);

}

void Player::DropItem(Item * item)
{
	cout << "Item dropped"<<endl;
	item->SetParent(_room);
	_room->OnItemIsDropped(item);
}


void Player::LookInventory() const
{
	cout << "Inventory:" << endl;
	_inventory->LookChilds();

}

