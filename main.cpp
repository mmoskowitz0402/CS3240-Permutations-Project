#include <iostream>
#include <string>
#include "permuteString.h"

using namespace std;

int main() {
	string str = "ABCD";
	int n = str.size();
	permuteString(str,0,n-1);
	return 0;
}
