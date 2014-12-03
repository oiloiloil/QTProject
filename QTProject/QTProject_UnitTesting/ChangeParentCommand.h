#pragma once
#include <iostream>
#include "Command.h"
#include "Component.h"
#include "NodeOperation.h"

using namespace std;

class ChangeParentCommand:public Command
{
private:
	Component *oriNode;
	Component *newParent;
	Component *oldParent;
public:
	ChangeParentCommand(Component *oriNode, Component *newParent, Component *oldParent);
	void execute();
	void unexecute();
};