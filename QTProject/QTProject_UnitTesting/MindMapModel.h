#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Component.h"
#include "CommandManager.h"
#include "EditComponentCommand.h"
#include "ChangeParentCommand.h"
#include "DeleteComponentCommand.h"
#include "InsertAChildNodeCmd.h"
#include "InsertAParentNodeCmd.h"
#include "InsertASiblingNodeCmd.h"
#include "ComponentFactory.h"

using namespace std;

class MindMapModel
{
private:
	Component *root;
	ComponentFactory factory;
	CommandManager cmdManager;
	Command *cmd;
public:
	bool checkRootExist();
	Component* returnRoot();
	void createMinMap(string description);

	void insertParentNode(int nodeID, int greatID, string description);
	void insertChildNode(int nodeID, int greatID, string description);
	void insertSiblingNode(int nodeID, int greatID, string description);

	Component* createNode(string description, int ID);
	void didUserSelect(int nodeID, int greatID, char userSelect, string description);//!
	void insertNode(Component *node, Component *nNode, char userSelect);//!

	int getGreatID();
	void getNodeList(list <Component *> nodeList, list <Component *> &resultList);
	Component* findTargetNode(int ID, Component *node);
	bool findNode(int ID, Component *node);
	list<Component *> remove(Component *targetNode, Component *removeNode);

	void editNodeDescription(int nodeID, string newDescription);
	void editNodeParent(int nodeID, int parentID);
	void editDeleteNode(int nodeID);

	void didRedo();
	void didUndo();

	void readFile(string path);
	bool checkFileExist(string path);
	void handleFile(fstream &file, string data[50][50]);
	void createMindMap(string data[50][50]);
	bool findNodeInList(int nodeID, list<Component *>tempList);
	Component* getNodeInList(int nodeID, list<Component *>tempList);

	void saveMindMap();
	void showMindMap();
	void myDisplay(Component *node, string space);

	void cutNode();
	void copyNode(int nodeID);
	void pasteNode();
};