#ifndef __ROOM__
#define __ROOM__
#include "Entity.h"
#include <vector>
class Item;
class Room:public Entity
{
public:
	Room(const char *name, const char *description, Entity *parent, bool isLocked = false, vector<Room*> exits = vector<Room*>(4, NULL));
	~Room();
	vector<Room*> _exits;

	bool IsLocked()const;

	void Unlock();

	void OnItemIsTaked(Item *item);

	void ShowItems()const;

	void OnItemIsDropped(Item *item);

private:
	bool _isLocked = false;
	list <Item*>_items;
	

};

#endif
