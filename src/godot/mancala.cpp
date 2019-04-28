
#include "mancala.h"

namespace godot {

    struct Mancala::Impl {
        int _value;
    };

    Mancala::Mancala() : pImpl(std::make_unique<Impl>()) {}
    Mancala::~Mancala() {}

    void Mancala::_init() {}

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


/** GDNative Initialize **/
extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

/** GDNative Terminate **/
extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

/** NativeScript Initialize **/
extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);

    godot::register_class<godot::Mancala>();
}
