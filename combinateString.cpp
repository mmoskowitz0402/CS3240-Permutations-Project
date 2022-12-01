#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>

using namespace std;


// Uses a binary mapping to generate all possible combinations without repeats.
// 
// Example: combinateString(ABC) =
// Use each binary digit between 1 & 2^(a.length()) as a mapping of all possible combinations of every length
// Ignore 000
// 001 = C
// 010 = B
// 011 = BC
// 100 = A
// 101 = AC
// 110 = AB
// 111 = ABC
//
void combinateString(string a, queue<string> binaryQ) {
	// make all objects in queue length a.length()
	queue<string> formatBinaryQ;
	
	while (!binaryQ.empty()) {
		string element = binaryQ.front();
		if (element.length() < a.length())
		{
			int digToAdd = a.length() - element.length();
			string elementFixed = "";
			while (digToAdd > 0)
			{
				elementFixed.append("0");
				digToAdd--;
			}
			elementFixed.append(element);
			formatBinaryQ.push(elementFixed);
		}
		else
		{
			formatBinaryQ.push(element);
		}
		binaryQ.pop();
	}

	ofstream file;
	file.open("Combinations_List.txt", std::ios_base::app);
	

	while (!formatBinaryQ.empty()) {
		string queueVal = formatBinaryQ.front();
		
		formatBinaryQ.pop();

		for (int i = 0; i < queueVal.length(); i++) {
			if (queueVal[i] == '0') {
				continue;
			}
			else {
				file << a[i];
			}
		}
		file << endl;
	}
}