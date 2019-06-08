#include <fstream>
#include <time.h>
#include "Matrix.h"

#define REFERENCE_ROW 0

Matrix::Matrix() {
	this->matrix = nullptr;
	this->_size = 0;
}

Matrix::Matrix(const Matrix &m) {
	_size = m._size;
	this->matrix = new int*[_size];
	for (int i = 0; i < _size; i++) {
		matrix[i] = new int[_size];
		for (int j = 0; j < _size; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
}

Matrix& Matrix::operator=(const Matrix &m){
	_size = m._size;
	matrix = new int*[_size];
	for (int i = 0; i < _size; i++) {
		matrix[i] = new int[_size];
		for (int j = 0; j < _size; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
	return *this;
}

Matrix::Matrix(int s) {
	initializeMatrix(s);
}

Matrix::~Matrix(){
	clearMatrix();
}

void Matrix::initializeMatrix(int s) {
	clearMatrix();
	_size = s;
	matrix = new int*[_size];
	for (int i = 0; i < _size; i++) {
		matrix[i] = new int[_size];
	}

	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			matrix[i][j] = 0;
		}
	}
}

void Matrix::clearMatrix() {
	if (matrix != nullptr) {
		for (int i = 0; i < _size; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = nullptr;
	}
}

Matrix Matrix::readFromFile(std::string file_name){
	Matrix matrix;
	std::fstream fs;
	fs.open(file_name, std::fstream::in);

	if(fs.is_open()){
		int size;
		fs >> size;
		matrix.initializeMatrix(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				fs >> matrix[i][j];
			}
		}
	}

	fs.close();
	return matrix;
}

Matrix Matrix::randomMatrix(int size){
	Matrix matrix;
	srand( time( NULL ) );

	matrix.initializeMatrix(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = rand() % 100;
		}
	}

	return matrix;
}

int Matrix::size() {
	return _size;
}

Matrix getMinor(Matrix m, int row, int col){
	Matrix result;
	result.initializeMatrix(m.size()-1);
	int i_parent = 0, j_parent = 0;
	for (size_t i = 0; i < result.size(); i++, i_parent++) {
		if(i_parent==row) 
			i_parent++;
		j_parent = 0;
		for (size_t j = 0; j < result.size(); j++, j_parent++) {
			if(j_parent==col) 
				j_parent++;
			result[i][j] = m[i_parent][j_parent];
		}
	}
	return result;
}

//recursive implementation of determinant calculator
//based on Laplace expansion
int Matrix::calculateDeterminant(Matrix m){
	int det = 0;
	if(m.size()==0) {
		det = 0;
	}
	else if(m.size()==1) {
		det = m[0][0];
	}
	else {
		for (size_t i = 0; i < m.size(); i++) {
			int sign = (i+REFERENCE_ROW)%2==0 ? 1 : -1;
			Matrix minor = getMinor(m, REFERENCE_ROW, i);
			det += sign*m[REFERENCE_ROW][i]*calculateDeterminant(minor);
		}
	}
	return det;
}
