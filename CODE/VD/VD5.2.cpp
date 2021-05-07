//Hien thi lap phuong tu diem quan sat cho truoc, su dung chieu phoi canh
#include <glut.h>
#include <gl/gl.h>
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 6, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 10, 0, 0, 0, 0, 1, 0, 0);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(45, 1, 1, 1);
	glutWireCube(1);
	glPopMatrix();
	glFlush();
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Thi du 5.2");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
