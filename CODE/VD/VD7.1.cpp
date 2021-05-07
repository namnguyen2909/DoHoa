//Ve cac khoi da dien bang opengl
#include <glut.h>
#include <gl/gl.h>
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0., 0., 1.);
	// Set viewing transformation
	gluLookAt(5., 5., 5., 0, 0, 0, 0., 1.0, 0);
	// Scale cube and display as wire-frame parapellelepiped
	glScalef(1.5, 2.0, 1.0);
	glutWireCube(1.);
	// Scale, translate, and display wire-frame dodecahedron
	glScalef(0.8, 0.5, 0.8);
	glTranslatef(-6., -5., 0.);
	glutWireDodecahedron();
	// Translate and display wire-frame dodecahedron
	glTranslatef(8.6, 8.6, 2.);
	glutWireTetrahedron();
	// Translate and display wire-frame Octahedron
	glTranslatef(-3., -1., 0.);
	glutWireOctahedron();
	// Scale, translate, and display wire-frame icosahedron
	glScalef(0.8, .8, 1.);
	glTranslatef(4.3, -2., 0.5);
	glutWireIcosahedron();
	glFlush();
}
void reshapeFunc(GLint w, GLint h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glFrustum(-1., 1., -1., 1., 2., 20.);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Thi du 7.1");
	glutDisplayFunc(myDisplay);
	init();
	glutReshapeFunc(reshapeFunc);
	glutMainLoop();
}