output: main.cpp wav.o mylib.a
	g++ -std=c++11 -o output main.cpp wav.o mylib.a

wav.o: wav.cpp wav.h
	g++ -c -std=c++11 wav.cpp

mylib.a: Noisegate.o Normalization.o Echo.o
	ar suvr mylib.a Noisegate.o Normalization.o Echo.o

Noisegate.o: Noisegate.h Noisegate.cpp
	g++ -c -std=c++11 Noisegate.cpp

Echo.o: Echo.h Echo.cpp
	g++ -c -std=c++11 Echo.cpp

Normalization.o: Normalization.h Normalization.cpp
	g++ -c -std=c++14 Normalization.cpp

CSV.o: CSV.h CSV.cpp
	g++ -c -std=c++11 CSV.cpp

clean:
	rm *.o output
