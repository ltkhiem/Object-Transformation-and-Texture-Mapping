#include "Object.h"

void Paraboloid::Draw() {
	int cnt = 0;

	glBegin(GL_TRIANGLES);
	for (int i = 0; i <= 360; i += 20){
		float d = rad(i);
		float d1 = rad(i + 20);
		glTexCoord2f(0.5, 0.5);
		glVertex3f(0, -2, 0);
		glTexCoord2f(cos(d) / 2 + 0.5, sin(d) / 2 + 0.5);
		glVertex3f(sqrt(2)*cos(d), -2, sqrt(2)*sin(d));
		glTexCoord2f(cos(d1) / 2 + 0.5, sin(d1) / 2 + 0.5);
		glVertex3f(sqrt(2)*cos(d1), -2, sqrt(2)*sin(d1));
	}
	glEnd();

	glRotatef(-180, 1, 0, 0);
	glBegin(GL_QUAD_STRIP);
	for (float i = 0; i <= 2; i += 0.1){
		for (int j = 0; j <= 340; j += 20){
			if (j == 340) j--;
			float d = rad(j);
			
			float d1 = rad(j+20);
			
			if (j!=80) 
				glTexCoord2f(sin(d) / 2 + 0.5, (i + 0.1) / 2);
			else
				glTexCoord2f(i/2, 1);
			glVertex3f(sqrt(i + 0.1)*sin(d), i + 0.1, sqrt(i + 0.1)*cos(d));

			if (j!=80) 
				glTexCoord2f(sin(d) / 2 + 0.5, i / 2);
			else
				glTexCoord2f(j*(1-(1.0/360)*20) + 0.5, 1);
			glVertex3f(sqrt(i)*sin(d), i, sqrt(i)*cos(d));
		}
	}
	glEnd();


}
