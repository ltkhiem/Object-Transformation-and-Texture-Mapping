#include "Object.h"

void Hyperboloid::Draw() {
	glBegin(GL_TRIANGLES);
	for (int i = 0; i <= 360; i += 20){
		float di = rad(i);
		float di1 = rad(i + 20);
		glTexCoord2f(0.5, 0.5);
		glVertex3f(0, -1, 0);
		glTexCoord2f(cos(di)/2 + 0.5, sin(di)/2 + 0.5);
		glVertex3f(sqrt(4)*cos(di), -1, sqrt(4)*sin(di));
		glTexCoord2f(cos(di1)/2 + 0.5, sin(di1)/2 + 0.5);
		glVertex3f(sqrt(4)*cos(di1), -1, sqrt(4)*sin(di1));

		glTexCoord2f(0.5, 0.5);
		glVertex3f(0, 1, 0);
		glTexCoord2f(cos(di) / 2 + 0.5, sin(di) / 2 + 0.5);
		glVertex3f(sqrt(4)*cos(di), 1, sqrt(4)*sin(di));
		glTexCoord2f(cos(di1) / 2 + 0.5, sin(di1) / 2 + 0.5);
		glVertex3f(sqrt(4)*cos(di1), 1, sqrt(4)*sin(di1));
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (float i = -1; i <= 1; i += 0.1){
		for (int j = 0; j <= 360; j += 20){
			float d = rad(j);
			glTexCoord2f((sqrt(1 + 3 * i*i)*cos(d))/4 + 0.5, i / 2 + 0.5);
			glVertex3f(sqrt(1 + 3*i*i)*cos(d), i, sqrt(1 + 3*i*i)*sin(d));
			glTexCoord2f((sqrt(1 + 3 * (i + 0.1)*(i + 0.1))*cos(d))/4 + 0.5, (i + 0.1) / 2 + 0.5);
			glVertex3f(sqrt(1 + 3*(i + 0.1)*(i + 0.1))*cos(d), i + 0.1, sqrt(1 + 3*(i + 0.1)*(i + 0.1))*sin(d));

		}
	}
	glEnd();


}
