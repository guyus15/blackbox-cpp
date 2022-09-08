cmake_minimum_required(VERSION 3.24)

# Set the project name
project(blackbox)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./out)

set(TARGET_SOURCES src/main.cpp
                   src/packet/content.cpp
                   src/packet/headers.cpp
                   src/packet/packet.cpp
                   src/packet/serial_data_transfer.cpp
                   src/packet/packet_types.cpp
                   src/packet/packet_decoding.cpp
                   src/serial/serialib.cpp
                   src/config.cpp
                   src/logger.cpp
                   src/clock.cpp
                   )

set(TEST_SOURCES tests/run_tests.cpp
                 tests/content_test.cpp
                 tests/headers_test.cpp
                 tests/packet_test.cpp
                 tests/config_test.cpp
                 src/packet/content.cpp
                 src/packet/headers.cpp
                 src/packet/packet.cpp
                 src/packet/serial_data_transfer.cpp
                 src/serial/serialib.cpp
                 src/config.cpp
                 )

include_directories(include/)

add_executable(blackbox ${TARGET_SOURCES})
add_executable(tests ${TEST_SOURCES})

# Copy the configuration file into the build output directory.
execute_process(
    COMMAND bash -c "cp ./config.json build/out/config.json"
)