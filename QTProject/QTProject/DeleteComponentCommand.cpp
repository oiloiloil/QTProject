#include <iostream>
#include "DeleteComponentCommand.h"

using namespace std;

DeleteComponentCommand::DeleteComponentCommand(Component *oriNode, Component *parent)
{
	this->oriNode = oriNode;
	this->parent = parent;
}

void DeleteComponentCommand::execute()
{
	NodeOperation nodeOperation;
	nodeOperation.deleteNode(oriNode, parent);
}

void DeleteComponentCommand::unexecute()
{
	NodeOperation nodeOperation;
	nodeOperation.unDeleteNode(oriNode, parent);
}