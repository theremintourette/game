#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	vhpGame * g = new vhpGame();
	thereminApp.push_back(g);
	thereminApp[0]->setup();
	hasTouch = false;
}

void testApp::exit(){
	cout << "exit" << endl;
	thereminApp.clear();
}

//--------------------------------------------------------------
void testApp::update(){
    thereminApp[0]->update();
}

//--------------------------------------------------------------
void testApp::draw(){
	thereminApp[0]->draw();
	map<int,ofPoint>::iterator iter;
	for ( iter=touches.begin(); iter != touches.end(); ++iter ){
		cout << (int)iter->second.x << " - " << (int)iter->second.y << endl;
		ofCircle(iter->second, 30);
		thereminApp[0]->setTouchPosition(iter->second);
		if (hasTouch) {
			thereminApp[0]->touchPressed(hasTouch);
			hasTouch = false;
		}
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	thereminApp[0]->keyReleased(key);
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch){
	touches.insert(pair<int,ofPoint>(touch.id,ofPoint(touch.x,touch.y)));
	hasTouch = true;
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs &touch){
	touches[touch.id].set(touch.x,touch.y);
}
		
//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs &touch){
	touches.erase(touch.id);
}
		
//--------------------------------------------------------------
void testApp::twoFingerTap(){
}

//--------------------------------------------------------------
void testApp::twoFingerZoom(double dZoomFactor,const LONG lZx,const LONG lZy) {
}