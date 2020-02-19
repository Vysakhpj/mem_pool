
exe: main.c pool.a
	gcc	-o	pool	main.c	pool.a	

pool.o: pool.c	
	gcc	-c	pool.c
	
pool.a : pool.o
	ar	rs	pool.a	pool.o

all : exe

clean : 
	-rm -rf pool.a pool.o pool