#include <iostream>
#include "EditComponentCommand.h"

using namespace std;

EditComponentCommand::EditComponentCommand(Component *node, string oriDes, string newDes)
{
	this->node = node;
	this->oriDes = oriDes;
	this->newDes = newDes;
}

void EditComponentCommand::execute()
{
	NodeOperation nodeOperation;

	nodeOperation.editDescription(node, newDes);
}

void EditComponentCommand::unexecute()
{
	NodeOperation nodeOperation;

	nodeOperation.editDescription(node, oriDes);
}