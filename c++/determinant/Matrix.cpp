#include <fstream>
#include "Matrix.h"

Matrix::Matrix() {
	this->matrix = nullptr;
	this->_size = 0;
}

Matrix::Matrix(const Matrix &m) {
	_size = m._size;
	matrix = new int*[_size];
	for (int i = 0; i < _size; i++) {
		matrix[i] = new int[_size];
		for (int j = 0; j < _size; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
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

int Matrix::calculateDeterminant(){
	return 0;
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

int Matrix::size() {
	return _size;
}
