#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::vector<int> test;

	test.pushback(6);
	test.pushback(3);
	test.pushback(17);
	test.pushback(9);
	test.pushback(11);
	
	for (std::vector<int>::const_iterator it = test.begin(); it != test.end; ++it)
	{
		std::cout << it << std::endl;
	}
	
	return (0);
}