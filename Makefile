#  TESTOWY
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: uklad_rownan
	./uklad_rownan

uklad_rownan: obj/main.o obj/Wektor.o
	g++ -Wall -pedantic -o obj/main.o obj/Wektor.o

obj/main.o: src/main.cpp inc/Wektor.hh\
        inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

clear:
	rm -f obj/*.o uklad_rownan
