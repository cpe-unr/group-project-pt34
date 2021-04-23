audio: main.cpp wav.o wavPrint.o wavManager.o
	g++ -std=c++11 -o audio main.cpp wav.o wavPrint.o wavManager.o 

wav.o: wav.cpp wav.h
	g++ -c -std=c++11 wav.cpp

wavManager.o: wavManager.cpp wavManager.h
	g++ -c -std=c++11 wavManager.cpp



clean:
	rm *.o audio
