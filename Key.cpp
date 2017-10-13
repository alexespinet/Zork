#include "stdafx.h"
#include "Key.h"
#include "Room.h"
#include <iostream>
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
		cout << "The door of "<<_targetRoom->Name()<<" room will open automatically when you want to enter";
	}
	return b;
}
