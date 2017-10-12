#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon(const char *name, const char *description, Entity *parent,int maxUses,int damage):Item(name,description,parent,maxUses)
{
	_damage = damage;
}


Weapon::~Weapon()
{
}

bool Weapon::Use()
{
	bool b = Item::Use();
	if (b) {


	}
	return b;
}
