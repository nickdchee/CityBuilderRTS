#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	// test
	ofBackground(255, 255, 255);
	ofSetVerticalSync(true);
	testModel.loadModel("Factory.fbx");
	testModel.setScaleNormalization(false);
	testModel.setRotation(0, 180, 1, 0, 0);
	testModel2.loadModel("Factory.fbx", 20);
	testModel2.setScaleNormalization(false);
	testModel2.setRotation(0, 180, 1, 0, 0);
	testModel2.setPosition(200, 0, 0);
	light.setPosition(0, 0, 500);
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
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();
	cam.begin();	
	light.enable();
	testModel.drawFaces();
	testModel2.drawFaces();
	cam.end();
	light.disable();
	ofDisableDepthTest();
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
