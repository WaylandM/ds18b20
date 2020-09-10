
node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto sensors = getValue<input_DEV>(ctx);
                
        DeviceAddress devAddr;
        devAddr[0] = getValue<input_ADDR0>(ctx);
        devAddr[1] = getValue<input_ADDR1>(ctx);
        devAddr[2] = getValue<input_ADDR2>(ctx);
        devAddr[3] = getValue<input_ADDR3>(ctx);
        devAddr[4] = getValue<input_ADDR4>(ctx);
        devAddr[5] = getValue<input_ADDR5>(ctx);
        devAddr[6] = getValue<input_ADDR6>(ctx);
        devAddr[7] = getValue<input_ADDR7>(ctx);
        
        emitValue<output_TempC>(ctx, sensors->getTempC(devAddr));
        emitValue<output_DONE>(ctx, 1);

    }
}
