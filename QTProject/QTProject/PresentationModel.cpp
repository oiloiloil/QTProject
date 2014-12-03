#include "PresentationModel.h"

#define INSERT 1
#define EDIT 2

using namespace std;

PresentationModel::PresentationModel()
{

}

void PresentationModel::menuInput(int &number)
{
	do
	{
		cin >> number;
	} while (number < 0 || number > 9);
	
}

void PresentationModel::didUserSelect(int select)
{
	switch (select)
	{
	case 1:
		createMindMap();
		break;
	case 2:
		insertNode();
		showMindMap();
		break;
	case 3:		//edit node
		editNode();
		break;
	case 4:		//display mindmap
		showMindMap();
		break;
	case 5:		//save mindmap
		saveMindMap();
		break;
	case 6:		//load mind map
		loadMindMap();
		break;
	case 7:		//redo
		redoMap();
		showMindMap();
		break;
	case 8:		//undo
		undoMap();
		showMindMap();
		break;
	default:
		break;
	}
}

void PresentationModel::createMindMap()
{
	string description;
	createMindMapView();
	cin.ignore();
	getline(cin, description);

	mapModel.createMinMap(description);

	showMindMap();
}

void PresentationModel::insertNode()
{
	char select;
	int nodeID, greatID = mapModel.getGreatID();
	string description;
	if (mapModel.checkRootExist())
	{
		showMindMap();
		didUserInsertNodeID(nodeID, greatID, INSERT);		//get nodeID
		didUserInsertNodeSelect(nodeID, select, INSERT);			//get user's select
		didUserInsertNodeDescription(description);	//get node description
		didUserRequest(nodeID, greatID + 1, description, select);//新建立node的ID設成最大ID + 1
	}
}
/////////////////////////////////////////////////////////
//		type = 1為insert node
//		type = 2為edit node
/////////////////////////////////////////////////////////
void PresentationModel::didUserInsertNodeID(int &number, int greatID, int type)
{

	do			//input nodeID while nodeID can't larger than greatID
	{
		if (type == 1)
			insertNodeIDView();
		else if (type == 2)
			insertEditNodeIDView();

		cin >> number;

		if (type == 2 && number > greatID)
			nodeNotExist();
	} while (number > greatID);
}

void PresentationModel::didUserInsertNodeSelect(int nodeID, char &select, int type)
{
	do
	{
		if (type == 1)
			insertNodeView();		//input insert node selection
		else if (type == 2)
			showEditMenu();

		cin >> select;

		if (select > 99 || select < 97)
			commandError();
	} while ((select > 99 || select < 97) || checkRootSelect(nodeID, select));	//if select not a~c, loop again
}

void PresentationModel::didUserInsertNodeDescription(string &description)
{
	inputDescription();
	cin.ignore();
	getline(cin, description);				//get node description
}

bool PresentationModel::checkRootSelect(int nodeID, char select)
{
	if (nodeID == 0)
	{
		if (select == 'a')
		{
			rootInsertParentError();
			return true;
		}
			
		else if (select == 'c')
		{
			rootInsertSiblingError();
			return true;
		}

	} 

	return false;
}


//這裡greatID是新建立node的ID
void PresentationModel::didUserRequest(int nodeID, int greatID, string description, char select)
{
	switch (select)
	{
	case 'a':
		mapModel.insertParentNode(nodeID, greatID, description);
		break;
	case 'b':
		mapModel.insertChildNode(nodeID, greatID, description);
		break;
	case 'c':
		mapModel.insertSiblingNode(nodeID, greatID, description);
		break;
	default:
		break;
	}
}

//////////////////////////////////////////////////////////////
//			nodeID為要修改的node的ID
//////////////////////////////////////////////////////////////
void PresentationModel::editNode()
{
	int nodeID, greatID = mapModel.getGreatID();
	char select;
	didUserInsertNodeID(nodeID, greatID, EDIT);			//get edit node ID
	didUserInsertNodeSelect(nodeID, select, EDIT);
	if (checkEditRoot(nodeID, select))					//確認有沒有給root換parent或是刪除
		didUserEditNodeRequest(nodeID, greatID, select);
}

