#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<QStringList>
#include<QDebug>
#include<QString>
class Matrix
{
public:
    Matrix(int rows, int cols);
    Matrix(const Matrix &copy);
    ~Matrix();
    int* operator[](int i);
    Matrix operator+(const Matrix &second);
    Matrix operator-(const Matrix &second);
    Matrix operator/(const Matrix &second);
    Matrix operator*(const Matrix &second);
    Matrix operator=(const Matrix &second);
    bool operator==(const Matrix &second);
public:
    void printmat();
    int getRows();
    int getCols();
    int getMin();
    QString toString();
    Matrix transp();
private:
    int rows = 0;
    int cols = 0;
    int** matrix;
};

#endif // MATRIX_H
