
#pragma once

#include <memory>
#include <string>


namespace python {

    class Mancala {
    public:
        Mancala();
        ~Mancala();

        std::string get_state() const;
        void play_position(const std::string& position);
    protected:
        struct Impl;
        std::unique_ptr<Impl> pImpl;
    };

}