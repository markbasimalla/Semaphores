CXX = g++

CXXFLAGS = -lpthread -lrt -Wall -Iinc

TARGETS = activate_motor running_belt

ACTIVATE_SRC = src/main_activate_motor.cpp src/activate_motor.cpp src/memory_setup.cpp
RUNNING_SRC = src/main_running_belt.cpp src/running_belt.cpp src/memory_setup.cpp

all: $(TARGETS)

activate_motor: $(ACTIVATE_SRC)
	$(CXX) -o $@ $(ACTIVATE_SRC) $(CXXFLAGS)

running_belt: $(RUNNING_SRC)
	$(CXX) -o $@ $(RUNNING_SRC) $(CXXFLAGS)

clean:
	rm -f $(TARGETS)

.PHONY: all clean

