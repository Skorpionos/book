message(STATUS "start running cmake...")

cmake_minimum_required(VERSION 3.10)
project(book)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

#add_subdirectory(libs/googletest)
#include_directories(libs/googletest/googletest/include)

add_subdirectory(libs/fmt)
include_directories(libs/fmt/include)

set(SOURCE_FILES
        workspace/study/strings.cpp
        )
#        workspace/internal/print.h
#        workspace/internal/print_impl.h
#        workspace/internal/time.h
#        workspace/internal/time.cpp
#        workspace/study/classes/person.h
#        workspace/containers/list.h
#        workspace/study/classes/character_actions.h
#        workspace/study/classes/character_actions.cpp
#        workspace/tests/test_characters.h
#        workspace/tests/test_characters.cpp
#        workspace/study/arrays-study.cpp

add_executable(MAIN
        ${SOURCE_FILES}
        workspace/main.cpp)
target_link_libraries(MAIN PRIVATE fmt-header-only)

#add_executable(gtest_clock
#        ${SOURCE_FILES}
#        workspace/gtests/gtest_clock.cpp)
#target_link_libraries(gtest_clock gtest gtest_main)

#add_executable(gtest_array
#        ${SOURCE_FILES}
#        workspace/gtests/gtest_array.cpp)
#target_link_libraries(gtest_array gtest gtest_main)

#find_package(Boost COMPONENTS #[[system filesystem]] program_options REQUIRED)

#if(Boost_FOUND)
#    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
#    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
#    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    #    message(STATUS "Boost_PROGRAM_OPTIONS: ${Boost_PROGRAM_OPTIONS}")
#    include_directories(${Boost_INCLUDE_DIRS})

#    target_link_libraries(analyzer ${Boost_LIBRARIES})
#endif()