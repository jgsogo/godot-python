
#pragma once 

#include <core/Godot.hpp>
#include <Reference.hpp>

#include <memory>

namespace godot {

    class Mancala : public Reference {
        GODOT_CLASS(Mancala, Reference);
    public:
        Mancala();
        ~Mancala();

        void _init(); // _init must exist as it is called by Godot
        void test_void_method();
        Variant method(Variant arg);
        static void _register_methods();
        
        String _name;
        int _value;

        void set_value(int p_value);
        int get_value() const;

    protected:
        struct Impl;
        std::unique_ptr<Impl> pImpl;
    };

}