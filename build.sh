#!/bin/bash
build() {
  mkdir -p build
  cd build/
  
  g++ -c ../src/*.cpp
  g++ -c ../$1.cpp
  g++ -o $1.exe *.o
  
  ./$1.exe
  
  rm -rf ./*.o
  mv $1.exe $1.exe.old
}

build $1
