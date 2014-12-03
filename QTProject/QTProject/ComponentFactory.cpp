#include <iostream>
#include "ComponentFactory.h"

using namespace std;

Component* ComponentFactory::create(string type, string description, int nodeID)
{
	Component *node;
	if (type == "node")
		node = new Node(description, nodeID);
	else if (type == "root")
		node = new Root(description, 0);
	else 
		return NULL;

	return node;
}