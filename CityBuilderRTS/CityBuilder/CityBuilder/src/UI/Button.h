#pragma once
#include "ofMain.h"
class Button
{
public:
	Button(string _imageName, ofVec2f _scaledPosition, ofVec2f _imageSize, float _imageScale);
	~Button();
	
	void draw();
	bool clicked(float x, float y);

private:
	ofImage image;
	ofVec2f scaledPosition;
	ofVec2f imageSize;
	float imageScale;
	std::vector<std::function<void()>> listeners;

};

