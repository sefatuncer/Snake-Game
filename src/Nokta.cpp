#include "Nokta.h"
#include <GL/freeglut.h>

Nokta::Nokta()
{
	X=Y=0.0f;
}

Nokta::Nokta(float x,float y)
{
	X = x;
	Y = y;
}

bool Nokta::operator==(Nokta sag)
{
	if(X==sag.X && Y==sag.Y)
		return true;
	return false;
}


void Nokta::kullan()
{
	glVertex2f(X,Y);
}