all: clean build run

build: codewars.cpp
	g++ -o codewars.exe codewars.cpp

run: codewars.exe
	./codewars.exe

clean:
	rm -rf *.exe