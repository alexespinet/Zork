#ifndef __PLAYER__
#define __PLAYER__
#include "Character.h"
class Room;
class Item;
class Player:public Character
{
public:
	Player(const char *name, const char *description, Entity *parent);
	~Player();

	void EnterRoom(Room *room);

	void TakeItem(Item *item);

	void DropItem(Item *item);

	void LookInventory()const;

	

private:

	Entity *_inventory;

	Room *_room;

	Item * _selectedItem;

};

#endif