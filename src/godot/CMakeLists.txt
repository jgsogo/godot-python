
cmake_minimum_required(VERSION 3.0)
project(godot-python CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create imported target for Godot libraries
add_library(godot::godot INTERFACE IMPORTED)
set_target_properties(godot::godot PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "/Users/jgsogo/dev/projects/codeattack/godot-python/gdnative_cpp_example/godot-cpp/include;/Users/jgsogo/dev/projects/codeattack/godot-python/gdnative_cpp_example/godot-cpp/godot_headers")
set_target_properties(godot::godot PROPERTIES INTERFACE_LINK_LIBRARIES "/Users/jgsogo/dev/projects/codeattack/godot-python/gdnative_cpp_example/godot-cpp/bin/libgodot-cpp.osx.64.a")

add_library(godot_mancala SHARED mancala.h api.c mancala.cpp)
target_link_libraries(godot_mancala PRIVATE godot::godot)
set_property(TARGET godot_mancala PROPERTY POSITION_INDEPENDENT_CODE ON)

install(TARGETS godot_mancala 
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

install(FILES 
            ${CMAKE_CURRENT_LIST_DIR}/godot_mancala.gdnlib
            ${CMAKE_CURRENT_LIST_DIR}/godot_mancala.gdns
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
