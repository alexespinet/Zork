#include "stdafx.h"
#include "Room.h"
#include "Item.h"
#include<iostream>
Room::Room(const char *name, const char *description, Entity *parent, bool isLocked, Room *leftExit, Room *rightExit, Room *upExit, Room *downExit) :Entity(name, description, parent)
{
	_isLocked = isLocked;
	_leftExit = leftExit;
	_rightExit = rightExit;
	_downExit = downExit;
	_upExit = upExit;
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
	cout << "Items in the room:" << endl;
	for (list<Item*>::const_iterator it = _items.begin(); it != _items.end(); ++it)
		(*it)->Look();

}

Room * Room::GetExit(const Direction & direction) const
{
	Room *r = NULL;
	switch (direction) {
	case Direction::UP:
		r = _upExit;
		break;
	case Direction::DOWN:
		r = _downExit;
		break;
	case Direction::LEFT:
		r = _leftExit;
		break;
	case Direction::RIGHT:
		r = _rightExit;
		break;
	}
	return r;
}

void Room::OnItemIsDropped(Item * item)
{
	_items.push_back(item);
}
