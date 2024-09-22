#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::vector<int> test;

	test.push_back(6);
	test.push_back(3);
	test.push_back(17);
	test.push_back(9);
	test.push_back(11);
	
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	
	return (0);
}