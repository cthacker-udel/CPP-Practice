all: clean-win build run

build: %.cpp
	g++ -o $<.exe $<.cpp

run:
	./problem1.exe

clean:
	del *.exe