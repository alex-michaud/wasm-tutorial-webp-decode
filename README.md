# WebAssembly tutorial

This project aim to show a practical usage example for WebAssembly where we 
decode a webp image format and transform it to a jpeg image.

With this, we could make any browser display a webp image even if they don't 
support the format.   

## References
[existing_C_to_wasm](https://developer.mozilla.org/en-US/docs/WebAssembly/existing_C_to_wasm)

[on-the-fly-webp-decoding](https://medium.com/@kennethrohde/on-the-fly-webp-decoding-using-wasm-and-a-service-worker-33e519d8c21e)

[emscripten](https://emscripten.org/docs/index.html)

[web assembly browser support](https://caniuse.com/#feat=wasm)

[use cases for webassembly](https://webassembly.org/docs/use-cases/#inside-the-browser)

[curated list of WebAssembly projects](https://github.com/mbasso/awesome-wasm)

## Download and install Emscripten sdk

https://emscripten.org/docs/getting_started/downloads.html

(Do not install emscripten from the package manager, that version is too old)

#### Get the emsdk repo *(does not need to be at the root of the project)*
```
git clone https://github.com/emscripten-core/emsdk.git
```

#### Enter that directory
```
cd emsdk
```

#### Fetch the latest version of the emsdk *(not needed the first time you clone)*
```
git pull
```

#### Download and install the latest SDK tools.
```
./emsdk install latest
```

#### Make the "latest" SDK "active" for the current user. *(writes .emscripten file)*
```
./emsdk activate latest
```

#### Activate PATH and other environment variables in the current terminal
```
source ./emsdk_env.sh
```

#### Make sure emsdk is installed properly 
```
emcc --version
```

## Clone libwebp *(at the root of the project)* 
```
git clone https://github.com/webmproject/libwebp
```

## Run the script to create the javascript and wasm module
```
./webp.sh
```

### Notes about the emscripten compiler *(webp.sh)*

-01 simple optimizations

-03 advanced optimizations

-s OPTION=VALUE options passed to the emscripten compiler
