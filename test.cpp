#include <iostream>
#include "include/Matrix.h"
#include "include/CMatrix.h"

using namespace std;

int main() {
  system("clear");

  char * temp1[4][4] = {
    {"he", "llo", "wo", "rld"},
    {"he", "llo", "wo", "rld"},
    {"he", "llo", "wo", "rld"},
    {"he", "llo", "wo", "rld"},
  };

  float temp[4][4] = {
    {2, 3, 4, 6},
    {1, 1, 1, 1},
    {8, 8, 8, 8},
    {55, 55, 55, 55}
  };


  Matrix<char *> test1(*temp1, 4, 4);
  Matrix<char *> test2;
  Matrix<float> test3(*temp, 4, 4);
  Matrix<int> test4;
  Matrix<float> test5;

  cout << "char * - конструктор копирования" << endl;
  cout << test1 << endl;
  cout << "char * - конструктор по умолчанию" << endl;
  cout << test2 << endl;
  cout << "float - конструктор копирования" << endl;
  cout << test3 << endl;
  cout << "int - конструктор по умолчанию" << endl;
  cout << test4 << endl;
  cout << "float - конструктор по умолчанию" << endl;
  cout << test5 << endl;

  test3 = test5;
  test1 = test2;

  cout << "float - оператор присваивания" << endl;
  cout << test3 << endl;
  cout << "char * - оператор присваивания" << endl;
  cout << test1 << endl;

  test1.setElement(0, 0, "PGUPS");
  cout << test1.getElement(0, 0) << endl;
  cout << test1;

  return 0;
}