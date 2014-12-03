#include <gtest/gtest.h>
#include "Component.h"
#include "Node.h"
#include "Root.h"
#include "ComponentFactory.h"

using namespace std;

class factoryTest : public ::testing::Test
{
protected:
	ComponentFactory factory;
};

TEST_F(factoryTest, createTest)
{
	Component *root = new Root("Computer", 0);
	Component *node = new Node("OS", 1);
	Component *temp;
	temp = factory.create("root", "Computer", 0);
	EXPECT_EQ(root->getID(), temp->getID());
	EXPECT_EQ(root->getDescription(), temp->getDescription());
	temp = factory.create("node", "OS", 1);
	EXPECT_EQ(node->getID(), temp->getID());
	EXPECT_EQ(node->getDescription(), temp->getDescription());
	temp = factory.create("node", "OS X", 3);
	EXPECT_NE(node->getID(), temp->getID());
	EXPECT_NE(node->getDescription(), temp->getDescription());
}