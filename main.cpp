#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include "permuteString.h"
#include "getBinaryNum.h"
#include "combinateString.h"

using namespace std;

int main() {
	// variable declaration
	string str, strToPermute;
	int nPerm, strSize, arraySize;

	// clear text file
	ofstream file;
	file.open("Permutations_List.txt", std::ofstream::out | std::ofstream::trunc);
	file.close();

	file.open("Combinations_List.txt", std::ofstream::out | std::ofstream::trunc);
	file.close();
	
	// getting a string
	cout << "Input string to permute: ";
	cin >> str;

	strSize = str.length();

	/*
	// handling the permutations
	nPerm = str.size();
	permuteString(str,0,nPerm-1);
	*/
	

	// handling the combinations
	int numBinNums = pow(2, strSize);
	numBinNums--;
	queue<string> binaryQ = getBinaryNum(numBinNums);
	combinateString(str, binaryQ);
	
	// setting up file for read
	ifstream infile("Combinations_List.txt");

	// reading line by line and permuting
	for (string line; getline(infile, line);) {
		nPerm = line.size();
		permuteString(line, 0, nPerm - 1);
	}

	return 0;
}

