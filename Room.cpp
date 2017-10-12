#include "stdafx.h"
#include "Room.h"


Room::Room(const char *name, const char *description, Entity *parent,bool isLocked=false):Entity(name,description,parent)
{
	_isLocked = isLocked;
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
