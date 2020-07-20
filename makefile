pro: main.o Tree.o Graph.h
	g++ -o pro main.o Tree.o 
main.o:	main.cpp 
	g++ -c main.cpp 
Tree.o:	Tree.cpp
	g++ -c Tree.cpp 
clean:
	rm pro
	rm *.o  