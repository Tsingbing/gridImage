#include "ofApp.h"
#include "qbGrid.h"
qbGrid grid;
qbGrid grid1;
//--------------------------------------------------------------
void ofApp::setup(){
	grid.setup("sunflower.png");
	grid1.setup("sun.png");
}

//--------------------------------------------------------------
void ofApp::update(){
	grid.update();
	grid1.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofBackground( 128, 128, 128 );

	grid.draw(0, 0);
	grid1.draw(650, 0);
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
