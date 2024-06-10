.PHONY: all clean

# Set the executable name
EXECUTABLE := coordinate_systems

# Compiler flags
# CFLAGS := -g
# CFLAGS := -g -Wall -Wextra
CFLAGS := -Wall -O0 -s

# Set the compiler
CC := g++

# BUILD_DIR is a variable which has the string build
# the following line creates a directory to put the exe and the objects
BUILD_DIR := build
$(shell mkdir -p $(BUILD_DIR))

SRC := main.cpp coordinates.cpp
OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)
HEADER := coordinates.hpp

all: $(EXECUTABLE)
	@echo "Finished!"

# The following creates the object files and then compiles
# $(HEADER) is to update changes in the header files
$(BUILD_DIR)/%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# The following creates the executable.
# $(OBJ) is expanding on our list of strings that are our objects
$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# This removes the entire build folder
clean:
	rm -rf $(BUILD_DIR)
