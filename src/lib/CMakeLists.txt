
cmake_minimum_required(VERSION 3.0)
project(godot-python CXX)

add_library(mancala mancala.h mancala.cpp)
target_link_libraries(mancala PRIVATE pybind11::pybind11 ${Python_LIBRARIES})
target_include_directories(mancala PRIVATE ${Python_INCLUDE_DIRS})

install(TARGETS mancala 
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
