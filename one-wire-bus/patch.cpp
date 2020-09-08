// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/PaulStoffregen/OneWire"

//Include C++ libraries
#include <OneWire.h>

// Define our custom type as a pointer on the class instance.
using Type = OneWire*;

node {

    meta {
        using Type = OneWire*;
    }

    static_assert(isValidDigitalPort(constant_input_PORT), "must be a valid digital port");

    OneWire ow = OneWire(constant_input_PORT);

    void evaluate(Context ctx) {
        if (!isSettingUp()) return;

        emitValue<output_OWB>(ctx, &ow);
    }
}
