#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	// test
	ofBackground(255, 255, 255);
	ofSetVerticalSync(true);
	ofSetSmoothLighting(true);

	

	sunLight1.setPosition(0, -10000, 17500);
	sunLight1.setPointLight();
	sunLight1.setDiffuseColor(ofColor(255.f, 254.f, 224.f));
	sunLight1.setSpecularColor(ofColor(255.f, 254.f, 224.f));
	sunLight1.setAttenuation(1.0);

	material.setShininess(30);
	yellowColor.setBrightness(180.f);
	yellowColor.setSaturation(150.f);
	materialColor.setBrightness(250.f);
	materialColor.setSaturation(200.f);
	sunLight1.setAmbientColor(ofColor::black);


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
	sunLight1.enable();
	material.begin();


	for (auto tile : tiles)
	{
		ofSetColor(155);
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
	cam.end();
	ofDisableDepthTest();
	ofDisableLighting();

	ofSetColor(ofColor::white);
	mainUI.draw(0, ofGetWindowHeight() - mainUI.getHeight());
	
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
