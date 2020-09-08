#pragma XOD require "https://github.com/milesburton/Arduino-Temperature-Control-Library"

#include <DallasTemperature.h>

node {
    meta {
        using Type = DallasTemperature*;
    }

    uint8_t mem[sizeof(DallasTemperature)];

    void evaluate(Context ctx) {
        if (!isSettingUp()) return;

        auto ow = getValue<input_OWB>(ctx);

        Type sensors = new (mem) DallasTemperature(ow);

        sensors->begin();

        emitValue<output_DEV>(ctx, sensors);
    }
}
