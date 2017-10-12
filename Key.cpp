#include "stdafx.h"
#include "Key.h"
#include "Room.h"

Key::Key(const char *name, const char *description, Entity *parent, Room *room) :Item(name, description, parent, 1)
{
	_targetRoom = room;
}


Key::~Key()
{
}

bool Key::Use()
{
	bool b = Item::Use();
	if (b) {
		_targetRoom->Unlock();
	}
	return b;
}
