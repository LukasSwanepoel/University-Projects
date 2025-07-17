ofiles = main.o Node.o List.o SinglyLinked.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp Node.o List.o SinglyLinked.o
	$(gpp_o) main.cpp

Node.o: Node.cpp Node.h
	$(gpp_o) Node.cpp

List.o: List.cpp List.h
	$(gpp_o) List.cpp

SinglyLinked.o: SinglyLinked.cpp SinglyLinked.h
	$(gpp_o) SinglyLinked.cpp

run: main
	./main
	
clean:
	rm *.o main