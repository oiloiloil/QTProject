#pragma once
#include <iostream>
#include "Command.h"
#include "Component.h"
#include "NodeOperation.h"

using namespace std;

class MindMapModel;

class InsertASiblingNodeCmd :public Command
{
private:
	Component *node;
	Component *nNode;
public:
	InsertASiblingNodeCmd(Component *node, Component *nNode);
	void execute();
	void unexecute();
};