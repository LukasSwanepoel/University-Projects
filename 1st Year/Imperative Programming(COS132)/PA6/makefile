main: main.o dog.h dog.o citizen.h citizen.o  
	g++ -static dog.o citizen.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp
	
dog.o: dog.h dog.cpp  
	g++ -c dog.cpp
	
citizen.o: citizen.h citizen.cpp  
	g++ -c citizen.cpp

run:
	./main
	
clean:
	rm -f dog.o citizen.o main.o main