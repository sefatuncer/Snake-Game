#ifndef Nokta_h
#define Nokta_h

class Nokta
{
public:
	Nokta();
	Nokta(float x,float y);
	void kullan();
	bool operator==(Nokta sag);
public:
	float X;
	float Y;
};

#endif