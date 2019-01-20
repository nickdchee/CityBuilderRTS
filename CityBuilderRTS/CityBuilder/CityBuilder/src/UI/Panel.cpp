#include "Panel.h"
#include "Button.h"

Panel::Panel(string _panelName) : name(_panelName)
{
}

void Panel::draw()
{
	for (auto button : buttons)
	{
		button->draw();
	}
}

void Panel::pushButton(string _buttonName, string _imageName)
{
	if (buttons.size() >= max_panel_count) { 
		std::cout << "ERROR: COULD NOT ADD BUTTON TO PANEL!" << std::endl;
		return; 
	}
	ofVec2f buttonScaledPos = buttonScaledPositions[buttons.size()];
	std::shared_ptr<Button> button = std::shared_ptr<Button>(
		new Button(_buttonName, _imageName, buttonScaledPos, imageSize, imageScale));
	buttons.push_back(button);
}

void Panel::popButton()
{
	buttons.pop_back();
}

void Panel::handleClick(float x, float y)
{
	for (auto button : buttons)
	{
		button->clicked(x, y);
	}
}

void Panel::addListener(string _buttonName, std::function<void()> _listener)
{
	for (auto button : buttons)
	{
		if (button->getName() == _buttonName)
		{
			button->addListener(_listener);
		}
	}
}
