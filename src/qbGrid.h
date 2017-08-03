#pragma once

#include "ofMain.h"



class qbGrid {
public:
	float gridWidth, gridHeight;
	float cellWidth, cellHeight;
	float quadWidth, quadHeight;
	float cellGap, quadGap;

	ofImage image;		//Declare image object

	ofColor quadColorSet;

	ofColor quadValue[100][100][10][10][6]; // Hue, Sat, Bri, Red, Green, Blue of each quadrant

	// �� UxV ������
	int u;
	int v; 
	// �� WxX ��ϸ��
	int w;
	int x; 

	qbGrid()
		: u(28)
		, v(28)
		, w(2)
		, x(2)
		, gridWidth(600)
		, gridHeight(600)
	{}

	virtual ~qbGrid() {}


	//--------------------------------------------------------------
	void setup() {

		//---------------------------------------------
		image.loadImage("sunflower.png");

		//Getting pointer to pixel array of image
		unsigned char *data = new unsigned char[image.getWidth() * image.getHeight() * 3];
		
		cout << image.getImageType() << endl;
		cout << image.getWidth() << " + " << image.getHeight() << endl;

		image.resize(600, 600);
		ofColor color = ofColor(0, 0, 0);
		ofPixels & pixels = image.getPixels();
		cout << pixels.size() << endl;

		image.setColor(10, 10, color);
		cout << image.getColor(300, 300) << endl;

		cout << image.getColor(180400).r << endl;

		//----------------------------------


		cellGap = 9.0 / 596.0 * gridWidth;
		cellWidth = (gridWidth - (u + 1) * cellGap) / u;
		cellHeight = (gridHeight - (v + 1) * cellGap) / v;

		quadGap = cellWidth / (2 * w - 1);
		quadWidth = (cellWidth - (w - 1) * quadGap) / w;
		quadHeight = (cellHeight - (x - 1) * quadGap) / x;

		cout << cellHeight << "\n";
		cout << cellWidth << "\n";
		cout << quadWidth << "\n";
		cout << quadHeight << "\n";
	}


	//--------------------------------------------------------------
	void update() {
		// ����С�������ɫ��������ά����quadValue[i][j][k][l][r:g:b:h:s:v]
		image.update();
	}


	//--------------------------------------------------------------
	void draw(float px, float py) {
		ofSetColor(255, 255, 255);
		image.draw(0, 0);
		// ���������
		ofSetColor(0, 0, 255);
		ofNoFill();
		ofSetLineWidth(1);
		ofDrawRectangle(px, py, gridWidth, gridHeight);
		
		// ��ϸ�����
		ofSetColor(255, 0, 0);
		ofNoFill();
		for (size_t i = 0; i < u; i++)
		{
			for (size_t j = 0; j < v; j++)
			{
				// ��ϸ�����
				for (size_t k = 0; k < w; k++)
				{
					// ��С���飬�����
					for (size_t l = 0; l < x; l++)
					{
						// 
						float local_x = px + l * (quadGap + quadWidth) + j * (cellGap + cellWidth) + (cellGap);
						float local_y = py + k * (quadGap + quadHeight) + i  * (cellGap + cellHeight) + (cellGap);
							
						for (size_t m = 0; m < quadWidth; m++)
						{
							for (size_t n = 0; n < quadHeight; n++)
							{
								// �ɼ�������ɫֵ,�������������ɫ
								quadValue[i][j][k][l][0] = image.getColor(local_x + m,local_y + n);
							}
						}

						ofSetColor(quadValue[i][j][k][l][0]);
						ofFill();
						ofDrawRectangle(local_x, local_y, quadWidth, quadHeight);

						ofSetColor(0, 0, 0);
						ofNoFill();
						ofSetLineWidth(1);
						ofDrawRectangle(local_x, local_y, quadWidth, quadHeight);
					}
				}
				ofPushMatrix();
					ofTranslate(j*cellWidth + (j + 1)*cellGap + px, i*cellHeight + (i + 1)*cellGap + py, 0);
					ofSetColor(0, 0, 0);
					ofSetLineWidth(1);  //�Ժ��滭�����εĿ����Ӱ�죬���Խ���ʱ����������Ϊ1��Ҳ���У���bug
					ofNoFill();
					ofDrawRectangle(0, 0, cellWidth, cellHeight);
				ofPopMatrix();         // recall the pushed coordinate position
			}
		}
	}
	
private:

};

