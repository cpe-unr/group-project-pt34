<<<<<<< HEAD
run: menu.o menu.cpp
	g++ -o run -std=c++11 menu.cpp
=======
output: main.cpp wav.o mylib.a
	g++ -std=c++11 -o audio main.cpp Noisegate.o Normalization.o Echo.o

mylib.a: Noisegate.o

wav.o: wav.cpp wav.h
	g++ -c -std=c++11 wav.cpp

mylib.a: Noisegate.o Normalization.o Echo.o
    ar suvr mylib.a Noisegate.o Normalization.o Echo.o

Noisegate.o: Noisegate.h Noisegate.cpp
    g++ -c Noisegate.cpp

Echo.o: Echo.h Echo.cpp
    g++ -c Echo.cpp

Normalization.o: Normalization.h Normalization.cpp
    g++ -c Normalization.cpp

clean:
	rm *.o output


>>>>>>> 6775e3ce7fc5fa54bb501b3139d5f458fc3c0674
