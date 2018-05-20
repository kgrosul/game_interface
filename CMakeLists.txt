cmake_minimum_required(VERSION 3.4)
project(game)

set(CMAKE_CXX_STANDARD 11)

enable_testing()
unset(WITH_TESTS CACHE)
unset(DEBUG CACHE)

option(BUILD_DOC "Build documentation" ON)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)


if (WITH_TEST)
    enable_testing()

    find_package(GTest REQUIRED)

    include_directories(${GTEST_INCLUDE_DIRS})

    set(SOURCE_FILES buildings.cpp ships.cpp main.cpp.cpp planet.cpp commands.cpp)

    add_executable(game ${SOURCE_FILES})

    target_link_libraries(game ${GTEST_LIBRARIES} pthread)

elseif(DEBUG)
	
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

    set(SOURCE_FILES buildings.cpp ships.cpp main.cpp planet.cpp commands.cpp)

    add_executable(game ${SOURCE_FILES})
else()

    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

    set(SOURCE_FILES buildings.cpp ships.cpp main.cpp planet.cpp commands.cpp)

    add_executable(game ${SOURCE_FILES})
	
endif()
