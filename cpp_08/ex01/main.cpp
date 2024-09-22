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

	int lowestSpan = 0;
	
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
	{
		for (std::vector<int>::iterator er = test.begin(); er != test.end(); ++er)
		{
			if (it > er)
				lowestSpan = it - er;
			else
				lowestSpan = er - it;
			std::cout << lowestSpan << std::endl;
		}
	}
	
	return (0);
}