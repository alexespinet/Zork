#include "stdafx.h"
#include "Item.h"
#include <iostream>



Item::Item(const char * name, const char * description, Entity * parent,int maxUses):Entity(name,description,parent)
{
	_maxUses = maxUses;
}

Item::~Item()
{
}

bool Item::Use()
{
	bool r = false;
	if (_maxUses==-1 || _uses < _maxUses) {
		_uses++;
		r = true;
	}
	
	return r;
}
