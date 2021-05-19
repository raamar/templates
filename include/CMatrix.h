#pragma once
#include "Matrix.h"

template <> 
class Matrix <char *> {
  private:
    char ***matrix;
    void create();
    bool outOfBoundsCheck(int, int);
    int size_x, size_y;
  public: 
    Matrix();
    Matrix(char **, int, int);
    Matrix(const Matrix &);
    ~Matrix();
    char * getElement(int, int);
    char * setElement(int, int, char *);
    Matrix<char *> & operator = (const Matrix<char *> &);
    friend std::ostream & operator<< (std::ostream &, const Matrix<char *> &);
};

Matrix <char *>::Matrix()
:size_x(ROW), size_y(COL) {
  create();
}

Matrix <char *>::Matrix(char ** source, int _x, int _y) 
:size_x(_x), size_y(_y) {
  create();
  for(int i = 0; i < size_x; i++)
    for(int j = 0; j < size_y; j++)
      matrix[i][j] = *((source + i * size_y) + j);
}

Matrix<char *>::Matrix(const Matrix<char *> & N)
:size_x(N.size_x), size_y(N.size_y) {
  create();
  for (int i = 0; i < size_x; i++)
    for (int j = 0; j < size_y; j++)
      matrix[i][j] = N.matrix[i][j];
}

void Matrix <char *>::create() {
  matrix = new char **[size_x];
  for (int i = 0; i < size_x; i++) {
    matrix[i] = new char *[size_y];
    for (int j = 0; j < size_y; j++) {
      matrix[i][j] = "Hello";
    }
  }
}

Matrix <char *>::~Matrix() {
  for (int i = 0; i < size_x; i++) 
    delete []matrix[i];

  delete []matrix;
}

char * Matrix <char *>::getElement(int i, int j) { 
  if (outOfBoundsCheck(i, j)) return 0;
  return matrix[i][j]; 
}

char * Matrix <char *>::setElement(int i, int j, char * value) {
  if (outOfBoundsCheck(i, j)) return 0;
  return matrix[i][j] = value;
}

Matrix <char *> & Matrix <char *>::operator = (const Matrix<char *> & right) {

  for (int i = 0; i < size_x; i++)
    for (int j = 0; j < size_y; j++)
      this->matrix[i][j] = right.matrix[i][j];

  return *this;
}

std::ostream & operator<< (std::ostream &out, const Matrix<char *> &M) {
  for(int i = 0; i < M.size_x; i++) {
    for (int j = 0; j < M.size_y; j++) {
      out << M.matrix[i][j];
      out << "\t";
    }

    out << std::endl;
  }

  return out;
}

bool Matrix <char *>::outOfBoundsCheck(int i, int j) {
  if(i > size_x - 1 || j > size_y - 1 || j < 0 || i < 0) {
    std::cout << "Ошибка! Индексы за пределами матрицы! \n";
    return true;
  }
  return false;
}