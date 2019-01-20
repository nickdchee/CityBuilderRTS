#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	// test
	ofBackground(255, 255, 255);
	ofSetVerticalSync(true);
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
	cam.setNearClip(0.1f);
		
	cam.setVFlip(false);

	mainUI.load("MainLayout.jpg");

	// tile stuff
	float size = 200;
	for (int i1 = 0; i1 < 10; ++i1)
	{
		for (int i2 = 0; i2 < 10; ++i2)
		{
			int r = rand() % 2;
			tiles.push_back(Tile(ofVec3f(i1 * size, 0, i2 * size), (Tile::BaseType)r, size));
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
	IntersectionData id;
	ofxIntersection is;
	IsRay ray;
	ofPoint mouse(ofGetMouseX(), ofGetMouseY());
	ray.set(cam.screenToWorld(mouse), cam.getZAxis());

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
		ofSetColor(sunLight1.getDiffuseColor());
		tile.getBaseModel()->drawFaces();
		auto t = tile.boundingPlane;
		id = is.RayFinitePlaneIntersection(ray, *t);
		if (id.isIntersection) {
			ofSetColor(255, 0, 0);
			t->draw();
		}
	}

	material.end();
	sunLight1.disable();
	//sunLight2.disable();
	//moonLight1.disable();
	//moonLight2.disable();
	cam.end();
	ofDisableDepthTest();
	ofDisableLighting();

	ofSetColor(ofColor::white);
	mainUI.draw(0, ofGetWindowHeight() - mainUI.getHeight());

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

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
	mainUI.resize(w, w/4.92);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
