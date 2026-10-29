BUILD := ./bin
TARGETS := $(BUILD)/client $(BUILD)/kdc
SRC_DIR := ./src
INCLUDE_DIR := ./include ./src/aes ./src/client ./src/kdc ./src/common
INCLUDE_FLAGS := $(addprefix -I,$(INCLUDE_DIR))

CLIENT_SRC_DIR := ./src/client ./src/aes ./src/common
CLIENT_SRC := $(foreach dir, $(CLIENT_SRC_DIR), $(wildcard $(dir)/*.cpp))
CLIENT_OBJ := $(CLIENT_SRC:.cpp=.o)

KDC_SRC_DIR := ./src/kdc ./src/aes ./src/common
KDC_SRC := $(foreach dir, $(KDC_SRC_DIR), $(wildcard $(dir)/*.cpp))
KDC_OBJ := $(KDC_SRC:.cpp=.o)

CXX := g++
CXXFLAGS := -std=c++20 $(INCLUDE_FLAGS) -Wall -Wextra
LDFLAGS :=

all: $(BUILD)/client $(BUILD)/kdc
$(BUILD)/client: $(CLIENT_OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
$(BUILD)/kdc: $(KDC_OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean
clean:
	rm -rf $(BUILD)