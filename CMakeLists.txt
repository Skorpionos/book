message(STATUS "start running cmake...")

cmake_minimum_required(VERSION 3.10)

project(book)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_subdirectory(libs/fmt)
include_directories(libs/fmt/include)

set(SOURCE_FILES workspace/main.cpp)

add_executable(solution
        ${SOURCE_FILES}
        workspace/internal/time.cpp
        workspace/study/strings.cpp)


target_link_libraries(solution fmt-header-only ${CMAKE_EXE_LINKER_FLAGS})
