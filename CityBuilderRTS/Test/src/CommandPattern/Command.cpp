#include "Command.h"

bool Command::IsUndoable()
{
	return true;
}

void Command::Attach(std::shared_ptr<Observer> obs)
{
	observers.push_back(obs);
}

void Command::Detach(std::shared_ptr<Observer> obs)
{
	auto it = std::find(observers.begin(), observers.end(), obs);
	if (it != observers.end())
	{
		observers.erase(it);
	}
}

void Command::Notify()
{
	for (auto obs : observers)
	{
		obs->Update();
	}
}
