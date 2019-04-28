
cmake_minimum_required(VERSION 3.0)
project(godot-python CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create imported target for Godot libraries
find_package(godot-cpp REQUIRED)

add_library(godot_mancala SHARED mancala.h mancala.cpp)
target_link_libraries(godot_mancala PRIVATE godot-cpp::godot-cpp pybind11::pybind11 mancala)
set_property(TARGET godot_mancala PROPERTY POSITION_INDEPENDENT_CODE ON)
target_link_libraries(godot_mancala PRIVATE pybind11::pybind11 ${Python_LIBRARIES})
target_include_directories(godot_mancala PRIVATE ${Python_INCLUDE_DIRS})

install(TARGETS godot_mancala 
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

install(FILES 
            ${CMAKE_CURRENT_LIST_DIR}/godot_mancala.gdnlib
            ${CMAKE_CURRENT_LIST_DIR}/godot_mancala.gdns
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
