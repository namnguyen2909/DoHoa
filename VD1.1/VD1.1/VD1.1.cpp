//Ve diem anh tren man hinh
#include <glut.h>
#include <gl/gl.h>
void myDisplay(void) {
	glClearColor(1., 1., 1., 1.);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1., 0., 0.);
	//glPointSize(12.0);
	glBegin(GL_POINTS);
	glVertex2i(0, 0);
	glEnd();
	glFlush();
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 150);
	glutInitWindowSize(640, 480);
	glutCreateWindow("VD1.1");
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}