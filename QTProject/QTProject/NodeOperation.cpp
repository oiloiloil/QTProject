#include <iostream>
#include "NodeOperation.h"

using namespace std;

void NodeOperation::addParent(Component *node, Component *nNode)
{
	node->getParent()->setList(remove(node->getParent(), node));//update parent's child list
	node->getParent()->addChild(nNode);
	nNode->addParent(node->getParent());
	nNode->addChild(node);
	node->addParent(nNode);
}

void NodeOperation::addChild(Component *node, Component *nNode)
{
	node->addChild(nNode);
	nNode->addParent(node);
}

void NodeOperation::addSibling(Component *node, Component *nNode)
{
	node->getParent()->addChild(nNode);
	nNode->addParent(node->getParent());
}

void NodeOperation::editDescription(Component *node, string description)
{
	node->setDescription(description);
}

void NodeOperation::changeParent(Component *node, Component *newParent, list<Component *> &childList)
{
	list <Component *> tempList = node->getNodeList();
	list <Component *>::iterator i;

	//先把node裡的childnode存進childList, 
	//這些childnode放在newParent底下, 再把node的childnode移除
	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		Component *temp = *i;

		childList.push_back(temp);

		node->setList(remove(node, temp));

		node->getParent()->addChild(temp);
		temp->addParent(node->getParent());

	}

	node->getParent()->setList(remove(node->getParent(), node));

	node->addParent(newParent);
	newParent->addChild(node);
}

void NodeOperation::deleteNode(Component *node, Component *parent)
{
	list <Component *> tempList = node->getNodeList();
	list <Component *>::iterator i;

	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		Component *temp = *i;
		parent->addChild(temp);
	}
	node->getParent()->setList(remove(node->getParent(), node));
}

void NodeOperation::unDeleteNode(Component *node, Component *parent)
{
	list <Component *> tempList = node->getNodeList();
	list <Component *> tempParentList = parent->getNodeList();
	list <Component *>::iterator i;//iterator i for node's list
	list <Component *>::iterator j;//iterator j for parent's list

	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		Component *temp = *i;
		for (j = tempParentList.begin(); j != tempParentList.end(); ++j)
		{
			Component *tempNode = *j;
			if (temp->getID() == tempNode->getID())
			{
				parent->setList(remove(parent, tempNode));
			}
		}
	}
	parent->addChild(node);
}

void NodeOperation::unInsertChild(Component *node, Component *parent)
{
	parent->setList(remove(parent, node));
}

void NodeOperation::unInsertParent(Component *node, Component *nNode, Component *parent)
{
	nNode->setList(remove(nNode, node));
	parent->setList(remove(parent, nNode));
	parent->addChild(node);
	node->addParent(parent);
}

void NodeOperation::unInsertSibling(Component *nNode, Component *parent)
{
	parent->setList(remove(parent, nNode));
}

void NodeOperation::unChangeParent(Component *node, Component *newParent, list<Component *> &childList)
{
	list <Component *>::iterator i;

	Component *parent = node->getParent();
	//把node的parent底下原本在childList的node移除, 並且把childnode從childList裡拿出來放在node底下
	for (i = childList.begin(); i != childList.end(); ++i)
	{
		Component *temp = *i;

		parent->setList(remove(node->getParent(), temp));

		newParent->addChild(temp);
		temp->addParent(newParent);
	}
	childList.clear();

	parent->addChild(newParent);
	newParent->addParent(parent);

}

list<Component *> NodeOperation::remove(Component *targetNode, Component *removeNode)
{
	list <Component *> tempList = targetNode->getNodeList();
	list <Component *>::iterator i;

	for (i = tempList.begin(); i != tempList.end();)
	{
		Component *temp = *i;
		if (temp->getID() == removeNode->getID())
			i = tempList.erase(i);
		else
			++i;
	}
	return tempList;
}