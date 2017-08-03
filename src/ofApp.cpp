#include "ofApp.h"
#include "qbGrid.h"
qbGrid grid;

//--------------------------------------------------------------
void ofApp::setup(){
	grid.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	grid.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Set up gray background
	ofBackground( 128, 128, 128 );

	//Draw image with top left corner x=100, y=50 pixels
	grid.draw(600, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

} 

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
