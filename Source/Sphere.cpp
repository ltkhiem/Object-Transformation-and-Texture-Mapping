#include "Object.h"

void Sphere::Draw() {
	int cnt = 0;
	glBegin(GL_QUAD_STRIP);
	for (int i = -90; i < 90; i += 10){
		float di = rad(i);
		float di1 = rad(i+10);
		for (int j = 0; j <= 360; j += 10){
			float dj = rad(j);
			glTexCoord2f((sin(dj)*cos(di))/2+0.5, sin(di)/2+0.5);
			glVertex3f(sin(dj)*cos(di), sin(di), cos(di)*cos(dj));
			glTexCoord2f((sin(dj)*cos(di1))/2+0.5, sin(di1)/2 + 0.5); 
			glVertex3f(sin(dj)*cos(di1), sin(di1), cos(di1)*cos(dj));
		}
	}
	glEnd();
}