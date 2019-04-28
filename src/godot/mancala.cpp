
#include "mancala.h"
#include "../mancala.h"
#include <pybind11/embed.h>

namespace godot {

    struct Mancala::Impl {
        int _value;
        python::Mancala mancala;
    };

    Mancala::Mancala() : pImpl(std::make_unique<Impl>()) {
        Godot::print("Mancala::Mancala");
    }
    Mancala::~Mancala() {}

    void Mancala::_init() {
        Godot::print("Mancala::_init");
        Godot::print(pImpl->mancala.get_state().c_str());
    }

    void Mancala::test_void_method() {
        Godot::print("This is test");
    }

    Variant Mancala::method(Variant arg) {
        Variant ret;
        ret = arg;

        return ret;
    }

    void Mancala::_register_methods() {
        register_method("method", &Mancala::method);
        
        /**
         * How to register exports like gdscript
         * export var _name = "SimpleClass"
         **/
        //register_property<Mancala, String>("base/name", &Mancala::_name, String("SimpleClass"));

        /* or alternatively with getter and setter methods */
        register_property<Mancala, int>("base/value", &Mancala::set_value, &Mancala::get_value, 0);

        /** For registering signal **/
        // register_signal<SimpleClass>("signal_name");
        // register_signal<SimpleClass>("signal_name", "string_argument", GODOT_VARIANT_TYPE_STRING)
    }
    
    void Mancala::set_value(int p_value) {
        pImpl->_value = p_value;
    }
    int Mancala::get_value() const {
        return pImpl->_value;
    }

}


std::unique_ptr<pybind11::scoped_interpreter> guard;

/** GDNative Initialize **/
extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    guard = std::make_unique<pybind11::scoped_interpreter>();
    // Add current working dir (to find the Python module)
    pybind11::object sys_path = pybind11::module::import("sys").attr("path");
    pybind11::object path_insert = sys_path.attr("insert");
    path_insert(0, "/Users/jgsogo/dev/projects/codeattack/godot-python/build/package/bin");
    
    godot::Godot::gdnative_init(o);
}

/** GDNative Terminate **/
extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    guard.reset();
    godot::Godot::gdnative_terminate(o);
}

/** NativeScript Initialize **/
extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);
    godot::register_class<godot::Mancala>();
}
