#!/bin/bash

podman run -it --rm -v "$PWD":/prog:Z devkitppc bash -c "cd /prog; make clean; make"

cp prog.dol pack/boot.dol

rm -rf apps/
mkdir -p apps/memrrtiks-wii
cp -r pack/* apps/memrrtiks-wii/
zip -r memrrtiks-wii.zip apps/
rm -rf apps/
