#pragma once
#include "ofMain.h"
#include <functional>
#include <vector>

class Button
{
public:
	Button(string _buttonName, string _imageName, ofVec2f _scaledPosition, ofVec2f _imageSize, float _imageScale);
	~Button() = default;

	void draw();
	bool clicked(float x, float y);
	void addListener(std::function<void()>);
	string getName();

private:
	string name;
	ofImage image;
	ofVec2f scaledPosition;
	ofVec2f imageSize;
	float imageScale;
	std::vector<std::function<void()>> listeners;

};
