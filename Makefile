CC = g++

PROJECT = blackbox

BIN = bin

TARGET_SOURCES = src/main.cpp src/packet/content.cpp
TARGET_INCLUDES = -I include/

main:
	$(CC) $(TARGET_SOURCES) -o $(BIN)/$(PROJECT) $(TARGET_INCLUDES) -std=c++17

all: main