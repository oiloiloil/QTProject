#include <iostream>
#include "Root.h"
#include "Node.h"

using namespace std;


class ComponentFactory
{
private:

public:
	Component* create(string type, string description, int nodeID);
};
