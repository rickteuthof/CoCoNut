#!/bin/bash

COCONUT_DIR=`dirname $0`

echo "Give the location you want to place the CoCoNut artifacts. [default = CoCoNut-artifacts]"
read COCONUT_DATA_DIR
if [ -z "$COCONUT_DATA_DIR" ]
then
	COCONUT_DATA_DIR=CoCoNut-artifacts/
fi

make -C $COCONUT_DIR &&
mkdir $COCONUT_DATA_DIR &&
mkdir $COCONUT_DATA_DIR/src/ &&
mkdir $COCONUT_DATA_DIR/include/ &&
mkdir $COCONUT_DATA_DIR/src/ccnstd/ &&
mkdir $COCONUT_DATA_DIR/bin/ &&
cp -r $COCONUT_DIR/src/core $COCONUT_DATA_DIR/src/ &&
cp -r $COCONUT_DIR/include/core $COCONUT_DATA_DIR/include/ &&
cp $COCONUT_DIR/coconut.mk $COCONUT_DATA_DIR/Makefile &&
cp $COCONUT_DIR/CoCoNut-lib/source/* $COCONUT_DATA_DIR/src/ccnstd/ &&
cp -r $COCONUT_DIR/CoCoNut-lib/include/lib $COCONUT_DATA_DIR/include &&
cp $COCONUT_DIR/coconut_flags.mk $COCONUT_DATA_DIR/
