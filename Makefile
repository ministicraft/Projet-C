projet.exe: main.o carte.o robot.o graphique.o
	gcc main.o carte.o robot.o graphique.o -o projet.exe
main.o: main.c carte.h robot.h graphique.h
	gcc -c main.c
carte.o:  carte.c carte.h
	gcc -c carte.c
robot.o:  robot.c robot.h
	gcc -c robot.c
graphique.o:  graphique.c graphique.h
	gcc -c graphique.c


clean:
	rm *.o *.exe
