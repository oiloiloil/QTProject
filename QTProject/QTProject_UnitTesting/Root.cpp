#include <iostream>
#include "Root.h"

using namespace std;

Root::Root(string newDes, int newID)
{
	description = newDes;
	ID = newID;
}

int Root::getID()
{
	return ID;
}

string Root::getDescription()
{
	return description;
}

void Root::setDescription(string newDes)
{
	description = newDes;
}

void Root::addParent(Component *node)
{
	cout << "Root can't insert parent node" << endl;
}

void Root::addSibling(Component *node)
{
	cout << "Root can't insert sibling node" << endl;
}

void Root::display()
{
	cout << "+-" + description + "(Root,ID: ";
	cout << ID;
	cout << ")" << endl;
}

Component* Root::clone()
{
	return new Root(*this);
}