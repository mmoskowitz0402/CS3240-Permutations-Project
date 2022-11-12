#include <string>
#include <bits/stdc++.h>

using namespace std;

void permuteString(string a, int l, int r) {
	
	if (l == r)
		cout << a << endl;
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
