#ifndef __ROOM__
#define __ROOM__
#include "Entity.h"
#include <vector>
class Room:public Entity
{
public:
	Room(const char *name, const char *description, Entity *parent,bool isLocked=false);
	~Room();
	vector<Room*> _exits;

	bool IsLocked()const;

	void Unlock();

private:
	bool _isLocked = false;

};

#endif
