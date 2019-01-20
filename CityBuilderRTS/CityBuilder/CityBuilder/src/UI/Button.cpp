#include "Button.h"

Button::Button(string _buttonName, string _imageName, ofVec2f _scaledPosition, ofVec2f _imageSize, float _imageScale) :
	name(_buttonName), scaledPosition(_scaledPosition), imageSize(_imageSize), imageScale(_imageScale)
{
	image.load(_imageName);
}

void Button::draw()
{
	float w = ofGetWindowWidth();
	float h = ofGetWindowHeight();
	ofVec2f containerSize = ofVec2f(w, w / 4.74074074);
	ofVec2f containerPosition = ofVec2f(0, ofGetWindowHeight() - containerSize.y);
	image.draw(containerPosition.x + (containerSize.x * scaledPosition.x), containerPosition.y + (containerSize.y * scaledPosition.y),
		imageScale * containerSize.x, imageScale * containerSize.x);
}

bool Button::clicked(float x, float y)
{
	float w = ofGetWindowWidth();
	float h = ofGetWindowHeight();
	ofVec2f containerSize = ofVec2f(w, w / 4.74074074);
	ofVec2f containerPosition = ofVec2f(0, ofGetWindowHeight() - containerSize.y);
	int x1, x2, y1, y2;
	x1 = containerPosition.x + (containerSize.x * scaledPosition.x);
	y1 = containerPosition.y + (containerSize.y * scaledPosition.y);
	x2 = x1 + imageScale * containerSize.x;
	y2 = y1 + imageScale * containerSize.x;
	if (x1 <= x && x <= x2 && y1 <= y && y <= y2)
	{
		for (auto listener : listeners)
		{
			listener();
		}
	}
	return (x1 <= x && x <= x2 && y1 <= y && y <= y2);
}

void Button::addListener(std::function<void()> _listener)
{
	listeners.push_back(_listener);
}

string Button::getName()
{
	return name;
}
