CC=gcc
CFLAGS=-g -Wall

exe: main.c pool.a
	${CC} ${CFLAGS} -o	pool	main.c	pool.a	

pool.o: pool.c	
	${CC} ${CFLAGS}	-c	pool.c
	
pool.a : pool.o
	ar	rs	pool.a	pool.o

all : exe

clean : 
	-rm -rf pool.a pool.o pool