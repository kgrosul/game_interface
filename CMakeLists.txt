cmake_minimum_required(VERSION 3.4)
project(game)

set(CMAKE_CXX_STANDARD 11)

enable_testing()
unset(WITH_TESTS CACHE)
unset(DEBUG CACHE)


if (WITH_TEST)
    enable_testing()

    find_package(GTest REQUIRED)

    include_directories(${GTEST_INCLUDE_DIRS})

    set(SOURCE_FILES buildings.cpp ships.cpp test.cpp planet.cpp)

    add_executable(game ${SOURCE_FILES})

    target_link_libraries(game ${GTEST_LIBRARIES} pthread)

elseif(DEBUG)
	
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

    set(SOURCE_FILES buildings.cpp ships.cpp main.cpp planet.cpp)

    add_executable(game ${SOURCE_FILES})
else()

    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

    set(SOURCE_FILES buildings.cpp ships.cpp main.cpp planet.cpp)

    add_executable(game ${SOURCE_FILES})
	
endif()
