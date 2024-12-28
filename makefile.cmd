all: main.exe

main.exe: main.o
	gcc -o main.exe main.o

main.o: main.c
	gcc -c main.c

X.o: X.c
	gcc -c X.c

clean:
	rm main.o main.exe