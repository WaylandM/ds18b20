
node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto sensors = getValue<input_DEV>(ctx);
        
        sensors->setResolution(getValue<input_DEV>(ctx));

        emitValue<output_DONE>(ctx, 1);
    }
}
