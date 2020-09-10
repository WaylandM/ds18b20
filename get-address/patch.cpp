
node {
    char str[32];
    CStringView view = CStringView(str);

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto sensors = getValue<input_DEV>(ctx);
        uint8_t idx = getValue<input_IDX>(ctx);
        
        DeviceAddress devAddr;
        sensors->getAddress(devAddr, idx);

        sprintf(str, "%02Xh-%02Xh-%02Xh-%02Xh-%02Xh-%02Xh-%02Xh-%02Xh",
                devAddr[0], devAddr[1], devAddr[2], devAddr[3],
                devAddr[4], devAddr[5], devAddr[6], devAddr[7]);

        emitValue<output_ADDR>(ctx, XString(&view));        
        
        emitValue<output_DONE>(ctx, 1);
    }
}
