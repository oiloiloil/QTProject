#pragma once
#include <iostream>
#include <string>
#include "Composite.h"

using namespace std;

class Node : public Composite
{
private:
	list<Component *> child;
	string description;
	int ID;
	Component *parent;
public:
	Node(string newDes, int newID);
	int getID();
	string getDescription();
	void setDescription(string newDes);
	void addParent(Component *node);
	void addSibling(Component *node);
	Component* getParent();
	void display();
};