main.exe: Abll.o main.o
	gcc Abll.o main.o -o main.exe
Abll.o: Abll.c Abll.h
	gcc -c Abll.c
main.o: main.c Abll.h
	gcc -c main.c
clean:
	del -f Abll.o main.o main.exe