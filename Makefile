CXX=g++
FLAGS=-Llibs -Iincludes
LIBS=-static -ljson

all:
	$(CXX) $(FLAGS) -o addressbook.out addressbook.cpp main.cpp $(LIBS)
