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
	mainUIBack.resize(w, w / 4.74074074);
	mainUIBack.draw(0, h - mainUIBack.getHeight());
	for (auto panel : panels)
	{
		panel.second->draw();
	}
	if (displayPreview)
	{
		preview.draw(w * 0.01, h - (w / 4.74074074) - (w * 0.01) - (0.0625 * w), 0.0625 * w, 0.0625 * w);
	}

	float offset = 0.01953125;
	ofVec2f base = ofVec2f(0.28125, 0.03703704);
	for (auto coord : myMap)
	{
		ofVec2f offsetV = ofVec2f(0, h - mainUIBack.getHeight()) + (base * ofVec2f(w, w / 4.74074074)) + (*coord.first * offset * ofGetWindowWidth());
		ofSetColor(coord.second);
		ofDrawRectangle(offsetV, offset * ofGetWindowWidth(), offset * ofGetWindowWidth());
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

void UIManager::setPreview(Structure::StructureType _type)
{
	displayPreview = true;
	switch (_type)
	{
	case Structure::FACTORY :
		preview.load("FactoryIcon.png");
		break;
	case Structure::APARTMENT :
		preview.load("ApartmentIcon.png");
		break;
	case Structure::FARM :
		preview.load("FarmIcon.png");
		break;
	case Structure::OFFICE:
		preview.load("OfficeIcon.png");
		break;
	}
}

void UIManager::resetPreview()
{
	displayPreview = false;
}

void UIManager::mapSet(int x, int y, Structure::StructureType _structureType, Tile::BaseType _baseType)
{
	ofColor c;
	if (_structureType == Structure::NONE)
	{
		switch (_baseType)
		{
		case Tile::MOUNTAIN :
			c = ofColor(155, 155, 155);
			break;
		case Tile::FLATLAND :
			c = ofColor(ofColor::forestGreen);
			break;
		}
	}
	else
	{
		switch (_structureType)
		{
		case Structure::APARTMENT:
			c = ofColor(153, 229, 80);
			break;
		case Structure::FACTORY:
			c = ofColor(217, 160, 102);
			break;
		case Structure::FARM:
			c = ofColor(94, 152, 255);
			break;
		case Structure::OFFICE:
			c = ofColor(215, 123, 186);
			break;
		}
	}
	myMap.insert({ shared_ptr<ofVec2f>(new ofVec2f(x,y)), c });
}
