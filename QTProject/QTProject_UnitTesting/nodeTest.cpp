#include <gtest/gtest.h>
#include "Component.h"
#include "Node.h"
#include "Root.h"

using namespace std;

class nodeTest : public ::testing::Test
{
protected:
	Component *node;
	virtual void SetUp()
	{
		this->node = new Node("OS X", 1);
	}

};

/*
void testGetID()
{
FAIL();
}
*/

TEST_F(nodeTest, testGetID)
{
	EXPECT_EQ(1, node->getID());
}

TEST_F(nodeTest, testGetDescription)
{
	EXPECT_EQ("OS X", node->getDescription());
}

TEST_F(nodeTest, testSetDescription)
{
	node->setDescription("Linux");
	EXPECT_EQ("Linux", node->getDescription());
}

TEST_F(nodeTest, testAddParent)
{
	Component *temp = new Node("OS", 2);
	node->addParent(temp);
	EXPECT_EQ(node->getParent(), temp);

}

TEST_F(nodeTest, testAddSibling)
{
	Component *parent = new Node("Computer", 2);
	Component *temp = new Node("OS", 3);
	node->addParent(parent);
	node->addSibling(temp);
	EXPECT_EQ(node->getParent()->getID(), temp->getParent()->getID());
	EXPECT_EQ(node->getParent()->getDescription(), temp->getParent()->getDescription());
}

TEST_F(nodeTest, testDisplay)
{
	
}