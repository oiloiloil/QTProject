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
	virtual void setSelected(bool status) = 0;
	virtual bool isSelected() = 0;
	virtual void setCoordinate(int x, int y) = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
};