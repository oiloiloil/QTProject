#include "Command.h"
#include "Component.h"
#include "ComponentFactory.h"
#include "CommandManager.h"
#include "gtest/gtest.h"
#include "InsertAChildNodeCmd.h"

using namespace std;

class cmdManager_Test : public ::testing::Test
{
protected:
	CommandManager cmdManager;
	ComponentFactory factory;
	Component *node;
	Component *nNode;
	virtual void SetUp()
	{
		node = factory.create("node", "Computer", 1);
		nNode = node = factory.create("node", "OS", 2);
	}
};

TEST_F(cmdManager_Test, executeTest)
{
	Command *cmd = new InsertAChildNodeCmd(node, nNode);
	cmdManager.execute(cmd);
	EXPECT_EQ(1, cmdManager.returnUndoSize());
	EXPECT_EQ(0, cmdManager.returnRedoSize());
	cmdManager.execute(cmd);
	EXPECT_EQ(2, cmdManager.returnUndoSize());
	EXPECT_EQ(0, cmdManager.returnRedoSize());

}

TEST_F(cmdManager_Test, redoTest)
{
	Command *cmd = new InsertAChildNodeCmd(node, nNode);
	cmdManager.execute(cmd);
	EXPECT_EQ(0, cmdManager.returnRedoSize());
	EXPECT_FALSE(cmdManager.redo());
}

TEST_F(cmdManager_Test, undoTest)
{
	Command *cmd = new InsertAChildNodeCmd(node, nNode);
	cmdManager.execute(cmd);
	EXPECT_FALSE(cmdManager.redo());
	EXPECT_TRUE(cmdManager.undo());
	EXPECT_FALSE(cmdManager.undo());
}