#include <windows.h>  // for MS Windows
#include <gl/glew.h>
#include <GL/glut.h>  // GLUT
#include <cmath>
#include "Object.h"

#define GLEW_STATIC

#include <GLFW/glfw3.h>

 char* imgName[8] = { "galaxy.jpg", "galaxy1.jpg", "galaxy2.jpg", "galaxy3.jpg", "galaxy4.jpg",
						"galaxy5.jpg", "galaxy7.jpg", "galaxy8.jpg" };
GLuint	texture[8];			// Storage For One Texture
float xrot, yrot, zrot;
float turnAroundAngle = 0.0;

int shapeRotate = 0;
Cone cone;
Circle circle;
Cube cube;
Sphere sphere;
Torus torus;
Cylinder cylinder;
Paraboloid paraboloid;
Hyperboloid hyperboloid;

/* Global variables */
char title[] = "3D Shapes with animation";
GLfloat anglePyramid = 0.0f;  // Rotational angle for pyramid 
GLfloat angleCube = 0.0f;     // Rotational angle for cube 
int refreshMills = 1;        // refresh interval in milliseconds 
double posx=0.0f, posy=0.0f, posz = 0;

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

int loadGLTextures(int i)         // Load Bitmaps And Convert To Textures
{
	/* load an image file directly as a new OpenGL texture */
	texture[i] = SOIL_load_OGL_texture
		(imgName[i],	SOIL_LOAD_AUTO,	SOIL_CREATE_NEW_ID,	SOIL_FLAG_INVERT_Y);
	if (texture[i] == 0)
		return false;


	// Typical Texture Generation Using ;Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture[i]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}

int drawGLScene(GLvoid)			// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

	for (int i=0; i<8; i++)		loadGLTextures(i);

	glLoadIdentity(); // Reset The View
	glTranslatef(posx-6.0f, posy+1.5f, posz-12.0f);
	glRotatef(shapeRotate, 0.0, -1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	cube.Draw();

	glLoadIdentity(); // Reset The View
	glTranslatef(posx-2.0f, posy+1.3f, posz-10.0f);
	glRotatef(shapeRotate, 0.0, -1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	sphere.Draw();

	glLoadIdentity(); // Reset The View
	glTranslatef(posx+1.0f, posy+1.4f, posz-10.0f);
	glRotatef(shapeRotate, 0.0, -1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	cylinder.Draw();

	glLoadIdentity(); // Reset The View
	glTranslatef(posx + 3.5f, posy + 0.7f, posz - 7.5f);
	glRotatef(shapeRotate, 0.0, -1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	cone.Draw();

	glLoadIdentity(); // Reset The View
	glTranslatef(posx - 4.0f, posy - 1.5f, posz - 8.0f);
	glRotatef(shapeRotate, 0.0, -1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	circle.Draw();

	glLoadIdentity(); // Reset The View
	glTranslatef(posx - 2.0f, posy - 1.7f, posz - 10.0f);
	glRotatef(shapeRotate, 0.0, -1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	torus.Draw();

	glLoadIdentity(); // Reset The View
	glTranslatef(posx + 1.5f, posy - 2.5f, posz - 16.0f);
	glRotatef(shapeRotate, 0.0, -1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	hyperboloid.Draw();

	glLoadIdentity(); // Reset The View
	glTranslatef(posx + 5.5f, posy - 0.7f, posz - 12.0f);
	glRotatef(shapeRotate, 0.0, -1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	paraboloid.Draw();

	shapeRotate += 1;
	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
	return TRUE;
}



/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	drawGLScene();
}

/* Called back when timer expired */
void timer(int value) {
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(1500, 700);   // Set the window's initial width & height
	glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	initGL();                       // Our own OpenGL initialization
	glutTimerFunc(0, timer, 0);     // First timer call immediately 
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}
