message(STATUS "start running cmake...")

cmake_minimum_required(VERSION 3.10)
project(book)

#set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")

add_subdirectory(libs/googletest)

include_directories(libs/googletest/googletest/include)

set(SOURCE_FILES
        workspace/main.cpp
        workspace/internal_utilities/print.hpp
        workspace/internal_utilities/print_impl.hpp
        workspace/internal_utilities/time.h
        workspace/internal_utilities/time.cpp
        workspace/trainings/person.h
        workspace/containers/list.h
        workspace/trainings/character_actions.h
        workspace/trainings/character_actions.cpp
        workspace/tests/test_characters.h
        workspace/tests/test_characters.cpp)

add_executable(book
        ${SOURCE_FILES}
        workspace/main.cpp)

target_link_libraries(book)

add_executable(test1
        ${SOURCE_FILES}
        workspace/gtests/test1.cpp)

target_link_libraries(test1 gtest gtest_main)


#find_package(Boost COMPONENTS #[[system filesystem]] program_options REQUIRED)

#if(Boost_FOUND)
#    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
#    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
#    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    #    message(STATUS "Boost_PROGRAM_OPTIONS: ${Boost_PROGRAM_OPTIONS}")
#    include_directories(${Boost_INCLUDE_DIRS})

#    target_link_libraries(analyzer ${Boost_LIBRARIES})
#endif()