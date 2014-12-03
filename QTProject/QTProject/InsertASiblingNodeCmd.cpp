#include <iostream>
#include "InsertASiblingNodeCmd.h"

using namespace std;

InsertASiblingNodeCmd::InsertASiblingNodeCmd(Component *node, Component *nNode)
{
	this->node = node;
	this->nNode = nNode;
}

void InsertASiblingNodeCmd::execute()
{
	NodeOperation nodeOperation;
	nodeOperation.addSibling(node, nNode);
}

void InsertASiblingNodeCmd::unexecute()
{
	NodeOperation nodeOperation;
	nodeOperation.unInsertSibling(nNode, nNode->getParent());
}