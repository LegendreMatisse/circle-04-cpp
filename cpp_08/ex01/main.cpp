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
	int temp = 0;
	
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
	{
		for (std::vector<int>::iterator er = test.begin(); er != test.end(); ++er)
		{
			if (*it > *er && *it != *er)
				temp = *it - *er;
			else if (*it < *er && *it != *er)
				temp = *er - *it;
			/*if (lowestSpan == 0)
				lowestSpan = temp;*/
			if (temp < lowestSpan)
				lowestSpan = temp;
		}
	}
	
	std::cout << lowestSpan << std::endl;
	
	return (0);
}