#ifndef __WEAPON__
#define __WEAPON__
#include "Item.h"
class Weapon:Item
{
public:

	Weapon(const char *name, const char *description, Entity *parent,int maxUses,int damage);
	~Weapon();
	bool Use()override;

private:
	int _damage;
	
	
};
#endif
