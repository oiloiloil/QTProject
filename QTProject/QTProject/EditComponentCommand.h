#pragma once
#include <iostream>
#include <string>
#include "Command.h"
#include "Component.h"
#include "NodeOperation.h"

using namespace std;


class EditComponentCommand:public Command
{
private:
	Component *node;
	string oriDes;
	string newDes;
public:
	EditComponentCommand(Component *node, string oriDes, string newDes);
	void execute();
	void unexecute();
};

