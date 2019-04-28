
cmake_minimum_required(VERSION 3.0)
project(godot-python CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(pybind11 REQUIRED)

set(Python_USE_STATIC_LIBS TRUE)
find_package(Python COMPONENTS Development)  # TODO: need Conan recipe
message(">>>> ${Python_LIBRARIES}")
message(">>>> ${Python_LIBRARY_DIRS}")
message(">>>> ${Python_RUNTIME_LIBRARY_DIRS}")

add_library(mancala mancala.h mancala.cpp)
target_link_libraries(mancala PRIVATE pybind11::pybind11 ${Python_LIBRARIES})
target_include_directories(mancala PRIVATE ${Python_INCLUDE_DIRS})

install(TARGETS mancala 
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/py_mancala/ 
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/py_mancala
        FILES_MATCHING PATTERN "*.py")

add_subdirectory(godot)
add_subdirectory(executable)


