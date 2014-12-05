#include <iostream>
#include "Composite.h"

using namespace std;

int Composite::getID()
{
	return ID;
}

void Composite::setID(int newID)
{
	ID = newID;
}

string Composite::getDescription()
{
	return description;
}

void Composite::setDescription(string newDes)
{
	description = newDes;
}

void Composite::addChild(Component *node)
{
	child.push_back(node);
}

void Composite::addParent(Component *node)
{
	parent = node;
}

void Composite::addSibling(Component *node)
{
	parent->addChild(node);
	node->addParent(parent);
}

list<Component *> Composite::getNodeList()
{
	return child;
}

void Composite::setList(list<Component *> list)
{
	child = list;
}

Component* Composite::getParent()
{
	return parent;
}

void Composite::setSelected(bool status)
{
	this->status = status;
}

bool Composite::isSelected()
{
	return status;
}

void Composite::setCoordinate(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Composite::getX()
{
	return x;
}

int Composite::getY()
{
	return y;
}

Component* Composite::clone()
{
	return new Composite(*this);
}