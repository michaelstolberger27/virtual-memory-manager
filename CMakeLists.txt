cmake_minimum_required(VERSION 3.10)
project(virtual_memory_manager)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/FIFOManager.cpp
    src/LRUManager.cpp
    src/OptimalManager.cpp
)

set(OBJECTS "")

foreach(SRC_FILE ${SOURCES})
    get_filename_component(FILENAME ${SRC_FILE} NAME_WE)
    set(OBJ_FILE "${CMAKE_SOURCE_DIR}/src/${FILENAME}.o")

    add_custom_command(
        OUTPUT ${OBJ_FILE}
        COMMAND ${CMAKE_CXX_COMPILER} ${CMAKE_CXX_FLAGS} -I${CMAKE_SOURCE_DIR}/include -std=c++14 -c ${CMAKE_SOURCE_DIR}/${SRC_FILE} -o ${OBJ_FILE}
        DEPENDS ${SRC_FILE}
        COMMENT "Compiling ${SRC_FILE} -> src/${FILENAME}.o"
        VERBATIM
    )

    list(APPEND OBJECTS ${OBJ_FILE})
endforeach()

add_custom_target(vmm_simulator ALL
    DEPENDS ${OBJECTS}
    COMMAND ${CMAKE_CXX_COMPILER} ${OBJECTS} -o ${CMAKE_SOURCE_DIR}/vmm_simulator
    COMMENT "Linking executable vmm_simulator"
)


