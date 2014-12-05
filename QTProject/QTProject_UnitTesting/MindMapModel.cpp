#include "MindMapModel.h"

using namespace std;

bool compare(Component *node1, Component *node2)
{
	if (node1->getID() > node2->getID())
		return false;
	else
		return true;
}

bool MindMapModel::checkRootExist()
{
	if (root == NULL)//root is not exist
		return false;
	else//root is exist
		return true;
}

Component* MindMapModel::returnRoot()
{
	return root;
}

void MindMapModel::createMinMap(string description)
{
	root = factory.create("root", description, 0);
}
///////////////////////////////////////////////////////////////////
//	nodeID 是目標node的ID，greatID是新建立node的ID
///////////////////////////////////////////////////////////////////
void MindMapModel::insertParentNode(int nodeID, int greatID, string description)
{
	Component *nNode = createNode(description, greatID);
	Component *node = findTargetNode(nodeID, root);

	cmd = new InsertAParentNodeCmd(node, nNode);
	cmdManager.execute(cmd);
}

void MindMapModel::insertChildNode(int nodeID, int greatID, string description)
{
	Component *nNode = createNode(description, greatID);
	Component *node = findTargetNode(nodeID, root);

	cmd = new InsertAChildNodeCmd(node, nNode);
	cmdManager.execute(cmd);
}

void MindMapModel::insertSiblingNode(int nodeID, int greatID, string description)
{
	Component *nNode = createNode(description, greatID);
	Component *node = findTargetNode(nodeID, root);

	cmd = new InsertASiblingNodeCmd(node, nNode);
	cmdManager.execute(cmd);
}


//nodeID : target node's ID    greatID : new node's ID
void MindMapModel::didUserSelect(int nodeID, int greatID, char userSelect, string description)
{
	Component *nNode = createNode(description, greatID);
	Component *targetNode = findTargetNode(nodeID, root);

	insertNode(targetNode, nNode, userSelect);
}

//node : targetNode    nNode : newNode  ,use 'userSelect' to choose user's action
void MindMapModel::insertNode(Component *node, Component *nNode, char userSelect)
{
	Command *cmd;

	switch (userSelect)
	{
	case 'a'://let newNode be targetNode's parentNode 
		cmd = new InsertAParentNodeCmd(node, nNode);
		cmdManager.execute(cmd);
		break;
	case 'b'://targetNode insert newNode
		cmd = new InsertAChildNodeCmd(node, nNode);
		cmdManager.execute(cmd);
		break;
	case 'c'://targetNode's parentNode insert new child node
		cmd = new InsertASiblingNodeCmd(node, nNode);
		cmdManager.execute(cmd);
		break;
	default:
		break;
	}
}

Component* MindMapModel::createNode(string description, int ID)
{
	Component *node = factory.create("node", description, ID);
	return node;
}

int MindMapModel::getGreatID()
{
	list <Component *> tempList = root->getNodeList();
	list <Component *> resultList;

	resultList.push_back(root);
	getNodeList(tempList, resultList);

	resultList.sort(compare);

	return resultList.back()->getID();
}

//遞迴把每個node的nodeList裡的node存給resultList
void MindMapModel::getNodeList(list <Component *> nodeList, list <Component *> &resultList)
{
	list <Component *>::iterator i;
	for (i = nodeList.begin(); i != nodeList.end(); ++i)
	{
		Component *temp = *i;
		resultList.push_back(temp);
		getNodeList(temp->getNodeList(), resultList);
	}
}

Component* MindMapModel::findTargetNode(int ID, Component *node)
{
	list <Component *> tempList = node->getNodeList();
	list <Component *> resultList;
	list <Component *>::iterator i;

	if (ID == node->getID())
		return node;
	else if (!tempList.empty())
	{
		getNodeList(tempList, resultList);
	}

	for (i = resultList.begin(); i != resultList.end(); i++)
	{
		Component *temp = *i;
		if (ID == temp->getID())
			return temp;
	}

}

bool MindMapModel::findNode(int ID, Component *node)
{
	list <Component *> tempList = node->getNodeList();
	list <Component *> resultList;
	list <Component *>::iterator i;

	if (ID == node->getID())//root is finded
		return true;
	else if (!tempList.empty())
	{
		getNodeList(tempList, resultList);
	}

	for (i = resultList.begin(); i != resultList.end(); i++)
	{
		Component *temp = *i;
		if (ID == temp->getID())
			return true;
	}

	return false;
}

//targetNode : parent   find parentNode's child list to remove removeNode and return list
list<Component *> MindMapModel::remove(Component *targetNode, Component *removeNode)
{
	list <Component *> tempList = targetNode->getNodeList();
	list <Component *>::iterator i;

	for (i = tempList.begin(); i != tempList.end();)
	{
		Component *temp = *i;
		if (temp->getID() == removeNode->getID())
			i = tempList.erase(i);
		else
			++i;
	}
	return tempList;
}

void MindMapModel::editNodeDescription(int nodeID, string newDescription)
{
	Component *node = findTargetNode(nodeID, root);
	cmd = new EditComponentCommand(node, node->getDescription(), newDescription);
	cmdManager.execute(cmd);
}

void MindMapModel::editNodeParent(int nodeID, int parentID)
{
	Component *node = findTargetNode(nodeID, root);
	Component *newParent = findTargetNode(parentID, root);

	cmd = new ChangeParentCommand(node, node->getParent(), newParent);

	cmdManager.execute(cmd);
}

