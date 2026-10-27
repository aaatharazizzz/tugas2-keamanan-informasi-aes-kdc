BUILD := ./bin
TARGETS := $(BUILD)/client $(BUILD)/kdc
SRC_DIR := ./src
INCLUDE_DIR := ./include ./src/aes ./src/client ./src/kdc
INCLUDE_FLAGS := $(add_prefix -I,$(INCLUDE_DIR))

CLIENT_SRC_DIR := ./src/client ./src/aes
CLIENT_SRC := $(wildcard $(CLIENT_SRC_DIR)/*.cpp)
CLIENT_OBJ := $(CLIENT_SRC:.cpp=.o)

KDC_SRC_DIR := ./src/kdc ./src/aes
KDC_SRC := $(wildcard $(KDC_SRC_DIRS)/*.cpp)
KDC_OBJ := $(KDC_SRC:.cpp=.o)

CXX := g++
CXXFLAGS := -std=c++20 $(INCLUDE_FLAGS) -Wall -Wextra
LDFLAGS := -lpthread

all: $(TARGETS)
$(BUILD)/client: $(CLIENT_OBJ)
$(BUILD)/kdc: $(KDC_OBJ)

$(TARGETS):
	$(CXX) $(LDFLAGS) $^ -o $@