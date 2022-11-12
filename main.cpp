#include <iostream>
#include <string>
#include <fstream>
#include "permuteString.h"

using namespace std;

int main() {
	string str, strToPermute;
	int nPerm;
	cout << "Please input string to evaluate anagrams that are words in the Oxford 3000: ";
	cin >> str;
	for (int i = 0; i <= str.length(); i++){
		strToPermute = str.substr(0,i);
		nPerm = strToPermute.size();
		permuteString(strToPermute,0,nPerm-1);
	}
	return 0;
}
