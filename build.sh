build() {
  mkdir -p build
  cd build/
  
  [ -f ../src/*.cpp ] && g++ -c ../src/*.cpp
  [ -f ../$1.cpp ]    && g++ -c ../$1.cpp
  [ -f *.o ]          && g++ -o $1.exe *.o
  [ -f ./$1.exe ]     && { ./$1.exe; mv $1.exe $1.exe.old; }
  
  rm -rf ./*.o
}

build $1