bool PresentationModel::checkEditRoot(int nodeID, char select)
{
	if (nodeID == 0)
	{
		if (select == 'b')
		{
			rootChangeParentError();
			return false;
		}
		else if (select == 'c')
		{
			rootDeleteError();
			return false;
		}
	}
	return true;
}

void PresentationModel::didUserInsertEditParentNodeID(int nodeID, int &parentID, int greatID)
{
	do			//input nodeID while nodeID can't larger than greatID
	{
		insertParentNodeIDView();
		cin >> parentID;

		if (parentID > greatID)
			nodeNotExist();
		else if (nodeID == parentID)
			sameNodeIDError();
	} while (parentID > greatID || nodeID == parentID);
}

void PresentationModel::didUserEditNodeRequest(int nodeID, int greatID, char select)
{
	string description;
	int parentID;
	switch (select)
	{
	case 'a':			//Edit description of node
		didUserInsertNodeDescription(description);
		mapModel.editNodeDescription(nodeID, description);
		break;
	case 'b':			//Change parent of a node
		didUserInsertEditParentNodeID(nodeID, parentID, greatID);
		mapModel.editNodeParent(nodeID, parentID);
		break;
	case 'c':			//Delete a node
		mapModel.editDeleteNode(nodeID);
		break;
	default:
		break;
	}
}

void PresentationModel::showMindMap()
{
	mapModel.showMindMap();
}

void PresentationModel::saveMindMap()
{
	showMindMap();
	mapModel.saveMindMap();
	saveMessage();
}

void PresentationModel::loadMindMap()
{
	string path;
	insertFilePath(path);
	if (mapModel.checkFileExist(path))
		mapModel.readFile(path);
	else
		fileNotExist();
}

void PresentationModel::insertFilePath(string &path)
{
	inputFilePathView();
	cin.ignore();
	getline(cin, path);				
}

void PresentationModel::redoMap()
{
	mapModel.didRedo();
}

void PresentationModel::undoMap()
{
	mapModel.didUndo();
}



bool PresentationModel::endedInput(int number)
{
	if (number == 9)
		return true;
	return false;
}


void PresentationModel::createMindMapView()
{
	cout << "Enter the node name:" << endl;
	cout << ">";
}

void PresentationModel::insertNodeIDView()
{
	cout << "Enter the node ID:" << endl;//Enter the node ID you want to do operation
	cout << ">";
}

void PresentationModel::insertEditNodeIDView()
{
	cout << "Enter the edit node ID:" << endl;//Enter the node ID you want to do operation
	cout << ">";
}

void PresentationModel::insertParentNodeIDView()
{
	cout << "Enter the parent ID:" << endl;//Enter the node ID you want to do operation
	cout << ">";
}


void PresentationModel::insertNodeView()
{
	cout << "a.Insert a parent node" << endl;
	cout << "b.Insert a child node" << endl;
	cout << "c.Insert a sibling node" << endl;
	cout << ">";
}

void PresentationModel::showEditMenu()
{
	cout << "a.Edit the description of a node" << endl;
	cout << "b.Change the parent of a node" << endl;
	cout << "c.Delete a node" << endl;
	cout << ">";
}

void PresentationModel::inputDescription()
{
	cout << "Enter the node name" << endl;
	cout << ">";
}

void PresentationModel::inputFilePathView()
{
	cout << "Please input a file path:";
}


void PresentationModel::commandError()
{
	cout << "The command is not found" << endl;
}

void PresentationModel::nodeNotExist()
{
	cout << "The node is not exist!!" << endl;
}

void PresentationModel::sameNodeIDError()
{
	cout << "You can't select itself" << endl;
}

void PresentationModel::rootChangeParentError()
{
	cout << "Root can't be changed the parent" << endl;
}

void PresentationModel::rootDeleteError()
{
	cout << "You can't delete the root" << endl;
}

void PresentationModel::fileNotExist()
{
	cout << "File is not exist!!" << endl;
}

void PresentationModel::rootInsertParentError()
{
	cout << "Root can't insert parent node" << endl;
}

void PresentationModel::rootInsertSiblingError()
{
	cout << "Root can't insert sibling node" << endl;
}

void PresentationModel::saveMessage()
{
	cout << "Save MindMap success" << endl;
}