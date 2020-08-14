# WebAssembly tutorial

This project aim to show a practical usage example for WebAssembly where we 
decode a webp image format and transform it to a jpeg image.

With this, we could make any browser display a webp image even if they don't 
support the format.

## What is WebAssembly

WebAssembly is a binary format code that can be executed in a browser 
(desktop and mobile) and NodeJS. (?WeChat?)

Even though it's possible to write code directly in WebAssembly its main goal 
is to port code from other languages. 
- C, C++
- Rust
- Go
- Python

## References
[existing_C_to_wasm](https://developer.mozilla.org/en-US/docs/WebAssembly/existing_C_to_wasm)

[on-the-fly-webp-decoding](https://medium.com/@kennethrohde/on-the-fly-webp-decoding-using-wasm-and-a-service-worker-33e519d8c21e)

[emscripten](https://emscripten.org/docs/index.html)

[web assembly browser support](https://caniuse.com/#feat=wasm)

[use cases for webassembly](https://webassembly.org/docs/use-cases/#inside-the-browser)

[curated list of WebAssembly projects](https://github.com/mbasso/awesome-wasm)

## First step, clone this project

```
git clone https://github.com/alex-michaud/wasm-tutorial-webp-decode.git
```

## Download and install Emscripten sdk

Check if you already have Emscripten installed

```
emcc --version
```

**If it returned a version number, make sure it's at least 2.X**


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

**-01** (simple optimizations)

**-03** (advanced optimizations)

**-0s** (above 03)

**-0z** (above 0z)

**-s OPTION=VALUE** (options passed to the emscripten compiler)

**-g0** (Make no effort to keep code debuggable)

**-g3** (When compiling to object files, keep debug info, including JS whitespace, function names, and LLVM debug info)

**-o webp_module.js** (generate a target javascript file + companion wasm file)
