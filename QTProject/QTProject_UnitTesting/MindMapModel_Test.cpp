#include "MindMapModel.h"
#include "gtest/gtest.h"

using namespace std;

class MindMapModel_Test : public ::testing::Test
{
protected:
	MindMapModel mapModel;
	list<Component *> tempList;
	virtual void SetUp()
	{
	}
};

TEST_F(MindMapModel_Test, rootExistTest)
{
	EXPECT_FALSE(mapModel.checkRootExist());
	mapModel.createMinMap("Hello");
	EXPECT_TRUE(mapModel.checkRootExist());
}

TEST_F(MindMapModel_Test, fileExistTest)
{
	string file_not_exist = "C:/MindMap/file_not_exist.mm";
	EXPECT_FALSE(mapModel.checkFileExist(file_not_exist));
	string file_exist = "C:/MindMap/file.mm";
	EXPECT_TRUE(mapModel.checkFileExist(file_exist));
}

TEST_F(MindMapModel_Test, rootTest)
{
	EXPECT_FALSE(mapModel.checkRootExist());
	mapModel.createMinMap("rootTest");
	EXPECT_TRUE(mapModel.checkRootExist());
	Component *node = mapModel.returnRoot();
	EXPECT_EQ(0, node->getID());
	EXPECT_EQ("rootTest", node->getDescription());

}

TEST_F(MindMapModel_Test, insertChildTest)
{
	mapModel.createMinMap("root");
	mapModel.insertChildNode(0, 1, "root child");
	Component *root = mapModel.returnRoot();
	tempList = root->getNodeList();
	EXPECT_EQ(1, tempList.size());
	Component *temp = tempList.back();
	EXPECT_EQ(1, temp->getID());
	EXPECT_EQ("root child", temp->getDescription());
}

TEST_F(MindMapModel_Test, insertParentTest)
{
	mapModel.createMinMap("root");
	mapModel.insertChildNode(0, 1, "child");
	mapModel.insertParentNode(1, 2, "parent");
	Component *root = mapModel.returnRoot();
	tempList = root->getNodeList();
	EXPECT_EQ(1, tempList.size());
	Component *temp = tempList.back();
	EXPECT_EQ(2, temp->getID());
	EXPECT_EQ("parent", temp->getDescription());
	tempList = temp->getNodeList();
	temp = tempList.back();
	EXPECT_EQ(1, temp->getID());
	EXPECT_EQ("child", temp->getDescription());
}

TEST_F(MindMapModel_Test, insertSiblingTest)
{

}

TEST_F(MindMapModel_Test, createNodeTest)
{
	Component *node = mapModel.createNode("create Test", 1);
	EXPECT_EQ(1, node->getID());
	EXPECT_EQ("create Test", node->getDescription());
}

TEST_F(MindMapModel_Test, getGreatIDTest)
{
	mapModel.createMinMap("root");
	EXPECT_EQ(0, mapModel.getGreatID());
	mapModel.insertChildNode(0, 1, "child");
	EXPECT_EQ(1, mapModel.getGreatID());
}

TEST_F(MindMapModel_Test, getNodeListTest)
{

}

TEST_F(MindMapModel_Test, findTargetNodeTest)
{
	mapModel.createMinMap("root");
	mapModel.insertChildNode(0, 1, "child1");
	mapModel.insertChildNode(0, 2, "child2");
	Component *temp = mapModel.findTargetNode(0, mapModel.returnRoot());
	EXPECT_EQ(0, temp->getID());
	EXPECT_EQ("root", temp->getDescription());
	temp = mapModel.findTargetNode(1, mapModel.returnRoot());
	EXPECT_EQ(1, temp->getID());
	EXPECT_EQ("child1", temp->getDescription());
	temp = mapModel.findTargetNode(2, mapModel.returnRoot());
	EXPECT_EQ(2, temp->getID());
	EXPECT_EQ("child2", temp->getDescription());
}

TEST_F(MindMapModel_Test, findNodeTest)
{
	mapModel.createMinMap("root");
	EXPECT_TRUE(mapModel.findNode(0, mapModel.returnRoot()));
	mapModel.insertChildNode(0, 1, "child");
	EXPECT_TRUE(mapModel.findNode(1, mapModel.returnRoot()));
	EXPECT_FALSE(mapModel.findNode(2, mapModel.returnRoot()));
}

TEST_F(MindMapModel_Test, removeTest)
{

}

TEST_F(MindMapModel_Test, editNodeDescriptionTest)
{

}

TEST_F(MindMapModel_Test, editNodeParentTest)
{

}

TEST_F(MindMapModel_Test, editDeleteNodeTest)
{

}

TEST_F(MindMapModel_Test, handleFileTest)
{

}

TEST_F(MindMapModel_Test, cutTest)
{

}

TEST_F(MindMapModel_Test, copyTest)
{
	mapModel.createMinMap("root");
	mapModel.insertChildNode(0, 1, "child");
	EXPECT_EQ(1, mapModel.getGreatID());
	mapModel.copyNode(1);
	mapModel.clone->setID(2);
	EXPECT_EQ(2, mapModel.clone->getID());

}

TEST_F(MindMapModel_Test, pasteTest)
{

}
