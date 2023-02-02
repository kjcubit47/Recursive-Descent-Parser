CXX = gcc
CXXFLAGS = -g -Wall

OBJECTS = lexer.o parser.o symbol.o main.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm *.o main

