#pragma once

#include "Command.h"
class UndoableCommand : public Command
{
public:
	UndoableCommand() = default;
	virtual ~UndoableCommand() = default;
	bool IsUndoable() override;
	virtual void Undo() = 0;
};

