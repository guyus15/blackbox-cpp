cmake_minimum_required(VERSION 3.18)

# Set the project name
project(blackbox)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./out)

# Off by default
option (TEST "Build tests" OFF)
option (ENABLE_INFO_OUTPUT "Enable verbose info output" OFF)
option (ENABLE_PROFILING "Enable profiling" OFF)

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
                   src/profiling/instrumentation.cpp
                   )

if (TEST)
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
                    
    add_executable(tests ${TEST_SOURCES})
endif()
                 
if (ENABLE_INFO_OUTPUT)
    add_compile_definitions(OUTPUT_LEVEL_INFO)
endif()

if (ENABLE_PROFILING)
    add_compile_definitions(BX_PROFILING)
endif()

include_directories(include/
                    libs/spdlog/include
                    )

add_executable(blackbox ${TARGET_SOURCES})
                 
add_subdirectory(libs/spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)


# Copy the configuration file into the build output directory.
add_custom_target(copy_config ALL
        COMMAND ${CMAKE_COMMAND} -E copy
        ${PROJECT_SOURCE_DIR}/config.json
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/config.json
        COMMENT "Copying config into build directory")

add_dependencies(blackbox copy_config)
