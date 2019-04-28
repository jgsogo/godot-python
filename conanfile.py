
from conans import ConanFile, CMake

class GodotPython(ConanFile):
    name = "godot-python"
    version = "0.1"

    generators = "cmake_find_package"

    def requirements(self):
        self.requires("pybind11/2.2.4@conan/stable")

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()
