VPATH = ./src
CXXFLAGS = -I "./include" -I "d:\freeglut\include"
CXXLIBDIR = -L "d:\freeglut\lib"

OBJECTS = main.o Sekil.o Renk.o Nokta.o Izgara.o Kutu.o Yilan.o

program: $(OBJECTS)
	g++ $(OBJECTS)	$(CXXFLAGS) -o	program	$(CXXLIBDIR)	-lfreeglut	-lopengl32	-lglu32

Nokta.o:Nokta.cpp
	g++ -c	$(CXXFLAGS)	$<

main.o:main.cpp
	g++ -c	$(CXXFLAGS)	$<

Renk.o:Renk.cpp
	g++ -c	$(CXXFLAGS)	$<

Sekil.o:Sekil.cpp
	g++ -c	$(CXXFLAGS)	$<

Izgara.o:Izgara.cpp
	g++ -c	$(CXXFLAGS)	$<

Kutu.o:Kutu.cpp
	g++ -c	$(CXXFLAGS)	$<

Yilan.o:Yilan.cpp
	g++ -c	$(CXXFLAGS)	$<


clean:
	del *.o
	del *.exe



