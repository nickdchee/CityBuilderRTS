#pragma once

#include <stack>
#include <deque>
#include <memory>
#include "Command.h"
#include "UndoableCommand.h"

/* 
 * This class could be turned into a singleton, if we need.
 */

class CommandManager
{
private:
	// limit number of UndoableCommands we keep (for the sake of memory)
	// -1 by default meaning no limit (anything <= 0 is no limit)
	int max_size;

	// our command stack (actually a double ended queue i.e. deque)
	std::deque<std::shared_ptr<Command>> commandDeque;
public:
	CommandManager(int m_size = -1);
	~CommandManager();
	void ExecuteCommand(std::shared_ptr<Command> cmd);
	void Undo();
};

