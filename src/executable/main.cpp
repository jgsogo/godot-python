
#include <iostream>
#include <pybind11/embed.h>
#include "../mancala.h"

namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive
    py::print("Hello Python!"); // use the Python API

    // Add current working dir (to find the Python module)
    py::object sys_path = py::module::import("sys").attr("path");
    py::object path_insert = sys_path.attr("insert");
    path_insert(0, "/Users/jgsogo/dev/projects/codeattack/godot-python/build/package/bin");

    python::Mancala mancala;
    auto pos = mancala.get_state();
    std::cout << "(c++) pos: " << pos << "\n";
    mancala.play_position("new pos");
}
