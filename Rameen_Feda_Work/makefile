output: main.cpp Noisegate.o Wav.o Normalization.o Echo.o
	g++ main.cpp Noisegate.o Wav.o Normalization.o Echo.o -o output

Noisegate.o: Noisegate.h Noisegate.cpp
	g++ -c Noisegate.cpp

Echo.o: Echo.h Echo.cpp
	g++ -c Echo.cpp

Wav.o: Wav.h Wav.cpp
	g++ -c -std=c++11 Wav.cpp

Normalization.o: Normalization.h Normalization.cpp
	g++ -c Normalization.cpp
clean:
	rm *.o audioprocessor
