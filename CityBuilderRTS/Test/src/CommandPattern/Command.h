#pragma once
#include "../ObserverPattern/Observer.h"
#include <memory>
#include <vector>
#include <algorithm>

class Command
{
private:
	std::vector<std::shared_ptr<Observer>> observers;
public:
	Command() = default;
	virtual ~Command() = default;
	virtual void Execute() = 0;
	virtual bool IsUndoable();
	virtual void Attach(std::shared_ptr<Observer> obs);
	virtual void Detach(std::shared_ptr<Observer> obs);
	virtual void Notify();

};

