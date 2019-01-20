#pragma once

#include "ofMain.h"

// test 
#include "ofxAssimpModelLoader.h"
#include "Models/Tile.h"
#include <vector>
#include "ofxIntersection.h"


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
		ofLight sunLight1;
		ofLight sunLight2;
		ofLight moonLight1;
		ofLight moonLight2;
		ofEasyCam cam;
		std::vector<Tile> tiles;
		ofImage mainUI;

		// Shading Test
		ofMaterial material;
		ofColor yellowColor;
		ofColor materialColor;
		ofShader shader;

		// Material Display test
		int gold;
		int silver;
		int bronze;
		int lumber;

		ofTrueTypeFont displayFont;

};
