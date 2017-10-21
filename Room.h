#ifndef __ROOM__
#define __ROOM__
#include "Entity.h"
#include <vector>
#include "Definitions.h"
class Item;
class Room:public Entity
{
public:
	Room(const char *name, const char *description, Entity *parent, bool isLocked = false, Room *leftExit=NULL,Room *rightExit=NULL,Room *upExit=NULL,Room *downExit=NULL);
	virtual ~Room();

	bool IsLocked()const;

	void Unlock();

	void OnItemIsTaked(Item *item);

	void ShowItems()const;

	Room *GetExit(const Direction & direction)const;

	void OnItemIsDropped(Item *item);

private:
	bool _isLocked = false;
	list <Item*>_items;
	Room *_leftExit;

	Room *_rightExit;

	Room *_upExit;

	Room * _downExit;

	

};

#endif
