ofiles = main.o MyString.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp MyString.h
	$(gpp_o) main.cpp

MyString.o: MyString.cpp MyString.h
	$(gpp_o) MyString.cpp

run: main
	./main
	
clean:
	rm -f *.o main