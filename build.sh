#!/bin/bash

libs="-luser32 -lgdi32 -lopengl32"
includes="-Ithird_party -Ithird_party/Include"

defines="-D_CRT_SECURE_NO_WARNINGS"
warnings="-Wno-writable-strings -Wno-format-security -Wno-deprecated-declarations -Wno-inconsistent-dllimport"

clang++ $includes $defines -g src/main.cpp -o celeste.exe $libs $warnings
