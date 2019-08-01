#!/bin/bash

COCONUT_DIR=$1
COCONUT_DATA_DIR=$2

make -C $COCONUT_DIR &&
mkdir $COCONUT_DATA_DIR &&
mkdir $COCONUT_DATA_DIR/src/ &&
mkdir $COCONUT_DATA_DIR/include/ &&
mkdir $COCONUT_DATA_DIR/src/ccnstd/ &&
cp -r $COCONUT_DIR/src/core $COCONUT_DATA_DIR/src/ &&
cp -r $COCONUT_DIR/include/core $COCONUT_DATA_DIR/include/ &&
cp $COCONUT_DIR/coconut.mk $COCONUT_DATA_DIR/Makefile &&
cp $COCONUT_DIR/CoCoNut-lib/source/* $COCONUT_DATA_DIR/src/ccnstd/ &&
cp -r $COCONUT_DIR/CoCoNut-lib/include/lib $COCONUT_DATA_DIR/include
