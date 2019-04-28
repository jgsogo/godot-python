
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
        py::object mancala_class = py::module::import("py_mancala").attr("Mancala");
        pImpl->mancala = mancala_class();
        pImpl->get_state = pImpl->mancala.attr("get_state");
        pImpl->play_position = pImpl->mancala.attr("play_position");
    };
    Mancala::~Mancala() {};

    std::string Mancala::get_state() const {
        auto state = pImpl->get_state();
        return state.cast<std::string>();
    }

    void Mancala::play_position(const std::string& position) {
        pImpl->play_position(position);
    }

}
