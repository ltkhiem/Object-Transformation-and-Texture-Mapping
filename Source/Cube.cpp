#include "Object.h"

void Cube::Draw() {
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
	// Top face (y = 1.0f)
	// Define vertices in counter-clockwise (CCW) order with normal pointing out
	glTexCoord2f(0, 0);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0, 1);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1, 0);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1, 1);
	glVertex3f(1.0f, 1.0f, 1.0f);

	// Bottom face (y = -1.0f)
	glTexCoord2f(0, 0);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0, 1);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1, 0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1, 1);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Front face  (z = 1.0f)
	glTexCoord2f(0, 0);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0, 1);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1, 0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1, 1);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// Back face (z = -1.0f)
	glTexCoord2f(0, 0);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0, 1);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1, 0);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1, 1);
	glVertex3f(1.0f, 1.0f, -1.0f);

	// Left face (x = -1.0f)
	glTexCoord2f(0, 0);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0, 1);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1, 0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1, 1);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	// Right face (x = 1.0f)
	glTexCoord2f(0, 0);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0, 1);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1, 0);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1, 1);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();  // End of drawing color-cube
}