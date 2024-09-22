#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(void)
{
	std::vector<int> test;

	test.push_back(6);
	test.push_back(3);
	test.push_back(17);
	test.push_back(9);
	test.push_back(11);

	int lowestSpan = 0;
	int highestSpan = 0;
	int temp = 0;
	
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
	{
		for (std::vector<int>::iterator er = test.begin(); er != test.end(); ++er)
		{
			if (*it > *er && *it != *er)
				temp = *it - *er;
			else if (*it < *er && *it != *er)
				temp = *er - *it;
			if (lowestSpan == 0 && highestSpan == 0)
				lowestSpan = temp;
			if (temp < lowestSpan)
				lowestSpan = temp;
			if (temp > highestSpan)
				highestSpan = temp;
		}
	}
	
	std::cout << lowestSpan << std::endl;
	std::cout << highestSpan << std::endl;

	std::sort(test.begin(), test.end());

	std::vector<int> differences(test.size());

	std::adjacent_difference(test.begin(), test.end(), differences.begin());

	for (size_t i = 1; i < differences.size(); ++i) {
		if (differences[i] < lowestSpan && differences[i] > 0) {
			lowestSpan = differences[i];
		}
	}

	std::cout << lowestSpan << std::endl;
	
	return (0);
}