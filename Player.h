#ifndef __PLAYER__
#define __PLAYER__
#include "Character.h"
#include "Definitions.h"
class Room;
class Item;
class Player:public Character
{
public:
	Player(const char *name, const char *description, Entity *parent);
	virtual ~Player();

	void EnterRoom(const Direction & direction);

	void TakeItem(const char*  itemName);

	void DropItem(const char *itemName);

	void LookInventory()const;

	void UseItem(const char *itemName);

	

private:

	Entity *_inventory;

	Room *_room;

	Item * _selectedItem;

};

#endif