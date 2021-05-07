//Ve hinh vuong, nhan phim trai chuot hinh vuong quay nguoc chieu kim dong ho, nhan phim phai chuot de dung
#include <glut.h>
#include <cstddef>
static GLfloat spin = 0.0; /* góc quay hiện tại của hình chữ nhật */
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0); /* xoay một góc spin quanh trục z */
	glColor3f(1.0, 1.0, 1.0); /* thiết lập màu vẽ cho hcn (màu trắng) */
	glRectf(-25.0, -25.0, 25.0, 25.0); /* vẽ hcn */
	glPopMatrix();
	glutSwapBuffers(); /* thực hiện việc hoán đổi 2 buffer */
}
void spinDisplay(void)
{
	spin = spin + 2.0; /* xoay thêm 2 deg cho mỗi lần lặp */
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay(); /* thông báo cho chương trình rằng: cần phải thực
	hiện việc vẽ lại */
}
/* các thao tác cần làm khi cửa sổ bị thay đổi kích thước */
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); /* thay đổi viewport */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
/* các thao tác xử lý chuột */
void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON: /* khi nhấn chuột trái */
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay); /* khi chương trình đang trong trạng
			thái idle (không phải xử lý gì cả) thì sẽ thực hiện hàm spinDisplay */
		break;
	case GLUT_RIGHT_BUTTON: /* khi nhấn chuột phải */
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}
/* hàm main của chương trình */
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); /* khai báo việc sử dụng
	chế độ double buffer */
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("BT4.1");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); /* đăng ký hàm reshape cho sự kiện cửa sổ bị
	thay đổi kích thước */
	glutMouseFunc(mouse); /* đăng ký hàm mouse cho sự kiện về chuột */
	glutMainLoop();
	return 0;
}
