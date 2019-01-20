#pragma once
#include "ofMain.h"
#include "Button.h"
#include <memory>
#include <functional>

class Panel
{
public:
	Panel(string _panelName);
	~Panel() = default;

	void draw();
	void pushButton(string _buttonName, string _imageName);
	void popButton();
	void handleClick(float x, float y);
	void addListener(string _buttonName, std::function<void()> listener);
	
protected:
	std::vector<std::shared_ptr<Button>> buttons;
	std::vector<ofVec2f> buttonScaledPositions;
	int max_panel_count;
	float imageScale = 0.0625;
	ofVec2f imageSize = ofVec2f(16,16);
	string name;

	virtual void initValues() = 0;

	
};

