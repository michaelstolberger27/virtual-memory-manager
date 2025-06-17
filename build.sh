#!/bin/bash
set -e

if [ "$1" == "clean" ]; then
    echo "Cleaning build artifacts..."
    rm -rf .build
    rm -f vmm_simulator
    rm -f src/*.o
    exit 0
fi

mkdir -p .build
cd .build
cmake ..
make
