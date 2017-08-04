#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCsv.h"
#include "qbGrid.h"
ofImage imageV;
class qbVideoCapture {
public:
	ofPoint A;
	ofPoint B;
	ofPoint C;
	ofPoint D;

	ofxCvColorImage cvImage;
	ofxCsv csv;

	int cornerIndex = 1;
	bool SaveWarpPoints = false;

	ofVideoGrabber vidGrabber;
	
	ofImage images;

	int camWidth;
	int camHeight;

	ofTrueTypeFont font;
	qbVideoCapture()
		: camWidth(640)
		, camHeight(480)
	{}

	virtual ~qbVideoCapture() {}

	//--------------------------------------------------------------
	void setup() {
		vidGrabber.setDeviceID(0);
		vidGrabber.setDesiredFrameRate(60);
		vidGrabber.initGrabber(camWidth, camHeight);

		ofSetVerticalSync(true);

		// ���ļ��ж�ȡ�ĸ������λ��
		if (csv.load("morse.csv")) {
			A = ofPoint(ofToFloat(csv[0][1]), ofToFloat(csv[0][2]), ofToFloat(csv[0][3]));
			B = ofPoint(ofToFloat(csv[1][1]), ofToFloat(csv[1][2]), ofToFloat(csv[1][3]));
			C = ofPoint(ofToFloat(csv[2][1]), ofToFloat(csv[2][2]), ofToFloat(csv[2][3]));
			D = ofPoint(ofToFloat(csv[3][1]), ofToFloat(csv[3][2]), ofToFloat(csv[3][3]));
		}

		// ����ռ� ����Ҫfree ��ס
		cvImage.allocate(600, 600);
		// ����ռ� ����Ҫfree
		imageV.allocate(600, 600, OF_IMAGE_COLOR);
		images.allocate(640, 480, OF_IMAGE_COLOR);
		//grid.setup("sunflower.png");
	}


	//--------------------------------------------------------------
	void update() {
		ofBackground(100, 100, 100);
		vidGrabber.update();

		// ��׽����ͷͼƬ
		if (vidGrabber.isFrameNew()) {
			images.setFromPixels(vidGrabber.getPixels());
		}

		// �������ѡȡABCD�ĸ���λ�á���S������ABCD�����λ�ñ��浽�ļ���
		if (SaveWarpPoints == true) {
			// ���浽�ļ�
			cout << "SaveWarpPoints" << "\n";

			csv[0].setInt(1, A.x);
			csv[0].setInt(2, A.y);
			csv[0].setInt(3, A.z);

			csv[1].setInt(1, B.x);
			csv[1].setInt(2, B.y);
			csv[1].setInt(3, B.z);

			csv[2].setInt(1, C.x);
			csv[2].setInt(2, C.y);
			csv[2].setInt(3, C.z);

			csv[3].setInt(1, D.x);
			csv[3].setInt(2, D.y);
			csv[3].setInt(3, D.z);

			csv.save("morse.csv");
			SaveWarpPoints = false;
		}

		ofSetHexColor(0xffffff);
		// ͼ����Σ�����ִ��˳��Ҫע�⣬ABCD����Ҫ��image2ƥ��
		cvImage = images;

		ofPoint A_ = ofPoint(A.x - 642, A.y - 162, 0);
		ofPoint B_ = ofPoint(B.x - 642, B.y - 162, 0);
		ofPoint C_ = ofPoint(C.x - 642, C.y - 162, 0);
		ofPoint D_ = ofPoint(D.x - 642, D.y - 162, 0);
		cvImage.warpPerspective(A_, B_, C_, D_);

		imageV.setFromPixels(cvImage.getPixels());
		imageV.resize(600, 600);
		cout << imageV.getColor(300, 300)  << endl;
		//grid.update();
	}


	//--------------------------------------------------------------
	void draw() {
		ofSetColor(255, 255, 255);
		// ����ȡ֮���ͼƬ
		imageV.draw(20, 160);

		// ������ͷͼ��
		vidGrabber.draw(642, 162);

		// ���ĸ��㣬ѡȡλ��
		ofSetColor(255, 0, 0);
		ofFill();
		ofDrawCircle(A, 5.0);
		ofDrawCircle(B, 5.0);
		ofDrawCircle(C, 5.0);
		ofDrawCircle(D, 5.0);

		// �����ߣ�ѡȡΧ������
		ofSetLineWidth(3.0);
		ofDrawLine(A, B);
		ofDrawLine(B, C);
		ofDrawLine(C, D);
		ofDrawLine(D, A);
		//grid.draw(image, 0,0);
	}


	//--------------------------------------------------------------
	void keyPressed(int key) {
		switch (key)
		{
		case '1':
			cornerIndex = 1;
			break;
		case '2':
			cornerIndex = 2;
			break;
		case '3':
			cornerIndex = 3;
			break;
		case '4':
			cornerIndex = 4;
			break;
		case 's':
			SaveWarpPoints = true;
			break;
		default:
			break;
		}
	}


	//--------------------------------------------------------------
	void mousePressed(int x, int y, int button) {
		switch (cornerIndex)
		{
		case 1:
			A = ofPoint(x, y, 0);
			break;
		case 2:
			B = ofPoint(x, y, 0);
			break;
		case 3:
			C = ofPoint(x, y, 0);
			break;
		case 4:
			D = ofPoint(x, y, 0);
			break;
		default:
			break;
		}
	}

};
