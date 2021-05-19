#pragma once
#include <iostream>
#define ROW 5
#define COL 5

template <class MType = int> 
class Matrix {
  private:
    MType **matrix;
    void create();
    bool outOfBoundsCheck(int, int);
    int size_x, size_y;
  public: 
    Matrix();
    Matrix(MType *, int, int);
    Matrix(const Matrix &);
    ~Matrix();
    MType getElement(int, int);
    MType setElement(int, int, MType);
    Matrix<MType> & operator = (const Matrix<MType> &);
    template<class MType2> 
    friend std::ostream & operator<< (std::ostream &, const Matrix<MType2> &);
};

template <class MType>
Matrix <MType>::Matrix()
:size_x(ROW), size_y(COL) {
  create();
}

template <class MType> 
Matrix <MType>::Matrix(MType * source, int _x, int _y) 
:size_x(_x), size_y(_y) {
  create();
  for(int i = 0; i < size_x; i++)
    for(int j = 0; j < size_y; j++)
      matrix[i][j] = *((source + i * size_y) + j);
}

template <class MType>
Matrix<MType>::Matrix(const Matrix<MType> & N)
:size_x(N.size_x), size_y(N.size_y) {
  create();
  for (int i = 0; i < size_x; i++)
    for (int j = 0; j < size_y; j++)
      matrix[i][j] = N.matrix[i][j];
}

template <class MType> 
void Matrix <MType>::create() {
  matrix = new MType*[size_x];
  for (int i = 0; i < size_x; i++) {
    matrix[i] = new MType[size_y];
    for (int j = 0; j < size_y; j++) {
      matrix[i][j] = (MType)(i * size_y + j);
    }
  }
}

template <class MType> 
Matrix <MType>::~Matrix() {
  for (int i = 0; i < size_x; i++) 
    delete []matrix[i];

  delete []matrix;
}

template <class MType> 
MType Matrix <MType>::getElement(int i, int j) { 
  if (outOfBoundsCheck(i, j)) return 0;
  return matrix[i][j]; 
}

template <class MType> 
MType Matrix <MType>::setElement(int i, int j, MType value) {
  if (outOfBoundsCheck(i, j)) return 0;
  return matrix[i][j] = value;
}

template <class MType> 
Matrix <MType> & Matrix <MType>::operator = (const Matrix<MType> & right) {

  for (int i = 0; i < size_x; i++)
    for (int j = 0; j < size_y; j++)
      this->matrix[i][j] = right.matrix[i][j];

  return *this;
}

template <class MType> 
std::ostream & operator<< (std::ostream &out, const Matrix<MType> &M) {
  for(int i = 0; i < M.size_x; i++) {
    for (int j = 0; j < M.size_y; j++) {
      out << M.matrix[i][j];
      out << "\t";
    }

    out << std::endl;
  }

  return out;
}

template <class MType> 
bool Matrix <MType>::outOfBoundsCheck(int i, int j) {
  if(i > size_x - 1 || j > size_y - 1 || j < 0 || i < 0) {
    std::cout << "Ошибка! Индексы за пределами матрицы! \n";
    return true;
  }
  return false;
}