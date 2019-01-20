#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {

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
	buildSound.load("bx_Build_Building.mp3");
	buildSound.setMultiPlay(true);

	introSound.setVolume(0.4);
	introSound.play();
	backgroundMusic.setVolume(0.4);
	backgroundMusic.setLoop(true);
	backgroundMusic.play();



	// test
	ofBackground(255, 255, 255);
	ofSetVerticalSync(true);
	light.setPosition(0, 100, 500);
	cam.rotate(45, cam.getYAxis());
	cam.rotate(-35, cam.getXAxis());
	cam.removeAllInteractions();
	cam.addInteraction(ofEasyCam::TRANSFORM_TRANSLATE_XY, 0);
	cam.disableDoubleClick();
	cam.enableOrtho();
	cam.setMouseScrollSensitivity(20.0f);
	cam.setScale(0.3, 0.3, 0.3);
	cam.setCamYUpperBound(-1);
	cam.setCamYLowerBound(-1);
	cam.setPosition(0, 400, 0);
	ofSetEscapeQuitsApp(false);

	cam.setVFlip(false);
	ofEnableAlphaBlending();


	// tile stuff
	float size = 200;
	for (int i1 = 0; i1 < 10; ++i1)
	{
		for (int i2 = 0; i2 < 10; ++i2)
		{
			int r = rand() % 2;
			tiles.push_back(std::shared_ptr<Tile>(new Tile(ofVec3f(i1 * size, 0, i2 * size), (Tile::BaseType)r, size)));
		}
	}

	std::function<void()> factoryClickedE = [&] { factoryClicked(); };
	std::function<void()> apartmentClickedE = [&] { apartmentClicked(); };


	uim.addButton("factory", "leftPanel", "FactoryIcon.png", false);
	uim.addListener("factory", "leftPanel", factoryClickedE);
	uim.addButton("apartment", "leftPanel", "ApartmentIcon.png", false);
	uim.addListener("apartment", "leftPanel", apartmentClickedE);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();
	cam.begin();	
	light.enable();

	for (auto tile : tiles)
	{
		ofSetColor(150);
		if (tile->isOccupied())
		{
			tile->getStructure()->getModel()->drawFaces();
		}
		else {
			tile->getBaseModel()->drawFaces();
		}
		
	}
	if (hoveredTile != nullptr)
	{
		if (selectedBuildType != Structure::NONE)
		{
			if (hoveredTile->getType() == Tile::MOUNTAIN || hoveredTile->isOccupied())
			{
				ofSetColor(255, 0, 0);
			}
			else {
				ofSetColor(0, 255, 0);
			}
		}
		else
		{
			ofSetColor(0, 0, 255);
		}
		hoveredTile->getBoundingPlane()->draw();
	}

	cam.end();
	light.disable();
	ofDisableDepthTest();
	ofDisableLighting();

	uim.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ofKey::OF_KEY_ESC)
	{
		selectedBuildType = Structure::NONE;
		uim.resetPreview();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
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
	if (button == 2 && hoveredTile != nullptr)
	{
		switch (selectedBuildType)
		{
		case Structure::NONE :
			break;
		case Structure::APARTMENT :
			if ((hoveredTile->getType() == Tile::MOUNTAIN || hoveredTile->isOccupied())) { tapBlockedSound.play(); break; }
			hoveredTile->placeStructure(Structure::APARTMENT);
			buildSound.play();
			uim.resetPreview();
			selectedBuildType = Structure::NONE;
			break;
		case Structure::FACTORY :
			if ((hoveredTile->getType() == Tile::MOUNTAIN || hoveredTile->isOccupied())) { tapBlockedSound.play(); break; }
			hoveredTile->placeStructure(Structure::FACTORY);
			buildSound.play();
			uim.resetPreview();
			selectedBuildType = Structure::NONE;
			break;
		}
	}
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


void ofApp::factoryClicked(void)
{
	std::cout << "Factory selected!" << std::endl;
	selectedBuildType = Structure::FACTORY;
	tapSelectSound.play();
	uim.setPreview(selectedBuildType);
}


void ofApp::apartmentClicked(void)
{
	std::cout << "Appartment selected!" << std::endl;
	selectedBuildType = Structure::APARTMENT;
	tapSelectSound.play();
	uim.setPreview(selectedBuildType);
}