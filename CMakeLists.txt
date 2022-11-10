cmake_minimum_required(VERSION 3.18)

# Set the project name
project(blackbox)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./out)

# Off by default
option (TEST "Build tests" OFF)
option (ENABLE_INFO_OUTPUT "Enable verbose info output" OFF)
option (ENABLE_PROFILING "Enable profiling" OFF)

set(TARGET_SOURCES src/main.cpp)
                 
if (ENABLE_INFO_OUTPUT)
    add_compile_definitions(OUTPUT_LEVEL_INFO)
endif()

if (ENABLE_PROFILING)
    add_compile_definitions(BX_PROFILING)
endif()

include_directories(include/
                    libs/blackbox-common/include
                    libs/blackbox-common/libs/spdlog/include)

add_executable(${PROJECT_NAME} ${TARGET_SOURCES})

add_subdirectory(libs/blackbox-common)
target_link_libraries(${PROJECT_NAME} blackbox-common)

# Copy the configuration file into the build output directory.
add_custom_target(copy_config ALL
        COMMAND ${CMAKE_COMMAND} -E copy
        ${PROJECT_SOURCE_DIR}/config.json
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/config.json
        COMMENT "Copying config into build directory")

add_dependencies(blackbox copy_config)
