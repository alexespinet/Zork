#include "stdafx.h"
#include "Entity.h"
#include <iostream>



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
			parent->AddChild(this, false);
		}
	}
}

void Entity::Look() const
{
	cout << _name << endl << _description << endl;

}

void Entity::LookChilds() const
{
	for (list<Entity*>::const_iterator it = _childs.begin(); it != _childs.end(); ++it) {
		cout << _name << endl << _description << endl << "---------------------" << endl;

	}

}


bool Entity::FindInChildren(const Entity * child) const
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

Entity * Entity::FindInChildrenByName(const char * name) const
{
	Entity *r = NULL;
	for (list<Entity*>::const_iterator it = _childs.begin(); it != _childs.end(); ++it) {
		if ((*it)->_name.compare(name)==0) {
			r = *it;
			break;
		}
	}
	return r;

}



void Entity::RemoveChild(Entity *  child)
{
	bool exists = FindInChildren(child);
	if (exists) {
		_childs.remove(child);
	}
}

std::string Entity::Name() const
{
	return _name;
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


