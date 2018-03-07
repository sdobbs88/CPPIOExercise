/**
* Class: CSCI2490 C++ Programming
* Instructor: Y. Daniel Liang
* Description: Receives input from a text file by asking the user for a file path. 
* It then takes the output, shifts the bits by 3 and saves the new binary output to file 
* that the user specifies. 
* Due: 10/05/2016
* @author Shaun C. Dobbs
* @version 1.0

* I pledge by honor that I have completed the programming assignment independently.
* I have not copied the code from a student or any source.
* I have not given my code to any student.

Sign here: Shaun C. Dobbs
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
//C:\\Users\\Shaun\\Documents\\School\\Fall 2016\\C++(2490)\\test.txt
//C:\\Users\\Shaun\\Documents\\School\\Fall 2016\\C++(2490)\\newFile.txt

using namespace std;


int main()
{
	string inputPath, outputPath;

	cout << "Enter the path for the file which you would like to have encrypted: " << endl;
	getline(cin, inputPath);
	cout << "Enter the path for the file which you would like the data stored in: " << endl;
	getline(cin, outputPath);

	fstream input(inputPath, ios::in | ios::binary);
	fstream print(outputPath, ios::out | ios::binary);

	char data;

	while (input >> data) {
		unsigned* p2 = reinterpret_cast<unsigned*>(data);

		p2 += 3;

		print.write(reinterpret_cast<char*>(&p2), sizeof(p2));

	}
	input.close();
	print.close();

	return 0;
	
}

