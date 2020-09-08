
// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/PaulStoffregen/OneWire"

//Include C++ libraries
#include <OneWire.h>


// Reserve memory to store an instance of the Adafruit_BMP280 class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(OneWire)];
};

// Define our custom types as a pointers on the class instances.
using Type = OneWire*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);
    
    auto port = getValue<input_PORT>(ctx);
    if (!isValidDigitalPort(port)) {
        raiseError(ctx); // Invalid port
        return;
    }

    Type ow = new (state->mem) OneWire(port);
    
    emitValue<output_OWB>(ctx, ow);
}
