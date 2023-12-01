BIN1 = p1
BIN2 = p2

CXX = clang++
CXXFLAGS  = -Wall -Wextra -Werror
CXXFLAGS += -std=c++17

BUILD_DIR = build

P1_DIR = part1
SRC1 = $(shell find "$(P1_DIR)" -name '*.cpp')
OBJ1 = $(SRC1:%=$(BUILD_DIR)/%.o)

P2_DIR = part2
SRC2 = $(shell find "$(P2_DIR)" -name '*.cpp')
OBJ2 = $(SRC2:%=$(BUILD_DIR)/%.o)

.PHONY: all
all: p1

.PHONY: p1
p1: $(BUILD_DIR)/$(BIN1)

$(BUILD_DIR)/$(BIN1): $(OBJ1)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/$(BIN2): $(OBJ2)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(P1_DIR) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
