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
		// regular openframeworks methods
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

		// ofx objects
		ofLight sunLight1;
		ofEasyCam cam;
		ofTrueTypeFont displayFont;

		// Display menu (just text)
		bool displayMenu;

		// all of our physical tiles
		std::vector<std::shared_ptr<Tile>> tiles;

		// uimanager that handles the bottom shelf ui
		UIManager uim;

		// button listener functions
		void factoryClicked();
		void apartmentClicked();
		void farmClicked();
		void officeClicked();
		void upgradeClicked();

		// current selected building type
		Structure::StructureType selectedBuildType = Structure::NONE;
		// tile the mouse cursor is hovering over
		std::shared_ptr<Tile> hoveredTile = nullptr;

		// all of the sounds used (edited/created by Dillon Pratt)
		ofSoundPlayer introSound;
		ofSoundPlayer backgroundMusic;
		ofSoundPlayer demoSound;
		ofSoundPlayer tapBlockedSound;
		ofSoundPlayer tapSelectSound;
		ofSoundPlayer buildSound;

		// update the resource counts (gold, foodinflow, materials, etc)
		void updateResources();

		// add x ammount of residents to the game
		void addResidents(int _num);

		// try to place residents into residence/workplace
		void placeResidents();

		// arithmetic for calculating happyness
		void updateHappiness();

		// all general variables
		int residents = 0;
		int homeless = 0;
		int jobless = 0;
		int happiness = 100;
		int gold = 500;
		int buildingMaterial = 500;
		int foodInflow = 0;

		// selecting an already placed building related
		std::shared_ptr<Tile> selectedStructureTile;

		bool gameLost = false;
		
};
