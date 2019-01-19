#include "CommandManager.h"

CommandManager::CommandManager(int m_size) : max_size(m_size) { }

CommandManager::~CommandManager() {}

void CommandManager::ExecuteCommand(std::shared_ptr<Command> cmd)
{
	cmd->Execute();
	if (cmd->IsUndoable())
	{
		commandDeque.push_front(cmd);
	}
	if (commandDeque.size() > max_size)
	{
		commandDeque.pop_back();
	}
}
void CommandManager::Undo()
{
	if (commandDeque.size() > 0)
	{
		std::shared_ptr<Command> cmd = commandDeque.front();
		std::shared_ptr<UndoableCommand> u_cmd = std::dynamic_pointer_cast<UndoableCommand>(cmd);
		u_cmd->Undo();
		commandDeque.pop_front();
	}
}