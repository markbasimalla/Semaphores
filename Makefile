CXX = g++
CXXFLAGS = -lpthread -lrt -Wall -Iinc
TARGETS = activate_motor running_belt
BUILDDIR = build

ACTIVATE_SRC = src/main_activate_motor.cpp src/activate_motor.cpp src/memory_setup.cpp
RUNNING_SRC = src/main_running_belt.cpp src/running_belt.cpp src/memory_setup.cpp

OBJ_ACTIVATE = $(patsubst src/%.cpp,$(BUILDDIR)/%.o,$(ACTIVATE_SRC))
OBJ_RUNNING = $(patsubst src/%.cpp,$(BUILDDIR)/%.o,$(RUNNING_SRC))

all: $(BUILDDIR) $(TARGETS)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

activate_motor: $(OBJ_ACTIVATE)
	$(CXX) -o $@ $^ $(CXXFLAGS)

running_belt: $(OBJ_RUNNING)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(BUILDDIR)/%.o: src/%.cpp | $(BUILDDIR)
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	rm -f $(BUILDDIR)/*.o $(TARGETS)

.PHONY: all clean
