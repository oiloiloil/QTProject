#include <iostream>
#include "ChangeParentCommand.h"

using namespace std;

ChangeParentCommand::ChangeParentCommand(Component *oriNode, Component *oldParent, Component *newParent)
{
	// test git commit
	this->oriNode = oriNode;
	this->newParent = newParent;
	this->oldParent = oldParent;
}

void ChangeParentCommand::execute()
{
	NodeOperation nodeOperation;
	nodeOperation.changeParent(oriNode, newParent, childList);
}

void ChangeParentCommand::unexecute()
{
	NodeOperation nodeOperation;
	nodeOperation.unChangeParent(newParent, oriNode, childList);
}