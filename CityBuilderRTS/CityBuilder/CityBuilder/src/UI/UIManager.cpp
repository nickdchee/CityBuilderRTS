#include "UIManager.h"



UIManager::UIManager()
{
	mainUIBack.load("MainLayout.png");
}


UIManager::~UIManager()
{
}

void UIManager::draw()
{
	ofSetColor(255);
	float w = ofGetWindowWidth();
	float h = ofGetWindowHeight();
	mainUIBack.resize(w, w / 4.92);
	mainUIBack.draw(0, ofGetWindowHeight() - mainUIBack.getHeight());
	for (auto panel : panels)
	{
		panel.second->draw();
	}
}

void UIManager::addButton(string _buttonName, string _panelName, string _imageName, bool _isRight)
{
	auto i = panels.find(_panelName);
	if (i != panels.end())
	{
		i->second->pushButton(_buttonName, _imageName);
	}
	else
	{
		if (_isRight)
		{
			panels[_panelName] = std::shared_ptr<Panel>(new RightPanel(_panelName));
			panels[_panelName]->pushButton(_buttonName, _imageName);
		}
		else
		{
			panels[_panelName] = std::shared_ptr<Panel>(new LeftPanel(_panelName));
			panels[_panelName]->pushButton(_buttonName, _imageName);
		}
	}
}

void UIManager::handleClick(float x, float y)
{
	for (auto panel : panels)
	{
		panel.second->handleClick(x, y);
	}
}

void UIManager::addListener(string _buttonName, string _panelName, std::function<void()> _listener)
{
	panels[_panelName]->addListener(_buttonName, _listener);
}
