#pragma once
#include <iostream>
#include <string>
#include "MindMapModel.h"

using namespace std;

class PresentationModel
{
private:
	MindMapModel mapModel;
public:
	PresentationModel();
	void menuInput(int &number);
	void didUserSelect(int select);

	void createMindMap();
	void insertNode();
	void didUserInsertNodeID(int &number, int GreatID, int type);
	void didUserInsertNodeSelect(int nodeID, char &select, int type);
	void didUserInsertNodeDescription(string &description);
	bool checkRootSelect(int nodeID, char select);
	void didUserRequest(int nodeID, int greatID, string description, char select);

	void editNode();
	bool checkEditRoot(int nodeID, char select);
	void didUserInsertEditParentNodeID(int nodeID, int &parentID, int greatID);
	void didUserEditNodeRequest(int nodeID, int greatID, char select);
	void showMindMap();
	void saveMindMap();
	void loadMindMap();
	void insertFilePath(string &path);
	void redoMap();
	void undoMap();

	bool endedInput(int number);

	void createMindMapView();
	void insertNodeIDView();
	void insertEditNodeIDView();
	void insertParentNodeIDView();
	void insertNodeView();
	void showEditMenu();

	void inputDescription();
	void inputFilePathView();
	void commandError();
	void nodeNotExist();
	void sameNodeIDError();
	void rootChangeParentError();
	void rootDeleteError();
	void fileNotExist();
	void rootInsertParentError();
	void rootInsertSiblingError();
	void saveMessage();
};