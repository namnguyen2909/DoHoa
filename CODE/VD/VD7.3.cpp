//Ve va to mau khoi da dien vs cac dinh cho truoc va bo sung phim x,y de xoay da dien
#include <glut.h> // GLUT
#include <GL/glu.h> // GLU
#include <GL/gl.h> // OpenGL
#include <stdio.h>
#include <math.h>
int a[3] = { 0.0,0.0,0.0 }, b[3] = { 1.0,-1.0,1.0 }, c[3] = { -1.0,-1.0,1.0 }, d[3] = { -1.0,1.0,1.0 },
e[3] = { 1.0,1.0,-1.0 }, f[3] = { 1.0,-1.0,-1.0 }, g[3] = { -1.0,-1.0,-1.0 }, h[3] = { -1.0,1.0,-1.0 };
float angle_x = 0.0;
float angle_y = 0.0;
void drawcube(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glRotatef(angle_y, 0.0, 1.0, 0.0);
	glRotatef(angle_x, 1.0, 0.0, 0.0);
	// ----------------------------
	glColor3f(1.0, 0.0, 0.0);//red
	glBegin(GL_POLYGON);
	glVertex3iv(d);
	glVertex3iv(h);
	glVertex3iv(g);
	glVertex3iv(c);
	glEnd();
	glColor3f(0.0, 1.0, 0.0); // green
	glBegin(GL_POLYGON);
	glVertex3iv(e);
	glVertex3iv(f);
	glVertex3iv(g);
	glVertex3iv(h);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);//blue
	glBegin(GL_POLYGON);
	glVertex3iv(b);
	glVertex3iv(c);
	glVertex3iv(g);
	glVertex3iv(f);
	glEnd();
	glColor3f(1.0, .0, 1.0); // magenta
	glBegin(GL_TRIANGLES);
	glVertex3iv(a);
	glVertex3iv(d);
	glVertex3iv(b);
	glEnd();
	glColor3f(0.0, 1.0, 1.0);//cyan
	glBegin(GL_TRIANGLES);
	glVertex3iv(d);
	glVertex3iv(c);
	glVertex3iv(b);
	glEnd();
	glColor3f(1.0, 1.0, 0.0);//yellow
	glBegin(GL_TRIANGLES);
	glVertex3iv(e);
	glVertex3iv(h);
	glVertex3iv(d);
	glEnd();
	glColor3f(0.0, .0, 0.0);//black
	glBegin(GL_TRIANGLES);
	glVertex3iv(e);
	glVertex3iv(d);
	glVertex3iv(a);
	glEnd();
	glColor3f(0.7, 0.7, 0.7);//white
	glBegin(GL_TRIANGLES);
	glVertex3iv(e);
	glVertex3iv(a);
	glVertex3iv(b);
	glEnd();
	glColor3f(.0, .50, .50);//
	glBegin(GL_TRIANGLES);
	glVertex3iv(e);
	glVertex3iv(b);
	glVertex3iv(f);
	glEnd();
	glFlush();
}
void myDisplay(void)
{
	glClearColor(1., 1., 1., 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity(); /* clear the matrix */
	/* viewing transformation */
	gluLookAt(2.0, 3.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	drawcube();
	glFlush();
}
void myReshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'x':
	case 'X':
		angle_x += 10.;
		glutPostRedisplay();
		break;
	case 'y':
	case 'Y':
		angle_y += 10.;
		glutPostRedisplay();
		break;
	case 'i':
	case 'I':
		angle_x = 0.;
		angle_y = 0.;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400); // create a 400x400 window
	glutInitWindowPosition(0, 0); // ...in the upper left
	glutCreateWindow("Thi Du 7.3"); // create the window
	glutDisplayFunc(myDisplay);  // setup callbacks
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(myReshape);
	glutMainLoop(); // start it running
	return 0; // ANSI C expects this
}
