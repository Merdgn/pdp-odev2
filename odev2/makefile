all: compile link run

compile:
	gcc -c src/Canli.c -o lib/Canli.o
	gcc -c src/Bitki.c -o lib/Bitki.o
	gcc -c src/Bocek.c -o lib/Bocek.o
	gcc -c src/Pire.c -o lib/Pire.o
	gcc -c src/Sinek.c -o lib/Sinek.o
	gcc -c src/Habitat.c -o lib/Habitat.o
	gcc -c src/Test.c -o lib/Test.o
	gcc -c src/LinkedList.c -o lib/LinkedList.o

link:
	gcc -o bin/Test.exe lib/Canli.o lib/Bitki.o lib/Bocek.o lib/Pire.o lib/Sinek.o lib/Test.o lib/LinkedList.o lib/Habitat.o

run:
	./bin/Test.exe

clean:
	del /q bin
	del /q lib