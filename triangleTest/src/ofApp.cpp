#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    lightSys.setup();
    //ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);

}

//--------------------------------------------------------------
void ofApp::update(){
    lightSys.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    lightSys.begin();
    lightSys.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  lightSys.keyPressed(key);
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
