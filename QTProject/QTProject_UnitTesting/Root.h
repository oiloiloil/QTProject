#pragma once
#include <iostream>
#include <string>
#include "Composite.h"

using namespace std;

class Root :public Composite
{
private:
	string description;
	int ID;
public:
	//Root(const Root&);
	Root(string newDes, int newID);
	int getID();
	string getDescription();
	void setDescription(string newDes);
	void addParent(Component *node);
	void addSibling(Component *node);
	void display();
	virtual Component* clone();
};