CXX = g++
CXXFLAGS = -g -Wall
OUT = now
objects = base.o command.o games.o genmap.o main.o

$(OUT): $(objects)
	$(CXX) $(objects) -o $@

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm $(objects) $(OUT)