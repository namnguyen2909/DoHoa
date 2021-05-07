//Hien thi lap phuong tu diem quan sat cho truoc, su dung chieu truc giao
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
	glOrtho(-3.2, 3.2, -2.4, 2.4, 1, 50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(8, 10, 7, 0, 0, 0, 1, 0, 0);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutWireCube(1); // Ve lap phuong
	glFlush();
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Thi du 5.1");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
