CC = g++

PROJECT = blackbox

BIN = bin
TEST_BIN = tests/bin

# Target
TARGET_SOURCES = src/main.cpp src/packet/content.cpp src/packet/headers.cpp
TARGET_INCLUDES = -I include/

# Tests
TEST_SOURCES = tests/run_tests.cpp \
			   tests/content_test.cpp \
			   tests/headers_test.cpp \
			   src/packet/content.cpp \
			   src/packet/headers.cpp \

TEST_INCLUDES = -I include/
TEST_NAME = run_tests

main:
	$(CC) $(TARGET_SOURCES) -o $(BIN)/$(PROJECT) $(TARGET_INCLUDES) -std=c++17

.PHONY test:
	$(CC) $(TEST_SOURCES) -o $(TEST_BIN)/$(TEST_NAME) $(TEST_INCLUDES) -std=c++17

all: main tests

default-target: all