#include "Object.h"	

void Torus::Draw() {
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < 360; i += 20){
		float di = rad(i);
		float di1 = rad(i + 20);
		for (int j = 0; j <= 360; j += 20){
			float dj = rad(j);
			glTexCoord2f( ((1 + 0.25*cos(dj))*cos(di1)) / 2.5 + 0.5, sin(dj) / 2 + 0.5);
			glVertex3f((1 + 0.25*cos(dj))*cos(di1), 0.25*sin(dj), (1 + 0.25*cos(dj))*sin(di1));
			glTexCoord2f( ((1 + 0.25*cos(dj))*cos(di)) / 2.5 + 0.5, sin(dj) / 2 + 0.5);
			glVertex3f((1 + 0.25*cos(dj))*cos(di), 0.25*sin(dj), (1 + 0.25*cos(dj))*sin(di));
		}
	}
	glEnd();
}