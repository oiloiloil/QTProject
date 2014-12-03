#pragma once
#include <iostream>
#include <list>
#include "Component.h"

using namespace std;

class Composite : public Component
{
private:
	list<Component *> child;
	string description;
	int ID;
	Component *parent;
	bool status;
public:
	int getID();
	void setID(int newID);
	string getDescription();
	void setDescription(string newDes);
	void addChild(Component *node);
	void addParent(Component *node);
	void addSibling(Component *node);
	list<Component *> getNodeList();
	void setList(list<Component *> list);
	Component* getParent();
	void setSelected(bool status);
	bool isSelected();
};