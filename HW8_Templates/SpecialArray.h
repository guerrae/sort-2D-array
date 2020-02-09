#pragma once
#ifndef SPECIALARRAY_H
#define SPECIALARRAY_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//template class
template<class T>

//class
class SpecialArray {
private:
	T **arr;
	int numRows;
	int numColum;

public:
	//Declarations
	SpecialArray() {}
	SpecialArray(int rows, int columns);
	~SpecialArray();
	void readFile(ifstream &in);
	T max();
	T min();
	void sort();
	void print();
	void saveToFile();
};

//Definitions
template<class T>
SpecialArray<T>::SpecialArray(int rows, int columns) {
	numRows = rows;
	numColum = columns;
}//Overloaded constructor

template<class T>
SpecialArray<T>::~SpecialArray() { 
	for (int i = 0; i < numRows; i++) {
		delete[]arr[i];
	}
	delete[]arr;
}//destructor deltes 2D dynamic array

template<class T>
void SpecialArray<T>::readFile(ifstream &in) {
	arr = new T*[numRows];

	for (int i = 0; i < numRows; i++) {
		arr[i] = new T[numColum];
	}

	for (int j = 0; j < numRows; j++) {
		for (int k = 0; k < numColum; k++) {
			in >> arr[j][k];
		}
	}
}//set up 2D dynamic array then store input from file

template<class T>
T SpecialArray<T>::max() {
	T temp = arr[0][0];
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numColum; j++) {
			if (arr[i][j] > temp) {
				temp = arr[i][j];
			}
		}
	}
	return temp;
}//returns largest item in the array

template<class T>
T SpecialArray<T>::min() {
	T temp = arr[0][0];
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numColum; j++) {
			if (arr[i][j] < temp) {
				temp = arr[i][j];
			}
		}
	}
	return temp;
}//returns smallest item in the array

template<class T>
void SpecialArray<T>::sort(){
	T temp;
	for (int i = 0; i < numColum - 1; i++) {
		for (int j = 0; j < numRows; j++) {
			for (int k = 0; k < numColum - 1; k++) {
				if (arr[j][k] > arr[j][k+1]) {
					temp = arr[j][k];
					arr[j][k] = arr[j][k + 1];
					arr[j][k + 1] = temp;
				}
			}
		}
	}
}//sorts rows only from smallest to largest

template<class T>
void SpecialArray<T>::print() {
	for (int j = 0; j < numRows; j++) {
		for (int k = 0; k < numColum; k++) {
			cout << arr[j][k] << " ";
		}
		cout << endl;
	}
}//prints to console itmes in the array

template<class T>
void SpecialArray<T>::saveToFile() {
	ofstream outFile;
	outFile.open("output.txt");

	for (int j = 0; j < numRows; j++) {
		for (int k = 0; k < numColum; k++) {
			outFile << arr[j][k] << " ";
		}
		outFile << endl;
	}

	outFile.close();
}//prints to an output file the items in the array

#endif // !SPECIALARRAY_H