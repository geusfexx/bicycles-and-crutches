#include <iostream>
#include "test.h"


void kmp_test()
{
	std::vector<std::string> patterns = {
								"abacaba",
								"",
								"xx"
	};

	std::vector<std::string> lines = {
								"abcbaccabcaabcaabaabacabacabacababacabcaabadcabaacbacabaaa",
								"",
								"xxxxhasdfbckknbadpaojojanxc",
								"abacaba",
								"abaca"
	};

	for (auto pattern : patterns)
	{
		for (auto line : lines)
		{
			auto result = kmp(pattern, line);
			for (auto i : result)
			{
				std::cout << i << "\t";
			}
			std::cout << std::endl;
		}
	}
}

int main()
{
	kmp_test();

    return 0;
}
