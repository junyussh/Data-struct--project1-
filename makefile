pro: main.o Tree.o Graph.o
	g++ -o pro main.o Tree.o Graph.o
main.o:	main.cpp 
	g++ -c main.cpp 
Tree.o:	Tree.cpp
	g++ -c Tree.cpp 
Graph.o: Graph.h
	g++ -c Graph.cpp 
clean:
	rm pro
	rm *.o  