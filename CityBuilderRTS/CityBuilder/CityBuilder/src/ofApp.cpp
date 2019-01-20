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
	light.setPosition(0, 200, 300);
	light.setAmbientColor(ofColor::lightGray);
	light.setDiffuseColor(ofColor::yellow);
	light.setSpecularColor(ofColor::white);

	ofSetSmoothLighting(true);

	sunLight1.setPosition(0, 20000, 5000);
	sunLight1.setPointLight();
	sunLight1.setDiffuseColor(ofColor(255.f, 254.f, 224.f));
	sunLight1.setSpecularColor(ofColor(255.f, 254.f, 224.f));
	sunLight1.setAttenuation(1.0);

	material.setShininess(30);
	yellowColor.setBrightness(180.f);
	yellowColor.setSaturation(150.f);
	materialColor.setBrightness(250.f);
	materialColor.setSaturation(200.f);
	sunLight1.setAmbientColor(ofColor::yellowGreen);

	sunLight2.setPosition(0, -200000, 5000);
	sunLight2.setPointLight();
	sunLight2.setAttenuation(0.9);
	sunLight2.setAmbientColor(ofColor::yellowGreen);

	moonLight1.setPosition(20000, 0, 5000);
	moonLight1.setPointLight();
	sunLight1.setDiffuseColor(ofColor(128.f, 128.f, 128.f));
	sunLight1.setSpecularColor(ofColor(128.f, 128.f, 128.f));
	moonLight1.setAttenuation(1.0);

	moonLight2.setPosition(-20000, 0, 5000);
	moonLight2.setPointLight();
	//moonLight2.setAttenuation(0.5);
	moonLight2.setAmbientColor(ofColor::blue);

	//moonLight.setDirectional();
	//moonLight.lookAt(ofVec3f(0, 0, 0));
	//moonLight.setAmbientColor(ofColor(128));
	//moonLight.setOrientation(ofVec3f(0, 0, 0));


	//sunLight.rotateDeg(90, sunLight.getXAxis());
	//moonLight.rotateDeg(90, moonLight.getXAxis());

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
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	//ofEnableAntiAliasing();


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

	// display materials testing
	gold = 0;
	silver = 0;
	bronze = 0;
	lumber = 0;
	displayFont.load("VCR_OSD_MONO_1.001.ttf", 20);

	// display menu testing

	displayMenu = false;
	std::function<void()> factoryClickedE = [&] { factoryClicked(); };
	std::function<void()> apartmentClickedE = [&] { apartmentClicked(); };

	uim.addButton("factory", "leftPanel", "FactoryIcon.png", false);
	uim.addListener("factory", "leftPanel", factoryClickedE);
	uim.addButton("apartment", "leftPanel", "ApartmentIcon.png", false);
	uim.addListener("apartment", "leftPanel", apartmentClickedE);
}

//--------------------------------------------------------------
void ofApp::update(){
	sunLight1.rotateAroundDeg(0.1, sunLight1.getXAxis(), ofVec3f(0, 0, 0));
	sunLight2.rotateAroundDeg(0.1, sunLight2.getXAxis(), ofVec3f(0, 0, 0));

	moonLight1.rotateAroundDeg(0.1, moonLight1.getXAxis(), ofVec3f(0, 0, 0));
	moonLight2.rotateAroundDeg(0.1, moonLight2.getXAxis(), ofVec3f(0, 0, 0));
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();
	cam.begin();
	sunLight1.enable();
	material.begin();
	//sunLight2.enable();
	//moonLight1.enable();
	//moonLight2.enable();
	/*
	if (sunLight1.getY() < 0)
	{
		moonLight.disable();
	}

	else {
		sunLight.disable();
	}
	*/


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
				ofSetColor(140, 27, 23);
			}
			else {
				ofSetColor(20, 94, 33);
			}
		}
		else
		{
			ofSetColor(52, 209, 226);
		}

		hoveredTile->getBoundingPlane()->draw();
	}

	material.end();
	sunLight1.disable();
	//sunLight2.disable();
	//moonLight1.disable();
	//moonLight2.disable();
	cam.end();
	ofDisableDepthTest();
	ofDisableLighting();

	uim.draw();

	// testing material display
	ofSetColor(ofColor::black);
	displayFont.drawString("Gold: " + ofToString(gold), 10,30);
	displayFont.drawString("Silver: " + ofToString(silver), 10, 30 + displayFont.getAscenderHeight());
	displayFont.drawString("Bronze: " + ofToString(bronze), 10, 30 + 2* displayFont.getAscenderHeight());
	displayFont.drawString("Lumber: " + ofToString(lumber), 10, 30 + 3 * displayFont.getAscenderHeight());


	// testing menu display
	if (displayMenu) {
		ofSetColor(ofColor::black);
		displayFont.drawString("Menu displayed!!", ofGetWindowWidth() - 230, displayFont.getAscenderHeight());
	}
	else {
		ofSetColor(ofColor::black);
		displayFont.drawString("'f1' for menu.", ofGetWindowWidth() - 230	, displayFont.getAscenderHeight()+5);
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case OF_KEY_F1:
		if (displayMenu == false) {
			displayMenu = true;
		}
		else {
			displayMenu = false;
		}
	}
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
