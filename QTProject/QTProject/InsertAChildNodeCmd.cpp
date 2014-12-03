#include <iostream>
#include "InsertAChildNodeCmd.h"

using namespace std;

InsertAChildNodeCmd::InsertAChildNodeCmd(Component *node, Component *nNode)
{
	this->node = node;
	this->nNode = nNode;
}

void InsertAChildNodeCmd::execute()
{
	NodeOperation nodeOperation;
	nodeOperation.addChild(node, nNode);
}

void InsertAChildNodeCmd::unexecute()
{
	NodeOperation nodeOperation;
	nodeOperation.unInsertChild(nNode, node);
}