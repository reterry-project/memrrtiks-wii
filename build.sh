#!/bin/bash

podman run -it --rm -v "$PWD":/prog devkitppc bash -c "cd /prog; make clean; make"

cp prog.dol pack/boot.dol
