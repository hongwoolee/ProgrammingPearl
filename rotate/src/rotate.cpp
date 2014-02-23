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

int main()
{
	std::vector<int> vec;

	for(int i=0; i<10; ++i)
	{
		vec.push_back(i+1);
	}
	printVector(vec);

	for(int i=0; i<2; ++i)
	{
		int temp = vec[0];
		vec.erase(vec.begin());
		vec.push_back(temp);
	}
	printVector(vec);

	return 0;
}