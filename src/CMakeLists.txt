
cmake_minimum_required(VERSION 3.0)
project(godot-python)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(pybind11 REQUIRED)
find_package(Python COMPONENTS Interpreter Development)  # TODO: need Conan recipe

add_library(mancala mancala.h mancala.cpp)
target_link_libraries(mancala PRIVATE pybind11::pybind11 Python::Python)

install(TARGETS mancala 
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/py_mancala/ 
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/py_mancala
        FILES_MATCHING PATTERN "*.py")

add_subdirectory(executable)


