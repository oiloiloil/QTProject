#include <gtest/gtest.h>
#include "Component.h"
#include "Node.h"
#include "Root.h"

using namespace std;

class rootTest : public ::testing::Test
{
protected:
	Component *root;
	virtual void SetUp()
	{
		this->root = new Root("Computer", 0);
	}

};

/*
void testGetID()
{
FAIL();
}
*/

TEST_F(rootTest, testGetID)
{
	EXPECT_EQ(0, root->getID());
}

TEST_F(rootTest, testGetDescription)
{
	EXPECT_EQ("Computer", root->getDescription());
}

TEST_F(rootTest, testSetDescription)
{
	root->setDescription("OS X");
	EXPECT_EQ("OS X", root->getDescription());
}

/*
TEST_F(rootTest, testAddParent)
{
	Component *temp = new Node("OS", 1);
	root->addParent(temp);
}

TEST_F(rootTest, testAddSibling)
{

}

TEST_F(rootTest, testDisplay)
{

}
*/