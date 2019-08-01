#!/bin/bash

COCONUT_DATA_DIR=coconut-data

make -C CoCoNut &&
mkdir $COCONUT_DATA_DIR &&
mkdir $COCONUT_DATA_DIR/src/ &&
mkdir $COCONUT_DATA_DIR/include/ &&
mkdir $COCONUT_DATA_DIR/src/ccnstd/ &&
cp -r CoCoNut/src/core $COCONUT_DATA_DIR/src/ &&
cp -r CoCoNut/include/core $COCONUT_DATA_DIR/include/ &&
cp CoCoNut/coconut.mk $COCONUT_DATA_DIR/Makefile &&
cp CoCoNut/CoCoNut-lib/source/* $COCONUT_DATA_DIR/src/ccnstd/ &&
cp -r CoCoNut/CoCoNut-lib/include/lib $COCONUT_DATA_DIR/include
