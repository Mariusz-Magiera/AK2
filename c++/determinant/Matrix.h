#pragma once
#include <string>

class Matrix{
private:
	int _size;
	int** matrix;
	void clearMatrix();

public:
	Matrix();
	Matrix(const Matrix &m);
	Matrix(int size);
	~Matrix();

	void initializeMatrix(int size);
	
	int size();
	
	static Matrix readFromFile(std::string file_name);
	static int calculateDeterminant(Matrix m);

	int* operator[](int i) {
		return matrix[i];
	}

	Matrix& operator=(const Matrix &m);
};

