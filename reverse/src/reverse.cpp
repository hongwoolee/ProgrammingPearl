#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void reverseVec(vector<int>& vec, int i, int n)
{
	reverse(vec.begin()+i, vec.begin()+n+1);
}

void rotate(vector<int>& vec, int i, int n)
{
	reverseVec(vec, 0, i-1);
	reverseVec(vec, i, n-1);
	reverseVec(vec, 0, n-1);
}

void printVector(vector<int>& vec)
{
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

int main()
{
	vector<int> vec;

	for(int i = 1; i != 1000; ++i) {
		vec.push_back(i);
	}

	printVector(vec);
	rotate(vec, 200, 999);
	printVector(vec);
	
	return 0;
}