output: main.o Noisegate.o Wav.o Normalization.o
	g++ main.o Noisegate.o Wav.o Normalization.o -o output

main.o: main.cpp
	g++ -c main.cpp

Noisegate.o: Noisegate.h Noisegate.cpp
	g++ -c Noisegate.cpp

Wav.o: Wav.h Wav.cpp
	g++ -c -std=c++11 Wav.cpp

Normalization.o: Normalization.h Normalization.cpp
	g++ -c Normalization.cpp
clean:
	rm *.o audioprocessor
