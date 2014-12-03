#include "CommandManager.h"

using namespace std;

CommandManager::CommandManager() 
{
	while (!m_undoCmds.empty()) {
		Command* c = m_undoCmds.top();
		m_undoCmds.pop();
		delete c;
	}
	while (!m_redoCmds.empty()) {
		Command* c = m_redoCmds.top();
		m_redoCmds.pop();
		delete c;
	}
}

void CommandManager::execute(Command* cmd) {
	cmd->execute();
	m_undoCmds.push(cmd);

	// cleanup and release redoable commands
	while (!m_redoCmds.empty()) {
		Command* c = m_redoCmds.top();
		m_redoCmds.pop();
		delete c;
	}
}

int CommandManager::returnRedoSize()
{
	return m_redoCmds.size();
}

int CommandManager::returnUndoSize()
{
	return m_undoCmds.size();
}

bool CommandManager::redo() {
	if (m_redoCmds.size() == 0)
	{
		return false;
	}
		
	else
	{
		Command* c = m_redoCmds.top();
		m_redoCmds.pop();
		c->execute(); // redo the command
		m_undoCmds.push(c);

		return true;
	}
	
}

bool CommandManager::undo() {
	if (m_undoCmds.size() == 0)
	{
		return false;
	}
		
	else
	{
		Command* c = m_undoCmds.top();
		m_undoCmds.pop();
		c->unexecute(); // undo the command
		m_redoCmds.push(c);

		return true;
	}
	
}