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

	std::function<void()> testButton1 = [&] { button1(); };
	std::function<void()> testButton2 = [&] { button2(); };
	std::function<void()> testButton3 = [&] { button1(); };
	std::function<void()> testButton4 = [&] { button2(); };


	
	uim.addButton("factory1", "rightPanel", "FactoryIcon.png", true);
	uim.addListener("factory1", "rightPanel", testButton1);
	uim.addButton("factory2", "rightPanel", "FactoryIcon.png", true);
	uim.addListener("factory2", "rightPanel", testButton2);
	uim.addButton("factory3", "rightPanel", "FactoryIcon.png", true);
	uim.addButton("factory4", "rightPanel", "FactoryIcon.png", true);
	uim.addButton("factory5", "rightPanel", "FactoryIcon.png", true);
	uim.addButton("factory6", "rightPanel", "FactoryIcon.png", true);
	uim.addButton("factory7", "rightPanel", "FactoryIcon.png", true);
	uim.addButton("factory8", "rightPanel", "FactoryIcon.png", true);
	uim.addButton("factory9", "rightPanel", "FactoryIcon.png", true);
	uim.addButton("factory10", "rightPanel", "FactoryIcon.png", true);
	uim.addButton("factory11", "rightPanel", "FactoryIcon.png", true);
	uim.addButton("factory12", "rightPanel", "FactoryIcon.png", true);

	uim.addButton("factory13", "leftPanel", "FactoryIcon.png", false);
	uim.addListener("factory13", "leftPanel", testButton3);
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


void ofApp::button1(void)
{
	std::cout << "button 1!" << std::endl;
}


void ofApp::button2(void)
{
	std::cout << "button 2!" << std::endl;
}