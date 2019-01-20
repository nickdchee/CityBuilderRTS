#pragma once
#include "ofMain.h"
#include "Panel.h"
#include "RightPanel.h"
#include "LeftPanel.h"
#include <memory>
#include <functional>
#include "../Models/Structure.h"
#include "../Models/Tile.h"

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
	void mapSet(int x, int y, Structure::StructureType _structureType, Tile::BaseType _baseType);
	void setSelectedTile(shared_ptr<Tile> _tile);
	void resetSelectedTile();

private:
	std::unordered_map<string, std::shared_ptr<Panel>> panels;
	ofVec2f mapScaledPosition;
	ofImage mainUIBack;
	bool rightPanelCheck;
	ofImage preview;
	bool displayPreview = false;
	std::unordered_map<shared_ptr<ofVec2f>, ofColor> myMap;
	ofImage selectedPreview;
	ofImage selectedInfo;
	ofImage upgradeImage;
	ofTrueTypeFont displayFont;

	std::shared_ptr<Tile> selectedTile = nullptr;
};

