#include "toggle.h"

// Simple tracking of a key combo being pressed then released.
// Cycles throught three states on buttons release.
class Tristate {
public:
    Tristate() {}

    Tristate(int8_t val) : state(val) {}

    bool changed(bool buttons) {
        if (pressed.changed(buttons)) {
            state = (state + 1) % 3;
            return true;
        }
        return false;
    }

    operator int8_t() const {
        return state;
    }

    void operator =(const int8_t val) {
        state = val;
    }

private:
    int8_t state { 0 };
    Toggle pressed { false };
};
