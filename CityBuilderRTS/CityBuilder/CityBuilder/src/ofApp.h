#pragma once

#include "ofMain.h"

// test 
#include "ofxAssimpModelLoader.h"
#include "Models/Tile.h"
#include <vector>
#include "ofxIntersection.h"
#include "UI/UIManager.h"
#include <functional>


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// test stuff
		ofLight	light;
		ofEasyCam cam;
		std::vector<Tile> tiles;
		ofImage mainUI;
		UIManager uim;

		void button1();
		void button2();
		
};
