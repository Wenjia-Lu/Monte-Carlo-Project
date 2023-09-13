compile: main.o final.o client.o
	gcc -o final.out main.o final.o
	
main.o: main.c final.h
	gcc -c main.c

final.o: final.c final.h
	gcc -c final.c

client.o: client.c client.h
	gcc -c client.c

client: client.out
	./client.out

client.out: client.o monte.o
	gcc -o client.out client.o monte.o -lm

run: final.out
	./final.out $(ARGS)

clear:
	rm *.o final.out client.out

clean:
	make clear

final.out: main.o final.o
	gcc -o final.out main.o final.o

monte: monte.out
	./monte.out

monte.out: monte.o
	gcc -o monte.out monte.o

monte.o: monte.c monte.h
	gcc -c monte.c -lm

distribute: distribute.out
	./distribute.out

distribute.out: distribute.o
	gcc -o distribute.out distribute.o

distribute.o: distribute.c final.h
	gcc -c distribute.c
