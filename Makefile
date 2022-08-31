CC = g++

PROJECT = blackbox

BIN = bin
TEST_BIN = tests/bin

# Target
TARGET_SOURCES = src/main.cpp \
				 src/packet/content.cpp \
				 src/packet/headers.cpp \
				 src/packet/packet.cpp \
				 src/packet/serial_data_transfer.cpp \
				 src/serial/serialib.cpp
				 
TARGET_INCLUDES = -I include/ \
				  -I libs/yaml-cpp/include

# Tests
TEST_SOURCES = tests/run_tests.cpp \
			   tests/content_test.cpp \
			   tests/headers_test.cpp \
			   tests/packet_test.cpp \
			   src/packet/content.cpp \
			   src/packet/headers.cpp \
			   src/packet/packet.cpp \
			   src/packet/serial_data_transfer.cpp \
			   src/serial/serialib.cpp

TEST_INCLUDES = -I include/ \
				-I libs/yaml-cpp/include
				
TEST_NAME = run_tests

LIBS = -L libs/yaml-cpp/build/ -lyaml-cpp

lib:
	cd libs/yaml-cpp/ && if not exist build mkdir build && cd build \
	&& cmake -G "Unix Makefiles" -DYAML_BUILD_SHARED_LIBS=OFF -DCMAKE_MAKE_PROGRAM=mingw32-make .. \
	&& mingw32-make

main:
	$(CC) $(TARGET_SOURCES) -o $(BIN)/$(PROJECT) $(TARGET_INCLUDES) $(LIBS) -std=c++17

.PHONY test:
	$(CC) $(TEST_SOURCES) -o $(TEST_BIN)/$(TEST_NAME) $(TEST_INCLUDES) $(LIBS) -std=c++17

all: libs main tests

default-target: all