#include <iostream>
#include <stack>
#include "Command.h"

using namespace std;

class CommandManager
{
private:
	stack<Command*> m_undoCmds;
	stack<Command*> m_redoCmds;
public:
	CommandManager();
	void execute(Command* c);
	int returnRedoSize();
	int returnUndoSize();
	bool redo();
	bool undo();
};