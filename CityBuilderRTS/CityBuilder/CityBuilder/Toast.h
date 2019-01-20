#pragma once
#include <string>
#include "ofxIntersection.h"
using namespace std;

class Toast
{
public:
	Toast(string message);
	~Toast();

	//Toast test
	bool toastActive;
	string msg;
	time_t start;
	ofTrueTypeFont displayFont;

	void update();
};

