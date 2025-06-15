CXX = g++
CXXFLAGS = -std=c++14 -Wall
INCLUDES = -Iinclude

SRC = src/main.cpp src/FIFOManager.cpp src/LRUManager.cpp src/OptimalManager.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = vmm_simulator

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f src/*.o $(EXEC)

