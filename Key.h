#ifndef __KEY__
#define __KEY__
#include "Item.h"
class Room;
class Key:public Item
{
public:
	Key(const char *name, const char *description, Entity *parent,Room *room);
	virtual ~Key();
	bool Use()override;

private:
	Room *_targetRoom;
};
#endif

