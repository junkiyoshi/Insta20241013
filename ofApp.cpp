#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofEnableDepthTest();
	ofSetCircleResolution(60);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 1.44);

	ofFill();
	ofSetColor(239);
	ofDrawCircle(glm::vec3(), 230);

	ofSetLineWidth(2);
	ofNoFill();
	ofSetColor(0);
	ofDrawCircle(glm::vec3(), 231);
	
	for (int i = 0; i < 20; i++) {
	
		ofPushMatrix();
		ofRotateZ(ofRandom(360));
		ofRotateY(ofRandom(360));
		ofRotateX(ofRandom(360));

		auto radius = ofRandom(255, 300);
		auto deg_start = ofRandom(360, 720) + ofGetFrameNum() * (int)ofRandom(1, 5);;

		ofSetLineWidth(ofMap(radius, 255, 300, 0.5, 1.5));

		ofNoFill();
		ofBeginShape();
		for (int deg = deg_start; deg < deg_start + 350; deg++) {

			ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		}
		ofEndShape();

		ofFill();
		ofDrawSphere(glm::vec3(
			radius * cos((deg_start - 5) * DEG_TO_RAD),
			radius * sin((deg_start - 5) * DEG_TO_RAD),
			0), 3);

		ofPopMatrix();
	}

	this->cam.end();

	/*
	int start = 250;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}