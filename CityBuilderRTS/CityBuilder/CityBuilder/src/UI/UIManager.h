#pragma once
#include "ofMain.h"
#include "Button.h"
#include <functional>

class UIManager
{
public:
	UIManager();
	~UIManager();
	
	void draw();
	void addButton(string _buttonName, string _panelName, string _imageName);
	void removeButton(string _buttonName);
	void addButtonListener(string _buttonName, std::function<void()>);
};

