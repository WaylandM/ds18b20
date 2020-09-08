
// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/PaulStoffregen/OneWire"
#pragma XOD require "https://github.com/milesburton/Arduino-Temperature-Control-Library"

//Include C++ libraries
{{#global}}
#include <OneWire.h>
#include <DallasTemperature.h>
{{/global}}

// Reserve memory to store an instance of the Adafruit_BMP280 class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(DallasTemperature)];
};

// Define our custom types as a pointers on the class instances.
using Type = DallasTemperature*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);

    auto ow = getValue<input_OWB>(ctx);

    Type sensors = new (state->mem) DallasTemperature(ow);

    sensors->begin();
    
    emitValue<output_DEV>(ctx, sensors);
}
