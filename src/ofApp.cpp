#include "ofApp.h"
#include "qbGrid.h"
#include "qbVideoCapture.h"

qbGrid grid(imageV);
qbGrid grid1(imageV);
qbVideoCapture videoCapture;
qbVideoCapture videoCapture1;
//--------------------------------------------------------------
void ofApp::setup(){
	
	//grid1.setup("sun.png");
	videoCapture.setup();
	//grid.setup("sunflower.png");
}

//--------------------------------------------------------------
void ofApp::update(){
	grid.update();
	grid1.update();
	videoCapture.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 128, 128, 128 );
	videoCapture.draw(0,0);
	grid.draw(0, 0);
	//grid1.draw(650, 0);
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
