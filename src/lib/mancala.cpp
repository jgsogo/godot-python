
#include "mancala.h"
#include <pybind11/embed.h>

namespace python {
    namespace py = pybind11;

    struct Mancala::Impl {
        py::object mancala;
        py::object get_state;
        py::object play_position;
    };

    Mancala::Mancala() : pImpl(std::make_unique<Impl>()) {
        // State is stored inside the python module
        pImpl->mancala = py::module::import("py_mancala").attr("mancala");
        pImpl->get_state = pImpl->mancala.attr("get_state");
        pImpl->play_position = pImpl->mancala.attr("play_position");
    };
    Mancala::~Mancala() {};

    std::string Mancala::get_state() const {
        return pImpl->get_state().cast<std::string>();
    }

    void Mancala::play_position(const std::string& position) {
        pImpl->play_position(position);
    }

}
