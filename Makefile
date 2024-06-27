.PHONY: all clean

EXECUTABLE := coordinate_systems

# Compiler flags
# CFLAGS := -g
# CFLAGS := -g -Wall -Wextra
CFLAGS := -Wall -O0 -s

# Compiler
CC := g++

BUILD_DIR := build
$(shell mkdir -p $(BUILD_DIR))

SRC := main.cpp coordinates.cpp
OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)
HEADER := coordinates.hpp

all: $(EXECUTABLE)
	@echo "Finished!"

$(BUILD_DIR)/%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD_DIR)
