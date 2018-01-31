#include "Object.h"

void Cylinder::Draw() {
	float texPos = 0;
	float texStep = 1.0 / 360;
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= 360; i+=10){
		float d = rad(i);
		glTexCoord2f(texPos,0);
		glVertex3f(cos(d), 1, sin(d));
		glTexCoord2f(texPos,1);
		glVertex3f(cos(d), -1, sin(d));
		texPos += texStep*10;
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i <= 360; i += 10){
		float d = rad(i);
		float d1 = rad(i + 10);
		glTexCoord2f(0.5, 0.5);
		glVertex3f(0, -1, 0);
		glTexCoord2f(cos(d) / 2 + 0.5, sin(d) / 2 + 0.5);
		glVertex3f(cos(d), -1, sin(d));
		glTexCoord2f(cos(d1) / 2 + 0.5, sin(d1) / 2 + 0.5);
		glVertex3f(cos(d1), -1, sin(d1));

		glTexCoord2f(0.5, 0.5);
		glVertex3f(0, 1, 0);
		glTexCoord2f(cos(d) / 2 + 0.5, sin(d) / 2 + 0.5);
		glVertex3f(cos(d), 1, sin(d));
		glTexCoord2f(cos(d1) / 2 + 0.5, sin(d1) / 2 + 0.5);
		glVertex3f(cos(d1), 1, sin(d1));
	}
	glEnd();
}