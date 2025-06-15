CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = src/main.cpp src/MemoryManager.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = vmm_simulator

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(EXEC)
