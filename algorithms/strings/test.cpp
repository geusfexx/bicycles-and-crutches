#include <iostream>
#include "test.h"

void kmp_test()
{
	std::vector<std::string> patterns = {
								"abacaba",
								"",
								"xxx"
	};

	std::vector<std::string> lines = {
								"abcbaccabcaabcaabaabacabacabacababacabcaabadcabaacbacabaaa",
								"",
								"xxxxxxxxhasdfbckknbadpaojojanxc",
								"abacabas",
								"abaca"
	};

	for (auto pattern : patterns)
	{
		for (auto line : lines)
		{
			auto result = prefix_func_kmp(pattern, line);
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
	//kmp_test();

	auto result = prefix_func_kmp("aba", "ababacababxs");
	for (auto i : result)
	{
		std::cout << i << "\t";
	}

    return 0;
}
