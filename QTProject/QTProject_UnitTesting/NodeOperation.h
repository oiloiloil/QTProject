#pragma once
#include <iostream>
#include <list>
#include "Component.h"

using namespace std;

class NodeOperation
{
private:

public:
	void addParent(Component *node, Component *nNode);
	void addChild(Component *node, Component *nNode);
	void addSibling(Component *node, Component *nNode);
	void editDescription(Component *node, string description);
	void changeParent(Component *node, Component *newParent, list<Component *> &childList);
	void deleteNode(Component *node, Component *parent);
	void unDeleteNode(Component *node, Component *parent);
	void unInsertChild(Component *node, Component *parent);
	void unInsertParent(Component *node, Component *nNode, Component *parent);
	void unInsertSibling(Component *nNode, Component *parent);
	void unChangeParent(Component *node, Component *newParent, list<Component *> &childList);
	list<Component *> remove(Component *targetNode, Component *removeNode);
};