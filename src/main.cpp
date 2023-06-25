#include <GL/freeglut.h>
#include<windows.h>
#include "Yilan.h"
#include "Izgara.h"
Izgara i;

Yilan yilan;

const int HEIGHT = 600;
const int WIDTH  = 800;

//hangi þeklin secili olacagini belirler

int		zaman = 0;

void 	keyboard(unsigned char key, int x, int y);
void 	display(void);

void 	yaziYazdir(float x, float y, void *font, const char* yazi, Renk rgb)
{  
  char *c;

  glColor3f(rgb.kirmizi, rgb.yesil, rgb.mavi); 
  glRasterPos2f(x, y);

  glutBitmapString(font, (unsigned char*)yazi);
}

int main(int argc, char** argv)
{


	glutInit(&argc, argv);
	//penceremiz istenilen genislik ve yukseklikte olusturuluyor
	glutInitWindowSize(WIDTH,HEIGHT);
	//oluþturulacak olan pencerenin baþlýðý veriliyor
	glutCreateWindow("SNAKE GAME");
	//klavye fonksiyonu glut a veriliyor
	glutKeyboardFunc(keyboard);

	//çizim fonksiyonu	glut a veriliyor
	glutDisplayFunc(display);

	glutMainLoop();
	return EXIT_SUCCESS;
}


void keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 'w':
	case 'W':
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		break;
	case 's':
	case 'S':
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);	
		break;
    case '\x1B':
      exit(EXIT_SUCCESS);
      break;
	}
  
	yilan.klavyeOku(key);
 
}


void display()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(	0,800,0,600);

	glClear(GL_COLOR_BUFFER_BIT);
	
	
	i.ciz(); // Izgara

	//yilan hiç bir yere çarpýyormu
	if(!yilan.carpismaVarmi())
	{
		//çarpmýyorsa ilerle
		yilan.ilerle();
	}
	else
	{
		///çarpýyorsa oyun bitti mesajý yaz.
		yaziYazdir(300.0f, 570.0f, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER", Renk(1.0f, 0.0f, 0.0f));

	}
	////yýlaný çiz
	yilan.ciz();
	
	
	glFlush();
	//80 milisaniye bekle
	while(GetTickCount()-zaman<=80);
	
	zaman = GetTickCount();
	//tekrar çizim fonksiyonunu çaðýr
	glutPostRedisplay();
}
