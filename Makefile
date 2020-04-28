#  TESTOWY
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: uklad_rownan
	./uklad_rownan

uklad_rownan: obj/main.o obj/LZespolona.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/LZespolona.o

obj/main.o: src/main.cpp inc/Wektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

clear:
	rm -f obj/*.o uklad_rownan
