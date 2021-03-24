game: main.o fun_main.o gifenc.o
	cc main.c fun_main.c gifenc.c -o game
	rm *.o
clean: 
	rm game gameoflife.* *.ppm
	
