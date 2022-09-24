#include "matrix.h"

Matrix::Matrix(int rows, int cols)
{
    try {
        if(rows < 1){
            throw (QString("Пчел ты еблан"));
        }
        if(cols < 1){
            throw (QString("Второй раз"));
        }
    } catch (QString hui) {
        qDebug() << "\nNot correct rows|cols :: " << hui << "\n";
    }

    this->rows = rows;
    this->cols = cols;
    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }
}
Matrix::Matrix(const Matrix &copy){
    this->rows = copy.rows;
    this->cols = copy.cols;
    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = copy.matrix[i][j];
        }
    }
}
int* Matrix::operator[](int i){
    return matrix[i];
}
Matrix Matrix::operator=(const Matrix &second){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = second.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &second){
    if(rows != second.rows || cols != second.cols){
        std::cout << "\nNot equal rows|cols matrix\n";
        exit(0);
    }
    Matrix answer(rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            answer[i][j] =  this->matrix[i][j] + second.matrix[i][j];
        }
    }
    return answer;
}
Matrix Matrix::operator-(const Matrix &second){
    if(rows != second.rows || cols != second.cols){
        std::cout << "\nNot equal rows|cols matrix\n";
        exit(0);
    }
    Matrix answer(rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            answer[i][j] =  this->matrix[i][j] - second.matrix[i][j];
        }
    }
    return answer;
}

Matrix Matrix::operator*(const Matrix &second){
    if(rows != second.rows || cols != second.cols){
        std::cout << "\nNot equal rows|cols matrix\n";
        exit(0);
    }
    Matrix answer(rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            answer[i][j] = 0;
            for(int l = 0; l < rows; l++){
                answer[i][j] += matrix[i][l] * second.matrix[l][j];
            }
        }
    }
    return answer;
}

bool Matrix::operator==(const Matrix &second){
    if(second.cols != cols || second.rows != rows){
        return false;
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(second.matrix[i][j]!=matrix[i][j]){
                return false;
            }
        }
    }
    return true;
}

int Matrix::getMin(){
    int min_element = matrix[0][0];
    for(int i = 0; i < rows; i++){
        for(int j = 1; j < cols; j++){
            if(min_element > matrix[i][j]){
                min_element = matrix[i][j];
            }
        }
    }
    return min_element;
}

QString Matrix::toString(){
    QString matrix_line;
    QString matrix_to_string = "{";
    for(int i = 0; i < rows; i++){
        matrix_line = "{";
        for(int j = 0; j < cols; j++){
            matrix_line += QString::number(matrix[i][j]);
            if(j != cols-1){
                matrix_line += " ,";
            }
        }
        matrix_line += "}";
        matrix_to_string += matrix_line;
        if(i != rows - 1){
            matrix_to_string += " ,";
        }
    }
    matrix_to_string += "}";
    return matrix_to_string;
}

Matrix Matrix::transp(){
    if(rows != cols){
        std::cout << "\nNot equal rows|cols matrix\n";
        exit(0);
    }
    Matrix matrix_transp(rows,cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix_transp[i][j] = matrix[j][i];
        }
    }
    return matrix_transp;
}

int Matrix::getRows(){
    return rows;;
}
int Matrix::getCols(){
    return cols;
}
void Matrix::printmat(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            std::cout << matrix[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}
Matrix::~Matrix(){
    for (int i = 0; i < rows; ++i)
        delete [] matrix[i];
    delete [] matrix;
}

