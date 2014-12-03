#include <gtest/gtest.h>
#include <list>
#include "Component.h"
#include "Node.h"
#include "Root.h"
#include "NodeOperation.h"

using namespace std;

void testDisplay(Component *node, string space)
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
			testDisplay(temp, space);
		}
	}

}

class nodeOperationTest : public ::testing::Test
{
protected:
	Component *root;
	Component *grandChild;
	NodeOperation nodeOperation;
	virtual void SetUp()
	{
		root = new Root("Computer", 0);
		grandChild = new Node("Windows", 3);
		root->addChild(grandChild);
		grandChild->addParent(root);

	}
	virtual void TearDown()
	{
		//free(root);
		//free(grandChild);
	}
};


TEST_F(nodeOperationTest, testAddParent)
{
	Component *child = new Node("OS", 1);
	Component *temp;
	nodeOperation.addParent(grandChild, child);

	list <Component *> tempList;
	list <Component *>::iterator i;

	tempList = root->getNodeList();
	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		temp = *i;
		EXPECT_EQ("OS", temp->getDescription());
		EXPECT_EQ(1, temp->getID());
	}

	tempList = child->getNodeList();
	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		temp = *i;
		EXPECT_EQ("Windows", temp->getDescription());
		EXPECT_EQ(3, temp->getID());
	}

}

TEST_F(nodeOperationTest, testAddChild)
{
	Component *temp = new Node("OS X", 4);
	Component *item;
	nodeOperation.addChild(grandChild, temp);

	list <Component *> tempList;

	tempList = grandChild->getNodeList();
	item = tempList.back();
	EXPECT_EQ("OS X", item->getDescription());
	EXPECT_EQ(4, item->getID());

}

TEST_F(nodeOperationTest, testAddSibling)
{
	Component *temp = new Node("Linux", 5);
	nodeOperation.addSibling(grandChild, temp);

	Component *backItem = root->getNodeList().back();
	EXPECT_EQ("Linux", backItem->getDescription());
	EXPECT_EQ(5, backItem->getID());
}

TEST_F(nodeOperationTest, testEditDescription)
{
	nodeOperation.editDescription(grandChild, "OS");
	EXPECT_EQ("OS", grandChild->getDescription());

	nodeOperation.editDescription(grandChild, "Wireless");
	EXPECT_EQ("Wireless", grandChild->getDescription());
}

TEST_F(nodeOperationTest, testChangeParent1)
{
	list<Component *> childList;
	Component *temp = new Node("OS X", 6);
	nodeOperation.addChild(grandChild, temp);
	nodeOperation.changeParent(temp, root, childList);//temp 轉到root 底下

	Component *backItem = root->getNodeList().back();
	EXPECT_EQ("OS X", backItem->getDescription());
	EXPECT_EQ(6, backItem->getID());
}

TEST_F(nodeOperationTest, testChangeParent2)
{
	list<Component *> childList;
	Component *temp = new Node("OS X", 6);
	nodeOperation.addChild(grandChild, temp);
	nodeOperation.changeParent(grandChild, temp, childList);

	Component *backItem = root->getNodeList().back();
	EXPECT_EQ("OS X", backItem->getDescription());
	EXPECT_EQ(6, backItem->getID());

	Component *nextItem = backItem->getNodeList().back();
	EXPECT_EQ("Windows", nextItem->getDescription());
	EXPECT_EQ(3, nextItem->getID());
	
}

TEST_F(nodeOperationTest, testDeleteNode)
{
	Component *temp = new Node("Office", 7);
	nodeOperation.addChild(grandChild, temp);//temp接在grandChld底下

	nodeOperation.deleteNode(grandChild, root);//刪除grandChild

	Component *backItem = root->getNodeList().back();
	ASSERT_EQ(1, root->getNodeList().size());
	EXPECT_EQ(temp, backItem);
}

TEST_F(nodeOperationTest, testUnDeleteNode)
{
	Component *temp = new Node("Office", 7);
	nodeOperation.addChild(grandChild, temp);//temp接在grandChld底下

	nodeOperation.deleteNode(grandChild, root);//刪除grandChild
	nodeOperation.unDeleteNode(grandChild, root);//復原grandChild

	Component *backItem = root->getNodeList().back();//確認root的childList的size = 1, childNode會是grandChild
	ASSERT_EQ(1, root->getNodeList().size());
	EXPECT_EQ(grandChild, backItem);
}

TEST_F(nodeOperationTest, testUnInsertChild)
{
	Component *tempNode;
	Component *temp = new Node("Office", 7);
	nodeOperation.addChild(grandChild, temp);
	nodeOperation.unInsertChild(temp, grandChild);

	list <Component *> tempList;
	list <Component *>::iterator i;
	tempList = grandChild->getNodeList();
	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		tempNode = *i;
		EXPECT_NE(tempNode, temp);
	}
}

TEST_F(nodeOperationTest, testUnInsertParent)
{
	Component *backItem;
	Component *temp = new Node("OS", 10);
	nodeOperation.addParent(grandChild, temp);
	nodeOperation.unInsertParent(grandChild, temp, root);
	
	backItem = root->getNodeList().back();
	EXPECT_EQ(grandChild, backItem);
}

TEST_F(nodeOperationTest, testUnInsertSibling)
{
	Component *tempNode;
	Component *temp = new Node("Linux", 11);
	nodeOperation.addSibling(grandChild, temp);
	nodeOperation.unInsertSibling(temp, root);

	list <Component *> tempList;
	list <Component *>::iterator i;
	tempList = root->getNodeList();
	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		tempNode = *i;
		EXPECT_NE(tempNode, temp);//確認刪除的sibling temp不在childList裡
	}

}

TEST_F(nodeOperationTest, unChangeParent_Test)
{
	list<Component *> childList;
	Component *temp = new Node("OS X", 6);
	nodeOperation.addChild(grandChild, temp);
	nodeOperation.changeParent(grandChild, temp, childList);

	Component *backItem = root->getNodeList().back();
	EXPECT_EQ("OS X", backItem->getDescription());
	EXPECT_EQ(6, backItem->getID());

	Component *nextItem = backItem->getNodeList().back();
	EXPECT_EQ("Windows", nextItem->getDescription());
	EXPECT_EQ(3, nextItem->getID());

	nodeOperation.unChangeParent(temp, grandChild, childList);
	backItem = root->getNodeList().back();
	EXPECT_EQ("Windows", backItem->getDescription());
	EXPECT_EQ(3, backItem->getID());
	nextItem = backItem->getNodeList().back();
	EXPECT_EQ("OS X", nextItem->getDescription());
	EXPECT_EQ(6, nextItem->getID());
	
}

TEST_F(nodeOperationTest, unChangeParent_Test2)
{
	list<Component *> childList;
	Component *temp = new Node("OS X", 6);
	Component *temp2 = new Node("test", 7);
	nodeOperation.addChild(grandChild, temp);
	nodeOperation.addChild(grandChild, temp2);
	nodeOperation.changeParent(grandChild, temp, childList);

	list <Component *> tempList = childList;
	list <Component *>::iterator i;
	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		Component *test = *i;
		
	}

	nodeOperation.unChangeParent(temp, grandChild, childList);
	
	Component *temp3 = root->getNodeList().back();
	EXPECT_EQ(3, temp3->getID());
	EXPECT_EQ("Windows", temp3->getDescription());
	
	tempList = temp3->getNodeList();
	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		Component *test = *i;
	}
}
