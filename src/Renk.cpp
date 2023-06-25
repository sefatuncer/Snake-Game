#include "Renk.h"
#include <GL/freeglut.h>

Renk::Renk()
{
	kirmizi = 1.0f; // Varsayýlan kýrmýzý
	yesil	= 0.0f;
	mavi	= 0.0f;
}

Renk::Renk(float k,float y,float m)
{
	this->kirmizi = k;
	this->yesil	  = y;
	this->mavi	  = m;
}

void Renk::kullan()
{
	glColor3f(kirmizi,yesil,mavi);
}