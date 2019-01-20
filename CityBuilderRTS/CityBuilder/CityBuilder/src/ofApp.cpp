#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {

	// MUSIC SETUP
	ofSoundSetVolume(0.5);
	introSound.load("bx_launch_game.mp3");
	introSound.setMultiPlay(true);
	backgroundMusic.load("bx_Charities_and_Plastic_Blocks.mp3");
	backgroundMusic.setMultiPlay(true);
	demoSound.load("bx_Demo_building.mp3");
	demoSound.setMultiPlay(true);
	tapBlockedSound.load("bx_Tap_blocked.mp3");
	tapBlockedSound.setMultiPlay(true);
	tapSelectSound.load("bx_Tap_select.mp3");
	tapSelectSound.setMultiPlay(true);
	tapSelectSound.setVolume(1.0);
	buildSound.load("bx_Build_Building.mp3");
	buildSound.setMultiPlay(true);
	introSound.setVolume(0.4);
	introSound.play();
	backgroundMusic.setVolume(0.4);
	backgroundMusic.setLoop(true);
	backgroundMusic.play();

	// ofx 3d/graphics setup
	ofBackground(255, 255, 255);
	ofSetVerticalSync(true);
	sunLight1.setPosition(-29000,-44000, 34000);
	sunLight1.setAreaLight(500, 500);
	ofSetBackgroundColor(ofColor(116, 231, 255));
	cam.rotate(45, cam.getYAxis());
	cam.rotate(-35, cam.getXAxis());
	cam.removeAllInteractions();
	cam.addInteraction(ofEasyCam::TRANSFORM_TRANSLATE_XY, 0);
	cam.disableDoubleClick();
	cam.enableOrtho();
	cam.setMouseScrollSensitivity(20.0f);
	cam.setScale(0.3,0.3,0.3);
	cam.setCamYUpperBound(-1);
	cam.setCamYLowerBound(-1);
	cam.setPosition(0, 400, 0);
	ofSetEscapeQuitsApp(false);
	cam.setVFlip(false);

	// prepare font
	displayFont.load("VCR_OSD_MONO_1.001.ttf", 20);

	// init our tiles and map
	float size = 200;
	for (int i1 = 0; i1 < 17; ++i1)
	{
		for (int i2 = 0; i2 < 10; ++i2)
		{
			int r = rand() % 2;
			if (r == 1)
			{
				int r2 = rand() % 2;
				r = r2;
			}
			tiles.push_back(std::shared_ptr<Tile>(new Tile(i1, i2, ofVec3f(i1 * size, 0, i2 * size), (Tile::BaseType)r, size)));
			uim.mapSet(i1, i2, Structure::NONE, (Tile::BaseType)r);
		}
	}


	// display menu boolean
	displayMenu = false;

	// lambda functions for button listeners
	std::function<void()> factoryClickedE = [&] { factoryClicked(); };
	std::function<void()> apartmentClickedE = [&] { apartmentClicked(); };
	std::function<void()> farmClickedE = [&] { farmClicked(); };
	std::function<void()> officeClickedE = [&] { officeClicked(); };
	std::function<void()> upgradeClickedE = [&] { upgradeClicked(); };

	// add the buttons and listeners
	uim.addButton("factory", "leftPanel", "FactoryIcon.png", false);
	uim.addListener("factory", "leftPanel", factoryClickedE);
	uim.addButton("apartment", "leftPanel", "ApartmentIcon.png", false);
	uim.addListener("apartment", "leftPanel", apartmentClickedE);
	uim.addButton("farm", "leftPanel", "FarmIcon.png", false);
	uim.addListener("farm", "leftPanel", farmClickedE);
	uim.addButton("office", "leftPanel", "OfficeIcon.png", false);
	uim.addListener("office", "leftPanel", officeClickedE);
	uim.addButton("upgrade", "rightPanel", "UpgradeIcon.png", true);
	uim.addListener("upgrade", "rightPanel", upgradeClickedE);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (happiness <= 5)
	{
		gameLost = true;
		cam.disableMouseInput();
		ofSetEscapeQuitsApp(true);
		return;
	}
	if (ofGetFrameNum() % 900 == 0) // every 15 seconds at 60fps
	{
		addResidents(rand() % 15); // add 0-15 residesnts to the game
	}
	if (ofGetFrameNum() % 1800 == 0) // every 30 seconds at 60fps
	{
		// make new calculations to update the game state
		updateHappiness();
		updateResources();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	ofEnableDepthTest();
	ofEnableLighting();
	cam.begin();
	sunLight1.enable();

	// draw the 3d tiles
	for (auto tile : tiles)
	{
		if (selectedStructureTile == tile)
		{
			ofSetColor(155, 155, 155);
			selectedStructureTile->getBoundingPlane()->draw();
		}
		tile->draw();
	}

	// draw the appropriate outline
	if (hoveredTile != nullptr)
	{
		if (selectedBuildType != Structure::NONE)
		{
			if (hoveredTile->getType() == Tile::MOUNTAIN || hoveredTile->isOccupied())
			{
				ofSetColor(224, 67, 56);
			}
			else {
				switch (selectedBuildType)
				{
				case Structure::APARTMENT :
					if (gold >= Apartment::goldCost && buildingMaterial >= Apartment::buildingMaterialCost)
					{
						ofSetColor(144, 238, 144);
					}
					else {
						ofSetColor(224, 67, 56);
					}
					break;
				case Structure::FACTORY :
					if (gold >= Factory::goldCost && buildingMaterial >= Factory::buildingMaterialCost)
					{
						ofSetColor(144, 238, 144);
					}
					else {
						ofSetColor(224, 67, 56);
					}
					break;
				case Structure::FARM :
					if (gold >= Farm::goldCost && buildingMaterial >= Farm::buildingMaterialCost)
					{
						ofSetColor(144, 238, 144);
					}
					else {
						ofSetColor(224, 67, 56);
					}
					break;
				case Structure::OFFICE :
					if (gold >= Office::goldCost && buildingMaterial >= Office::buildingMaterialCost)
					{
						ofSetColor(144, 238, 144);
					}
					else {
						ofSetColor(224, 67, 56);
					}
					break;
				}
			}
		}
		else if (hoveredTile == selectedStructureTile)
		{
			ofSetColor(155, 155, 155);
		} 
		else
		{
			ofSetColor(23, 90, 198);
		}
		hoveredTile->getBoundingPlane()->draw();
	}

	// draw outline around selected building
	if (selectedStructureTile != nullptr)
	{
		ofSetColor(155, 155, 155);
		selectedStructureTile->draw();
	}
	
	sunLight1.disable();
	cam.end();
	ofDisableDepthTest();
	ofDisableLighting();

	uim.draw();

	if (gameLost)
	{
		// draw you lost statement
		ofSetColor(ofColor::black);
		displayFont.drawString("YOU LOST! (happiness too low!)", ofGetWindowWidth()/2 - 200, ofGetWindowHeight()/2);
		return;
	}

	// display game state
	ofSetColor(ofColor::black);
	displayFont.drawString("Gold: " + ofToString(gold), 10,30);
	displayFont.drawString("Building Material: " + ofToString(buildingMaterial), 10, 30 + displayFont.getAscenderHeight());
	displayFont.drawString("Food Inflow: " + ofToString(foodInflow), 10, 30 + 2* displayFont.getAscenderHeight());
	displayFont.drawString("Happiness: " + ofToString(happiness), 10, 30 + 3 * displayFont.getAscenderHeight());
	displayFont.drawString("Residents: " + ofToString(residents), 10, 30 + 4 * displayFont.getAscenderHeight());
	displayFont.drawString("Homeless: " + ofToString(homeless), 10, 30 + 5 * displayFont.getAscenderHeight());
	displayFont.drawString("Jobless: " + ofToString(jobless), 10, 30 + 6 * displayFont.getAscenderHeight());


	// menu display for help info
	if (displayMenu) {
		ofSetColor(ofColor::black);
		int offset = 400;
		displayFont.drawString("F1 to close this menu", ofGetWindowWidth() - offset, displayFont.getAscenderHeight());
		displayFont.drawString("ESC to cancel building", ofGetWindowWidth() - offset, 2 * displayFont.getAscenderHeight());
		displayFont.drawString("Right click to place", ofGetWindowWidth() - offset, 3 * displayFont.getAscenderHeight());
		displayFont.drawString("Left click on UI/pan", ofGetWindowWidth() - offset, 4 * displayFont.getAscenderHeight());
		displayFont.drawString("Scroll to zoom", ofGetWindowWidth() - offset, 5 * displayFont.getAscenderHeight());
		displayFont.drawString("GOAL: manage population", ofGetWindowWidth() - offset, 6 * displayFont.getAscenderHeight());
	}
	else {
		ofSetColor(ofColor::black);
		displayFont.drawString("'F1' for help.", ofGetWindowWidth() - 230	, displayFont.getAscenderHeight()+5);
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (gameLost) { return; }
	switch (key) {
	case OF_KEY_F1:
		if (displayMenu == false) {
			displayMenu = true;
		}
		else {
			displayMenu = false;
		}
	}
	// clear all current actions
	if (key == ofKey::OF_KEY_ESC)
	{
		selectedBuildType = Structure::NONE;
		selectedStructureTile = nullptr;
		uim.resetSelectedTile();
		uim.resetPreview();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (gameLost) { return; }
	// do raycasting to figure out which tile the mouse is selecting
	IntersectionData id;
	ofxIntersection is;
	IsRay ray;
	ofPoint mouse(ofGetMouseX(), ofGetMouseY());
	ray.set(cam.screenToWorld(mouse), cam.getZAxis());
	for (std::shared_ptr<Tile> tile : tiles)
	{
		id = is.RayFinitePlaneIntersection(ray, *tile->getBoundingPlane());
		if (id.isIntersection) {
			hoveredTile = tile;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (gameLost) { return; }
	// if right click and a hoveredtile is known, try to place a building
	if (button == 0 && hoveredTile != nullptr && hoveredTile->isOccupied())
	{
		selectedStructureTile = hoveredTile;
		uim.setSelectedTile(selectedStructureTile);
	}
	else if (button == 2 && hoveredTile != nullptr)
	{
		switch (selectedBuildType)
		{
		case Structure::NONE :
			break;
		case Structure::APARTMENT :
			if ((hoveredTile->getType() == Tile::MOUNTAIN || hoveredTile->isOccupied())) { tapBlockedSound.play(); break; }
			if (gold >= Apartment::goldCost && buildingMaterial >= Apartment::buildingMaterialCost)
			{
				hoveredTile->placeStructure(Structure::APARTMENT);
				buildSound.play();
				placeResidents();
				uim.resetPreview();
				selectedBuildType = Structure::NONE;
				gold -= Apartment::goldCost; buildingMaterial -= Apartment::buildingMaterialCost;
				uim.mapSet(hoveredTile->getX(), hoveredTile->getY(), Structure::APARTMENT, hoveredTile->getType());
			}
			else {
				tapBlockedSound.play();
			}
			break;
		case Structure::FACTORY :
			if ((hoveredTile->getType() == Tile::MOUNTAIN || hoveredTile->isOccupied())) { tapBlockedSound.play(); break; }
			if (gold >= Factory::goldCost && buildingMaterial >= Factory::buildingMaterialCost)
			{
				hoveredTile->placeStructure(Structure::FACTORY);
				buildSound.play();
				placeResidents();
				uim.resetPreview();
				selectedBuildType = Structure::NONE;
				gold -= Factory::goldCost; buildingMaterial -= Factory::buildingMaterialCost;

				uim.mapSet(hoveredTile->getX(), hoveredTile->getY(), Structure::FACTORY, hoveredTile->getType());
			}
			else {
				tapBlockedSound.play();
			}
			break;
		case Structure::FARM:
			if ((hoveredTile->getType() == Tile::MOUNTAIN || hoveredTile->isOccupied())) { tapBlockedSound.play(); break; }
			if (gold >= Farm::goldCost && buildingMaterial >= Farm::buildingMaterialCost)
			{
				hoveredTile->placeStructure(Structure::FARM);
				buildSound.play();
				placeResidents();
				uim.resetPreview();
				selectedBuildType = Structure::NONE;
				gold -= Farm::goldCost; buildingMaterial -= Farm::buildingMaterialCost;

				uim.mapSet(hoveredTile->getX(), hoveredTile->getY(), Structure::FARM, hoveredTile->getType());
			}
			else {
				tapBlockedSound.play();
			}
			break;
		case Structure::OFFICE:
			if ((hoveredTile->getType() == Tile::MOUNTAIN || hoveredTile->isOccupied())) { tapBlockedSound.play(); break; }
			if (gold >= Office::goldCost && buildingMaterial >= Office::buildingMaterialCost)
			{
				hoveredTile->placeStructure(Structure::OFFICE);
				buildSound.play();
				placeResidents();
				uim.resetPreview();
				selectedBuildType = Structure::NONE;
				gold -= Office::goldCost; buildingMaterial -= Office::buildingMaterialCost;

				uim.mapSet(hoveredTile->getX(), hoveredTile->getY(), Structure::OFFICE, hoveredTile->getType());
			}
			else {
				tapBlockedSound.play();
			}
			break;
		}
	}
	// if the mouse is within the button shelf ui zone, handle the mouse click via the ui manager
	if (y > ofGetWindowHeight() / 4.74074074 && button == 0)
	{
		uim.handleClick(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

void ofApp::officeClicked(void)
{
	selectedBuildType = Structure::OFFICE;
	tapSelectSound.play();
	uim.setPreview(selectedBuildType);
	selectedStructureTile = nullptr;
	uim.resetSelectedTile();
}

void ofApp::upgradeClicked()
{
	if (selectedStructureTile == nullptr) { return;  }
	if (gold >= 200 && selectedStructureTile->getStructure()->isUpgradable())
	{
		gold -= 200;
		selectedStructureTile->getStructure()->upgrade();
	}
}

void ofApp::farmClicked(void)
{
	selectedBuildType = Structure::FARM;
	tapSelectSound.play();
	uim.setPreview(selectedBuildType);
	selectedStructureTile = nullptr;
	uim.resetSelectedTile();
}


void ofApp::factoryClicked(void)
{
	selectedBuildType = Structure::FACTORY;
	tapSelectSound.play();
	uim.setPreview(selectedBuildType);
	selectedStructureTile = nullptr;
	uim.resetSelectedTile();
}


void ofApp::apartmentClicked(void)
{
	selectedBuildType = Structure::APARTMENT;
	tapSelectSound.play();
	uim.setPreview(selectedBuildType);
	selectedStructureTile = nullptr;
	uim.resetSelectedTile();
}

void ofApp::updateResources()
{
	int food = 0;
	for (auto tile : tiles)
	{
		auto structure = tile->getStructure();
		if (structure == nullptr) { continue; }
		switch (structure->getType())
		{
		case Structure::OFFICE :
			gold += structure->getPPP() * structure->getNumberOfPeople();
		case Structure::FARM :
			food += structure->getPPP() * structure->getNumberOfPeople();
			break;
		case Structure::FACTORY :
			buildingMaterial += structure->getPPP() * structure->getNumberOfPeople();
			break;
		case Structure::APARTMENT :
			// no effect
			break;
		}
	}
	foodInflow = food;
}

void ofApp::addResidents(int _num)
{
	int to_place = _num;
	residents += to_place;
	vector<shared_ptr<Tile>> residential_buildings;
	vector<shared_ptr<Tile>> producing_buildings;
	for (auto tile : tiles)
	{
		if (tile->getStructure() == nullptr) { continue; }
		switch (tile->getStructure()->getType())
		{
		case Structure::FACTORY :
			if (!tile->getStructure()->isFull())
			{
				producing_buildings.push_back(tile);
			}
			break;
		case Structure::APARTMENT:
			if (!tile->getStructure()->isFull())
			{
				residential_buildings.push_back(tile);
			}
			break;
		case Structure::FARM :
			if (!tile->getStructure()->isFull())
			{
				producing_buildings.push_back(tile);
			}
			break;
		case Structure::OFFICE:
			if (!tile->getStructure()->isFull())
			{
				producing_buildings.push_back(tile);
			}
			break;
		}
	}

	while (to_place > 0)
	{
		if (residential_buildings.size() == 0)
		{
			homeless += to_place;
			break;
		}
		int r = rand() % residential_buildings.size();
		residential_buildings[r]->getStructure()->addResident();
		--to_place;
		if (residential_buildings[r]->getStructure()->isFull())
		{
			residential_buildings.erase(residential_buildings.begin() + r);
		}
	}

	to_place = _num;
	while (to_place > 0)
	{
		if (producing_buildings.size() == 0)
		{
			jobless += to_place;
			break;
		}
		int r = rand() % producing_buildings.size();
		producing_buildings[r]->getStructure()->addResident();
		--to_place;
		if (producing_buildings[r]->getStructure()->isFull())
		{
			producing_buildings.erase(producing_buildings.begin() + r);
		}
	}
}

void ofApp::placeResidents()
{
	vector<shared_ptr<Tile>> residential_buildings;
	vector<shared_ptr<Tile>> producing_buildings;
	for (auto tile : tiles)
	{
		if (tile->getStructure() == nullptr) { continue; }
		switch (tile->getStructure()->getType())
		{
		case Structure::FACTORY :
			if (!tile->getStructure()->isFull())
			{
				producing_buildings.push_back(tile);
			}
			break;
		case Structure::APARTMENT:
			if (!tile->getStructure()->isFull())
			{
				residential_buildings.push_back(tile);
			}
			break;
		case Structure::FARM :
			if (!tile->getStructure()->isFull())
			{
				producing_buildings.push_back(tile);
			}
			break;
		case Structure::OFFICE:
			if (!tile->getStructure()->isFull())
			{
				producing_buildings.push_back(tile);
			}
			break;
		}
	}

	while (homeless > 0)
	{
		if (residential_buildings.size() == 0)
		{
			break;
		}
		int r = rand() % residential_buildings.size();
		residential_buildings[r]->getStructure()->addResident();
		--homeless;
		if (residential_buildings[r]->getStructure()->isFull())
		{
			residential_buildings.erase(residential_buildings.begin() + r);
		}
	}

	while (jobless > 0)
	{
		if (producing_buildings.size() == 0)
		{
			break;
		}
		int r = rand() % producing_buildings.size();
		producing_buildings[r]->getStructure()->addResident();
		--jobless;
		if (producing_buildings[r]->getStructure()->isFull())
		{
			producing_buildings.erase(producing_buildings.begin() + r);
		}
	}

}

void ofApp::updateHappiness()
{
	int negative = (homeless * -0.5) + (jobless * -0.25);
	if (foodInflow < residents)
	{
		negative += (residents - foodInflow) * -0.5;
	}
	if (negative == 0) // if no homeless or jobless or food issues
	{
		happiness += 5;
	}
	else 
	{
		happiness += negative;
	}
	if (happiness > 100) { happiness = 100; }
	if (happiness < 0) { happiness = 0; }
}
