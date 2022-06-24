compiler : main.c elevator.h person.h
	gcc -o ascenseur main.c elevator.c person.c -l ncurses

run : ascenseur
	./ascenseur

debug : main.c elevator.h person.h
	gcc -g -o ascenseur main.c elevator.c person.c -l ncurses
	gdb ascenseur
	run