void MindMapModel::editDeleteNode(int nodeID)
{
	Component *node = findTargetNode(nodeID, root);
	Component *parent = node->getParent();

	cmd = new DeleteComponentCommand(node, parent);

	cmdManager.execute(cmd);
}

void MindMapModel::didRedo()
{
	cmdManager.redo();
}

void MindMapModel::didUndo()
{
	cmdManager.undo();
}

void MindMapModel::readFile(string path)
{
	fstream file;
	string data[50][50];
	if (checkFileExist(path))
	{
		file.open(path, ios::in);
		handleFile(file, data);
		createMindMap(data);
	}
}

bool MindMapModel::checkFileExist(string path)
{
	fstream file;
	file.open(path, ios::in);
	if (file)
		return true;
	return false;
}

void MindMapModel::handleFile(fstream &file, string data[50][50])
{
	stringstream ss;
	int nodeID, row = 0, column;
	string description = "";

	string myString = "";//get a line of .txt

	while (!file.eof())
	{
		getline(file, myString);
		column = 0;
		for (int i = 0; i < myString.length(); i++)
		{
			nodeID = 0;
			description = "";

			////////////////////////////////////
			//get NodeID
			////////////////////////////////////
			if (myString[i] >= '0' && myString[i] <= '9')
			{
				do
				{
					nodeID *= 10;
					nodeID = nodeID + myString[i] - '0';
					i++;
				} while (myString[i] >= '0' && myString[i] <= '9');
				ss << nodeID;
				ss >> data[row][column];
				ss.clear();
				column++;
			}

			////////////////////////////////////
			//get description
			////////////////////////////////////
			if (myString[i] == '"')
			{
				do
				{
					i++;
					if (myString[i] != '"')
						description += myString[i];
				} while (myString[i] != '"');
				data[row][column] = description;
				column++;
			}
		}
		row++;
	}//end of while
}


void MindMapModel::createMindMap(string data[50][50])
{
	list<Component *>tempList;
	int childID, parentID;
	Component *parent;
	Component *child;
	for (int i = 0; i < 50; i++)
	{
		if (i == 0)//create root
		{
			createMinMap(data[0][1]);
			parent = root;
		}
		else
		{
			parentID = atoi(data[i][0].c_str());
			if (findNode(parentID, root))//parentID的node有接在root底下
			{
				parent = findTargetNode(parentID, root);
			}
			else//parentID的node沒有接在root底下
			{
				parent = createNode(data[parentID][1], parentID);
				tempList.push_back(parent);
			}
		}
		for (int j = 2; j < 50; j++)
		{
			if (data[i][j] == "")
				break;
			else if (data[i][j] != "")
			{
				childID = atoi(data[i][j].c_str());
				if (findNodeInList(childID, tempList))
					child = getNodeInList(childID, tempList);
				else
					child = createNode(data[childID][1], childID);
				insertNode(parent, child, 'b');	//!
			}
		}
	}
}

bool MindMapModel::findNodeInList(int nodeID, list<Component *>tempList)
{
	list <Component *>::iterator i;

	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		Component *temp = *i;
		if (temp->getID() == nodeID)
			return true;
	}
	return false;
}

Component* MindMapModel::getNodeInList(int nodeID, list<Component *>tempList)
{
	list <Component *>::iterator i;
	Component *temp;

	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		temp = *i;
		if (temp->getID() == nodeID)
			return temp;
	}
}

void MindMapModel::saveMindMap()
{
	list <Component *> tempList = root->getNodeList();
	list <Component *> resultList;
	list <Component *> childList;
	list <Component *>::iterator i;//iteration i use on resultList
	list <Component *>::iterator j;//iteration j use on childList

	resultList.push_back(root);
	getNodeList(tempList, resultList);
	resultList.sort(compare);

	fstream fp;

	//ios::app : input file's end
	fp.open("MindMap.txt", ios::out);
	if (!fp)
		cout << "file open failed" << endl;
	else
	{
		for (i = resultList.begin(); i != resultList.end(); ++i)//print node's ID
		{
			Component *temp = *i;
			childList = temp->getNodeList();
			fp << temp->getID() << " \"" + temp->getDescription() + "\" ";
			if (!childList.empty())
			{
				for (j = childList.begin(); j != childList.end(); ++j)
				{
					Component *child = *j;
					fp << child->getID() << " ";
				}
			}
			fp << "\n";
		}
	}
	fp.close();
}

void MindMapModel::showMindMap()
{
	cout << "The mind map " + root->getDescription() + " is dispalyed as follows:" << endl;
	myDisplay(root, "");
	cout << endl;
}

//output every node's info, use recursion let space can output enough space
void MindMapModel::myDisplay(Component *node, string space)
{
	list <Component *> tempList = node->getNodeList();
	list <Component *>::iterator i;

	node->display();
	if (!tempList.empty())
	{
		space = space + "  ";
		for (i = tempList.begin(); i != tempList.end(); ++i)
		{
			cout << space;
			Component *temp = *i;
			myDisplay(temp, space);
		}
	}
}

void MindMapModel::cutNode()
{

}

void MindMapModel::copyNode(int nodeID)
{
	Component *node = findTargetNode(nodeID, root);
	Component *clone = node->clone();
	cout << clone->getDescription();

}

void MindMapModel::pasteNode()
{

}