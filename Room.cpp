#include "stdafx.h"
#include "Room.h"
#include "Item.h"
#include<iostream>
Room::Room(const char *name, const char *description, Entity *parent, bool isLocked = false, vector<Room*> exits = vector<Room*>(4, NULL)) :Entity(name, description, parent)
{
	_isLocked = isLocked;
	_exits = exits;
}


Room::~Room()
{

}

bool Room::IsLocked() const
{
	return _isLocked;
}

void Room::Unlock()
{
	_isLocked = false;
}

void Room::OnItemIsTaked(Item * item)
{	
	_items.remove(item);
}

void Room::ShowItems() const
{
	cout << "Items in the room:"<<endl;
	for (list<Item*>::const_iterator it = _items.begin(); it != _items.end(); ++it) 
		(*it)->Look();
	
}

void Room::OnItemIsDropped(Item * item)
{
	_items.push_back(item);
}
