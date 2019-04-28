
cmake_minimum_required(VERSION 3.0)
project(godot-python)

add_executable(executable main.cpp)
target_link_libraries(executable PRIVATE pybind11::pybind11 Python::Python mancala)

install(TARGETS executable 
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
