#pragma once
#include <iostream>
#include "Command.h"
#include "Component.h"
#include "NodeOperation.h"

using namespace std;


class DeleteComponentCommand:public Command
{
private:
	Component *oriNode;
	Component *parent;
public:
	DeleteComponentCommand(Component *oriNode, Component *parent);
	void execute();
	void unexecute();
};