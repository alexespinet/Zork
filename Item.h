#ifndef __ITEM__
#define __ITEM__
#include "Entity.h"
class Item:public Entity
{
public:
	Item(const char *name, const char *description, Entity *parent,int maxUses);
	~Item();

	virtual bool Use()=0;

private:
	int _maxUses=-1;
	int _uses = 0;

};
#endif
