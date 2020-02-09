//Efrain Guerra
//read an input file and store the info in a 2D Dynamic Array
//The input file can contain integers or strings
//finaly sort the 2D Dynamic Array

#include "SpecialArray.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//function counts num of elements in row
int measureElementsPerLine(ifstream& inFile) {
	if (!inFile.is_open()) { throw 10; }//throws if file wont open

	int numOfElements = 1;
	char c;
	while (inFile.get(c)) { 
		if (c == '\n') { break; }
		else if( c == ' '){ numOfElements++; }
	}

	if (numOfElements == 1) { throw 'e'; }//thows if file is empty

	//cout << "number of elements " << numOfElements << endl;//testing numOfElements
	return numOfElements;
}

//function counts num of lines in file
int measureLines(ifstream& inFile) {
	int numOfLines = 1;
	char c;
	while (inFile.get(c)) {
		if (c == '\n') { numOfLines++; }
	}

	//cout << "number of lines " << numOfLines << endl;//testing numOfLines
	return numOfLines;
}

int main()
{
	int numOfLines, numOfElements;
	string fileName, dataType;
	cout << "Enter File Name: ";
	cin >> fileName;
	cout << "Enter Data Type: ";
	cin >> dataType;
	ifstream inFile(fileName);

	try {//try block to check for thrown errors
		numOfElements = measureElementsPerLine(inFile);
		inFile.close();
		inFile.open(fileName);
		numOfLines = measureLines(inFile);
		inFile.close();

		if (dataType == "int") {
			SpecialArray<int> specialArray(numOfLines, numOfElements);
			inFile.open(fileName);
			specialArray.readFile(inFile);
			inFile.close();
			specialArray.print();
			specialArray.sort();
			cout << "\nSorted outputs: \n";
			specialArray.print();
		}
		else if (dataType == "string") {
			SpecialArray<string> specialArray(numOfLines, numOfElements);
			inFile.open(fileName);
			specialArray.readFile(inFile);
			inFile.close();
			specialArray.print();
			specialArray.sort();
			cout << "\nSorted outputs: \n";
			specialArray.print();
		}
	}

	//catch statement
	catch (int a) { cout << "File does not exist."; }
	catch (char e) { cout << "File is empty."; }


	//system("pause");
	return 0;
}