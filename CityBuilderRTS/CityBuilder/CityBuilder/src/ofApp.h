#pragma once

#include "ofMain.h"

// test
#include "ofxAssimpModelLoader.h"
#include "Models/Tile.h"
#include <vector>
#include "ofxIntersection.h"
#include "UI/UIManager.h"
#include <functional>
#include "Models/Structure.h"


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
		ofLight light;
		ofLight sunLight1;
		ofLight sunLight2;
		ofLight moonLight1;
		ofLight moonLight2;
		ofEasyCam cam;

		// Shading Test
		ofMaterial material;
		ofColor yellowColor;
		ofColor materialColor;
		ofShader shader;

		// Material Display test
		int silver;
		int bronze;
		int lumber;
		ofTrueTypeFont displayFont;

		// Display menu test
		bool displayMenu;

		std::vector<std::shared_ptr<Tile>> tiles;
		std::shared_ptr<Tile> hoveredTile = nullptr;
		UIManager uim;

		void factoryClicked();
		void apartmentClicked();
		void farmClicked();
		void officeClicked();

		Structure::StructureType selectedBuildType = Structure::NONE;

		ofSoundPlayer introSound;
		ofSoundPlayer backgroundMusic;
		ofSoundPlayer demoSound;
		ofSoundPlayer tapBlockedSound;
		ofSoundPlayer tapSelectSound;
		ofSoundPlayer buildSound;


		void updateResources();

		void addResidents(int _num);
		void placeResidents();
		void updateHappiness();


		int residents = 0;
		int homeless = 0;
		int jobless = 0;

		int happiness = 100;
		int gold = 0;
		int buildingMaterial = 0;
		int foodInflow = 0;
		
};
