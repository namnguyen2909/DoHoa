//Nhan cac phim chuot va ban phim
#include <glut.h>
#include <gl/gl.h>
#include <stdio.h>
void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
	glFlush();
}
void myMouse(int b, int s, int x, int y)
{
	switch (b)
	{ // b indicates the button
	case GLUT_LEFT_BUTTON:
		if (s == GLUT_DOWN) // button pressed
			printf("\nLeft button pressed!");
		else if (s == GLUT_UP) // button released
			printf("\nLeft button released!");
		break;
	case GLUT_RIGHT_BUTTON:
		if (s == GLUT_DOWN) // button pressed
			printf("\nRight button pressed!");
		else if (s == GLUT_UP) // button released
			printf("\nRight button released!");
		break;
		// ... // other button events
	default: break;
	}
}
void myKeyboard(unsigned char c, int x, int y)
{
	switch (c)
	{ // c is the key that is hit
	case 27: // 'q' means quit
		exit(0);
		break;
	default:
		printf("\nKey %c is hit", c);
		break;
	}
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(300, 200);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Thi du 1.2");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	glutMainLoop();
}
