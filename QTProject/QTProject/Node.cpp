#include <iostream>
#include "Node.h"

using namespace std;


Node::Node(string newDes, int newID)
{
	description = newDes;
	ID = newID;
}

int Node::getID()
{
	return ID;
}

string Node::getDescription()
{
	return description;
}

void Node::setDescription(string newDes)
{
	description = newDes;
}

void Node::addParent(Component *node)
{
	parent = node;
}

void Node::addSibling(Component *node)
{
	parent->addChild(node);
}

Component* Node::getParent()
{
	return parent;
}

void Node::display()
{
	cout << "+-" + description + "(Node,ID: ";
	cout << ID;
	cout << ")" << endl;
}

Component* Node::clone()
{
	return new Node(*this);
}