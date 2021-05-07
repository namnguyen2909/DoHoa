#include <glut.h>
#include <GL/GLU.h>
#include <GL/GL.h>

static int shoulder = 0, elbow = 0, base = 0;
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);            


	glPushMatrix();
	glRotatef((GLfloat)base, 0.0, 1.0, 0.0);        
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);    

	glPushMatrix();                
	glTranslatef(1.5, 0.0, 0.0);  
	glScalef(2.0, 2.0, 2.0);        
	glColor3f(1.0, 1.0, 0.0);        
	glutWireCube(1.0);               

	glPopMatrix();                
	glTranslatef(2.5, 0.0, 0.0);    
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);    

	glPushMatrix();                
	glTranslatef(1.5, 0.0, 0.0);   
	glScalef(3.0, 1.0, 1.0);        
	glColor3f(0.0, 1.0, 0.0);        
	glutWireCube(1.0);               

	glPopMatrix();                
	glTranslatef(3.0, 0.0, 0.0);    
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);  

	glPushMatrix();               
	glTranslatef(1.5, 0.0, 0.0);   
	glScalef(3.0, 1.0, 1.0);      
	glColor3f(1.0, 0.0, 0.0);      
	glutWireCube(1.0);

	glPopMatrix();               
	glTranslatef(3.0, 0.0, 0.0);   
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);    

	glPushMatrix();             
	glTranslatef(1.5, 0.0, 0.0);   
	glScalef(3.0, 1.0, 1.0);       
	glColor3f(0.0, 0.0, 1.0);       
	glutWireCube(1.0);

	glPopMatrix();              
	glTranslatef(3.0, 0.0, 0.0);    
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);   

	glPushMatrix();               
	glTranslatef(0.5, 0.0, 0.0);    
	glScalef(1.0, 1.0, 3.0);        
	glColor3f(1.0, 1.0, 1.0);        
	glutWireCube(1.0);


	
	glPopMatrix();                
	glTranslatef(1.0, 0.0, -1.0);    

	glPushMatrix();                
	glTranslatef(0.5, 0.0, 0.0);   
	glScalef(1.0, 1.0, 1.0);       
	glColor3f(1.0, 1.0, 1.0);       
	glutWireCube(1.0);

	glPopMatrix();                
	glTranslatef(0.0, 0.0, 2.0);    

	glPushMatrix();               
	glTranslatef(0.5, 0.0, 0.0);    
	glScalef(1.0, 1.0, 1.0);       
	glColor3f(1.0, 1.0, 1.0);       
	glutWireCube(1.0);



	glPopMatrix();                
	glTranslatef(3, 0.0, 0.0);    
	glColor3f(1.0, 0.0, 0.0);  


	glPopMatrix(); 
	glutSwapBuffers(); 
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 's':
		shoulder = (shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5) % 360;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5) % 360;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}