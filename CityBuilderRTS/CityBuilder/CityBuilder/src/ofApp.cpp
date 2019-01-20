#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {

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

	cam.setVFlip(false);
	ofEnableAlphaBlending();

	mainUI.load("MainLayout.png");


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
	IntersectionData id;
	ofxIntersection is;
	IsRay ray;
	ofPoint mouse(ofGetMouseX(), ofGetMouseY());
	ray.set(cam.screenToWorld(mouse), cam.getZAxis());

	ofEnableDepthTest();
	cam.begin();	
	light.enable();

	for (auto tile : tiles)
	{
		ofSetColor(150);
		tile.getBaseModel()->drawFaces();
		auto t = tile.boundingPlane;
		id = is.RayFinitePlaneIntersection(ray, *t);
		if (id.isIntersection) {
			ofSetColor(255, 0, 0);
			t->draw();
		}
	}

	cam.end();
	light.disable();
	ofDisableDepthTest();
	ofDisableLighting();

	uim.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	uim.handleClick(x, y);
	//std::cout << "x ratio: " << (float)((float)x / (float)ofGetWindowWidth()) << std::endl;
	//std::cout << "y ratio: " << (float)((float)y / (float)ofGetWindowHeight()) << std::endl;
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
}


void ofApp::apartmentClicked(void)
{
	std::cout << "Appartment selected!" << std::endl;
}