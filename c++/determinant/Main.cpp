﻿#include <iostream>
#include <iomanip>
#include <fstream>

#include "Matrix.h"

using namespace std;

Matrix mat;

void printMainMenu();

int main(void) {
	char menu_choice;
	string file_name;
	while (true) { // main program loop
		
		printMainMenu();
		cout << "Wybierz opcje:";
		cin >> menu_choice;
		cout << endl;
		
		switch (menu_choice) {
		case '1':
			cout << "Podaj nazwe pliku tekstowego: ";
			cin >> file_name;
			mat = Matrix::readFromFile(file_name);
			if(mat.size()==0){
				cout << endl << "Blad odczytu z pliku" << endl;
			}
			break;
		case '2':
			int size;
			cout << "Podaj rozmiar generowanej macierzy: ";
			cin >> size;
			mat = Matrix::randomMatrix(size);
			if(mat.size()==0){
				cout << endl << "Blad odczytu z pliku" << endl;
			}
			break;
		case '3':
			cout << "Wyznacznik macierzy: " << Matrix::calculateDeterminant(mat) << endl;
			break;
		case '4':
			cout << "Rozmiar macierzy: " << mat.size() << endl;
			for (size_t i = 0; i < mat.size(); i++) {
				for (size_t j = 0; j < mat.size(); j++)	{
					cout << setw(4) << mat[i][j];
				}
				cout << endl;
			}			
			break;
		case '5':
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "Niepoprawny wybor";
		}
		cout << endl << endl;
	}
	return 0;
}

void printMainMenu() {
	cout << "Menu glowne:" << endl <<
		'\t' << "1 - Wczytaj macierz z pliku" << endl <<
		'\t' << "2 - Generuj losowa macierz" << endl <<
		'\t' << "3 - Oblicz wyznacznik" << endl <<
		'\t' << "4 - Wyswietl macierz" << endl <<
		'\t' << "5 - Wyjscie" << endl;
}
