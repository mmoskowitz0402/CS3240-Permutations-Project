#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>

using namespace std;

queue<string> getBinaryNum(int n) {

	queue<string> q;
	queue<string> returnQ;
	q.push("1");

	while (n--)
	{
		string str1 = q.front();
		q.pop();
		returnQ.push(str1);

		string str2 = str1;

		q.push(str1.append("1"));
		q.push(str2.append("0"));
	}

	return returnQ;
}