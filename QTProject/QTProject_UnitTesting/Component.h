#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Component
{
private:

public:
	virtual int getID() = 0;
	virtual string getDescription() = 0;
	virtual void setDescription(string description);
	virtual void addChild(Component *node);
	virtual void addParent(Component *node);
	virtual void addSibling(Component *node);
	virtual list<Component *> getNodeList() = 0;
	virtual void setList(list<Component *> list) = 0;
	virtual void display();
	virtual Component* getParent() = 0;
};