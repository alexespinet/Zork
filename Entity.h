#ifndef __ENTITY__
#define __ENTITY__
#include <string>
#include <list>
using namespace std;
class Entity
{
public:
	Entity(const char *name,const char *description,Entity *parent);
	virtual ~Entity();

	void SetParent(Entity *parent);

	void AddChild(Entity *child);

	bool FindInChildren(Entity *child)const;

	void RemoveChild(Entity *child);


private:

	void AddChild(Entity *child, bool checkChildren);
	std::string _name;
	std::string _description;
	Entity *_parent;
	list<Entity*> _childs;
};
#endif

