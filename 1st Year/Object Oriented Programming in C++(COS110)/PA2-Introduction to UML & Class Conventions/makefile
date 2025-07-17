ofiles = main.o Accessory.o Engine.o Car.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp Accessory.o Engine.o Car.o
	$(gpp_o) main.cpp

Accessory.o: Accessory.cpp Accessory.h
	$(gpp_o) Accessory.cpp

Engine.o: Engine.cpp Engine.h
	$(gpp_o) Engine.cpp

Car.o: Car.cpp Car.h
	$(gpp_o) Car.cpp


run: main
	./main
	
clean:
	rm *.o main