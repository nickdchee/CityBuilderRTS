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
	cam.setCamYUpperBound(1500);
	cam.setCamYLowerBound(300);
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
		auto t = tile.boundingTriangle;
		ofSetColor(150);
		tile.getBaseModel()->drawFaces();
		ofSetColor(0, 255, 0);
		ray.draw();
		ofSetColor(0, 0, 150, 50);
		t->draw();
		id = is.RayTriangleIntersection(*t, ray);
		if (id.isIntersection) {
			ofSetColor(255, 0, 0);
			ofDrawSphere(id.pos, 10);
		}
	}

	cam.end();
	light.disable();
	ofDisableDepthTest();

	ofSetColor(255);
	mainUI.draw(0,ofGetWindowHeight()-mainUI.getHeight());


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
