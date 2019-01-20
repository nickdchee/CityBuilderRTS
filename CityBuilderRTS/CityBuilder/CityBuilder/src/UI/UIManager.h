#pragma once
#include "ofMain.h"
#include "Panel.h"
#include "RightPanel.h"
#include "LeftPanel.h"
#include <memory>
#include <functional>
#include "../Models/Structure.h"

class UIManager
{
public:
	UIManager();
	~UIManager();
	
	void draw();
	void addButton(string _buttonName, string _panelName, string _imageName, bool _isRight);
	void handleClick(float x, float y);
	void addListener(string _buttonName, string _panelName, std::function<void()> _listenerj);
	void setPreview(Structure::StructureType _type);
	void resetPreview();

private:
	std::unordered_map<string, std::shared_ptr<Panel>> panels;
	ofVec2f mapScaledPosition;
	ofImage mainUIBack;
	bool rightPanelCheck;
	ofImage preview;
	bool displayPreview = false;
};

