ofiles = main.o crate.o warehouse.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp crate.o warehouse.o
	$(gpp_o) main.cpp

crate.o: crate.cpp crate.h
	$(gpp_o) crate.cpp

warehouse.o: warehouse.cpp warehouse.h
	$(gpp_o) warehouse.cpp

run: main
	./main
	
clean:
	rm *.o main