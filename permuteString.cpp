#include <string>
#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

// Permutation function uses backtracking and recursion to generate all possible permutations
//
// Example: permuteString(ABC) = 
// l = 0, r = 3
// inside else statement:
// at i = 0, i <= 3, swap a[0] with a[0] (fixes A in the first place of the string)
// recursively calls the permuteString function, using l = 1, r = 3
// inside recursion call, at i = 1, i <= 3, swap a[1] with a[1] (fixes B in the second place of the string, now generating AB)
// recursively calls the permuteString function, using l = 2, r = 3
// inside recusion call, at i = 2, i <= 3, swap a[2] with a[2] (fixes C in the third place of the string, now generating ABC)
// recursively calls the permuteString function, using l = 3, r = 3
// first if statement is satisfied, returning the first permuation of "ABC"
// Back to the recursive call where B is fixed to the second place, B is swapped with C
// recursively calls the permute string function, using l = 3, r = 3
// first if statement is satisfied, reutnring the second permutation of "ACB"
// repeat for all characters, fixing each character to the first spot of the string and recursively iterating through the string.
// 

void permuteString(string a, int l, int r) {

	if (l == r) {
		ofstream file;
		file.open("Permutations_List.txt", std::ios_base::app);
		file << a << endl;
	}
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a[l], a[i]);
			permuteString(a, l+1, r);
			swap(a[l], a[i]);
		}
	}
}
