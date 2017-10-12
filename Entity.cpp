#include "stdafx.h"
#include "Entity.h"




Entity::Entity(const char * name, const char * description, Entity * parent)
{
	this->_name = name;
	this->_description = description;
	SetParent(parent);
}

Entity::~Entity()
{
}

void Entity::SetParent(Entity * parent)
{
	if (parent != NULL) {
		if (_parent != NULL) {
			_parent->_childs.remove(this);
		}
		else {
			parent->AddChild(this,false);
		}
	}
}

void Entity::AddChild(Entity * child)
{
	AddChild(child, true);
}

bool Entity::FindInChildren(Entity * child) const
{
	bool r = false;
	for (list<Entity*>::const_iterator it = _childs.begin(); it != _childs.end(); ++it) {
		if (*it == child) {
			r = true;
			break;
		}
	}
	return r;

}



void Entity::RemoveChild(Entity * child)
{
	bool exists = FindInChildren(child);
	if (exists) {
		_childs.remove(child);
	}
}

void Entity::AddChild(Entity * child, bool checkChildren)
{
	child->_parent = this;
	bool b = true;
	if (checkChildren)
		b = !FindInChildren(child);
	if (b)
		_childs.push_back(child);

}


