#ifndef __CHARACTER__
#define __CHARACTER__
#include "Entity.h"
class Item;

class Character :public Entity
{
public:

	Character(const char* name, const char* description, Entity *parent,int life=100);
	virtual ~Character();

	void RecieveDamage(int damage);

	int GetLife()const;


private:

	int _life = 0;






};


#endif
