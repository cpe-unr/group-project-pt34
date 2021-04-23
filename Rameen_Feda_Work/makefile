output: main.o Noisegate.o wav.o
	g++ main.o Noisegate.o wav.o -o output

main.o: main.cpp
	g++ -c main.cpp

Noisegate.o: Noisegate.h Noisegate.cpp
	g++ -c Noisegate.cpp

wav.o: wav.cpp wav.h
	g++ -c -std=c++11 wav.cpp

clean:
	rm *.o audioprocessor
