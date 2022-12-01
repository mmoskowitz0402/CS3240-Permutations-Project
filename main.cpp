#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <list>
#include "permuteString.h"
#include "getBinaryNum.h"
#include "combinateString.h"

using namespace std;

int main() {
	
	// variable declaration
	string str, strToPermute, line1, line2;
	int nPerm, strSize, arraySize;
	queue<string> anagrams;

	// clear text file
	ofstream file;
	file.open("Permutations_List.txt", std::ofstream::out | std::ofstream::trunc);
	file.close();

	file.open("Combinations_List.txt", std::ofstream::out | std::ofstream::trunc);
	file.close();
	
	// getting a string
	cout << "Input string to find it's anagrams: ";
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}

	strSize = str.length();

	// handling the combinations
	int numBinNums = pow(2, strSize);
	numBinNums--;
	queue<string> binaryQ = getBinaryNum(numBinNums);
	combinateString(str, binaryQ);
	
	// setting up file for read
	ifstream combfile("Combinations_List.txt");

	// reading line by line and permuting
	for (string line; getline(combfile, line);) {
		nPerm = line.size();
		permuteString(line, 0, nPerm - 1);
	}

	combfile.close();
	
	
	ifstream oxfordfile;
	oxfordfile.open("The_Oxford_3000.txt");
	int charbug = 0;

	while (!oxfordfile.eof()) {
		getline(oxfordfile, line1);

		if (charbug == 0) {
			charbug++;
			continue;
		}
		
		ifstream permfile;
		permfile.open("Permutations_List.txt");

		while (!permfile.eof()) {
			getline(permfile, line2);
			if (line1 == line2) {
				anagrams.push(line1);
			}
		}
		
		permfile.close();
	}

	cout << endl;
	cout << "The following anagrams were found:" << endl;

	while (!anagrams.empty()) {
		cout << anagrams.front() << endl;
		anagrams.pop();
	}

	return 0;
}

