#include <gtest/gtest.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <direct.h>
#include <list>
#include "MindMapModel.h"
#include "SetTestData.h"

using namespace std;

class IntergrationTest : public ::testing::Test
{
protected:
	SetTestData set;
	fstream file;
	MindMapModel mapModel;
	virtual void SetUp()
	{
		_mkdir(".\\testdata");
		file.open("./testdata/test_file1.mm", ios::out);
		file << set.getData();
		file.close();
	}

	virtual void TearDown()
	{
		remove("testdata/test_file1.mm");
		_rmdir(".\\testdata");
	}
};

TEST_F(IntergrationTest, testLoadFileNotExist)
{
	string path = "testdata/file_not_exist.erd";
	EXPECT_FALSE(mapModel.checkFileExist(path));
}

TEST_F(IntergrationTest, testUnDoDeleteNode)
{
	string path = "./testdata/test_file1.mm";
	EXPECT_TRUE(mapModel.checkFileExist(path));
	mapModel.readFile(path);
	mapModel.insertChildNode(4, mapModel.getGreatID() + 1, "Test");
	Component *temp = mapModel.findTargetNode(mapModel.getGreatID(), mapModel.returnRoot());
	EXPECT_EQ("Test", temp->getDescription());
	mapModel.editDeleteNode(temp->getID());
	EXPECT_FALSE(mapModel.findNode(temp->getID(), mapModel.returnRoot()));
	mapModel.didUndo();
	EXPECT_TRUE(mapModel.findNode(temp->getID(), mapModel.returnRoot()));
}

TEST_F(IntergrationTest, testReDODeleteNode)
{
	string path = "./testdata/test_file1.mm";
	EXPECT_TRUE(mapModel.checkFileExist(path));
	mapModel.readFile(path);
	mapModel.insertChildNode(9, mapModel.getGreatID() + 1, "Test");
	Component *temp = mapModel.findTargetNode(mapModel.getGreatID(), mapModel.returnRoot());
	EXPECT_EQ("Test", temp->getDescription());
	mapModel.editDeleteNode(temp->getID());
	EXPECT_FALSE(mapModel.findNode(temp->getID(), mapModel.returnRoot()));
	mapModel.didUndo();
	EXPECT_TRUE(mapModel.findNode(temp->getID(), mapModel.returnRoot()));
	mapModel.didRedo();
	EXPECT_FALSE(mapModel.findNode(temp->getID(), mapModel.returnRoot()));
}

TEST_F(IntergrationTest, testChangeNodeParent)
{
	string path = "./testdata/test_file1.mm";
	EXPECT_TRUE(mapModel.checkFileExist(path));
	mapModel.readFile(path);
	mapModel.editNodeParent(1, 6);
	Component *node = mapModel.findTargetNode(1, mapModel.returnRoot());
	Component *parent = node->getParent();

	EXPECT_TRUE("Microsoft Office", node->getParent()->getDescription());
	EXPECT_TRUE("OS", parent->getDescription());

	
	mapModel.didUndo();
	node = mapModel.findTargetNode(6, mapModel.returnRoot());
	parent = node->getParent();
	EXPECT_TRUE("Windows", node->getParent()->getDescription());
	EXPECT_TRUE("OS", parent->getDescription());
	

	/*
	mapModel.didRedo();
	node = mapModel.findTargetNode(1, mapModel.returnRoot());
	parent = node->getParent();
	EXPECT_TRUE("Microsoft Office", node->getParent()->getDescription());
	EXPECT_TRUE("OS", parent->getDescription());
	*/
}

