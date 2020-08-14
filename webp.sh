#!/bin/zsh
# emcc -O1 -g -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]' -s ALLOW_MEMORY_GROWTH=1 -I libwebp webp.c libwebp/src/{dec,dsp,demux,enc,mux,utils}/*.c
emcc -Oz -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap", "getValue"]' \
    -s EXPORTED_FUNCTIONS="['_free', '_malloc']" \
    -s ALLOW_MEMORY_GROWTH=1 \
    -o webp_module.js \
    -I libwebp \
    webp.c \
    libwebp/src/{dec,dsp,demux,enc,mux,utils}/*.c \
    -g0
