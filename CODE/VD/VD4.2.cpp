//Xoay hinh vuong 1 goc 20 do. Tam xoay tai vi tri (x,y)
#include <glut.h>
#include <gl/gl.h>
void myInit(void) {
	glClearColor(0.7f, 0.7f, 0.7f, 0.0f); //Nen màu xám
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glMatrixMode(GL_MODELVIEW);
}
void myDisplay(void) {
	int x = 50, y = 40;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(200, 100, 400, 300);
	glColor3f(1.0f, 1.0f, 0.0f);
	glPushMatrix(); // save the current matrix (M)
	glTranslatef(x, y, 0.); // apply translation (T)
	glRotatef(30., 0., 0., 1.); // apply rotation (R)
	glTranslatef(-x, -y, 0.); // apply translation (T)
	glRectf(200., 100., 400., 300.); // draw rectangle at the origin
	glPopMatrix(); // restore the old matrix (M)
	glPointSize(4.);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Thi du 4.2");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
