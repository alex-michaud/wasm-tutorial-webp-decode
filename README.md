https://developer.mozilla.org/en-US/docs/WebAssembly/existing_C_to_wasm

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

### emcc

-01 simple optimizations

-03 advanced optimizations

-s OPTION=VALUE options passed to the emscripten compiler
