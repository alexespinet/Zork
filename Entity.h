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

	virtual void Look()const;

	void LookChilds(const Entity * exception=NULL)const;


	bool FindInChildren(const Entity *child)const;

	Entity * FindInChildrenByName(const char *name)const;

	void RemoveChild(Entity * child);

	std::string Name()const;

	
	const Entity *Parent()const;

private:
	void AddChild(Entity *child, bool checkChildren);

private:

	std::string _name;
	std::string _description;
	Entity *_parent;
	list<Entity*> _childs;

};
#endif

