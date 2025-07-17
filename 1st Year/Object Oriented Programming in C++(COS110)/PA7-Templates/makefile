ofiles = main.o Tuple.o Dictionary.o ScoreBoard.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp Tuple.o Dictionary.o ScoreBoard.o
	$(gpp_o) main.cpp

Tuple.o: Tuple.cpp Tuple.h
	$(gpp_o) Tuple.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	$(gpp_o) Dictionary.cpp

ScoreBoard.o: ScoreBoard.cpp ScoreBoard.h
	$(gpp_o) ScoreBoard.cpp


run: main
	./main
	
clean:
	rm *.o main