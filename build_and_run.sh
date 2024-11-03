#!/bin/bash

make clean
if [ $? -ne 0 ]; then
  echo "make clean failed. Exiting."
  exit 1
fi

make
if [ $? -ne 0 ]; then
  echo "make failed."
  exit 1
fi

./coordinate_systems