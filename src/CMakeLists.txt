
cmake_minimum_required(VERSION 3.0)
project(godot-python CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(pybind11 REQUIRED)

set(Python_USE_STATIC_LIBS TRUE)
find_package(Python COMPONENTS Development)  # TODO: need Conan recipe

add_subdirectory(lib)
add_subdirectory(godot)
add_subdirectory(executable)

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/py_mancala/ 
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/py_mancala
        FILES_MATCHING PATTERN "*.py")

