cmake_minimum_required(VERSION 3.8)
project(game)

set(CMAKE_CXX_STANDARD 11)

enable_testing()



if (WITH_TEST)
    enable_testing()

    find_package(GTest REQUIRED)

    include_directories(${GTEST_INCLUDE_DIRS})

    set(SOURCE_FILES buildings.cpp ships.cpp test.cpp)

    add_executable(game ${SOURCE_FILES})

    target_link_libraries(game ${GTEST_LIBRARIES} pthread)

else()
    set(SOURCE_FILES buildings.cpp ships.cpp main.cpp)

    add_executable(game ${SOURCE_FILES})
endif()

