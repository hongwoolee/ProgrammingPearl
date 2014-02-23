#include <iostream>
#include <vector>


void printVector(std::vector<int>& vec)
{
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

void leftRotate(std::vector<int>& vec, int d)
{
	int i, j, k, temp;
	for(i = 0; i < gcd(d, vec.size()); ++i)
	{
		temp = vec[i];
		j = i;
		while(1)
		{
			k = j+d;
			if(k >= vec.size())
				k = k-vec.size();
			if(k == i)
				break;
			vec[j] = vec[k];
			j = k;
		}
		vec[j] = temp;
	}
}

int main()
{
	std::vector<int> vec;
	for(int i = 1; i != 10; ++i)
		vec.push_back(i);
	leftRotate(vec, 6);
	printVector(vec);
	return 0;
}