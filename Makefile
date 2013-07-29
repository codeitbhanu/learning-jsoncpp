CXX=g++
FLAGS=-Llibs -Iincludes
LIBS=-static -ljson
SOURCE_FILES=src/addressbook.cpp src/main.cpp
BIN_FILE=addressbook.out

all:
	$(CXX) $(FLAGS) -o $(BIN_FILE) $(SOURCE_FILES) $(LIBS)
