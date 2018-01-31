#include "Object.h"

void Circle::Draw() {
	glBegin(GL_TRIANGLES);
	int cnt = 0;
	for (int i = 0; i <= 360; i += 10){
		float d = rad(i);
		float d1 = rad(i + 10);
		glTexCoord2f(0.5, 0.5);
		glVertex3f(0, 0, 0);
		glTexCoord2f(cos(d)/2+0.5, sin(d)/2+0.5);
		glVertex3f(cos(d), 0, sin(d));
		glTexCoord2f(cos(d1)/2+0.5, sin(d1)/2+0.5);
		glVertex3f(cos(d1), 0, sin(d1));
	}
	glEnd();
}