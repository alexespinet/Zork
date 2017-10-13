#include "stdafx.h"
#include "Character.h"
Character::Character(const char * name, const char * description, Entity * parent,int life=100):Entity(name,description,parent)
{
	_life = life;
}

Character::~Character()
{
}

void Character::RecieveDamage(int damage)
{
	_life -= damage;
}

int Character::GetLife() const
{
	return _life;
}

