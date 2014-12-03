#include <iostream>
#include "InsertAParentNodeCmd.h"

using namespace std;

InsertAParentNodeCmd::InsertAParentNodeCmd(Component *node, Component *nNode)
{
	this->node = node;
	this->nNode = nNode;
}

void InsertAParentNodeCmd::execute()
{
	NodeOperation nodeOperation;
	nodeOperation.addParent(node, nNode);
}

void InsertAParentNodeCmd::unexecute()
{
	NodeOperation nodeOperation;
	nodeOperation.unInsertParent(node, nNode, nNode->getParent());
}