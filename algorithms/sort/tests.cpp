#include <iostream>
#include "sorts.cpp"
#include <vector>
#include <chrono>
#include <ctime>
#include <map>
#include <limits>

using namespace bac;

template<class values>
void ptint(std::vector<values>& v)
{
    std::cout << "{ ";
    for (const auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << "}\n";
}

template<class values>
std::vector<values> fill_vector_progressive(int count)
{
    std::vector<values> res(count);
    values val(0);
    for(auto &i : res) {
        i = val++;
    }
    return res;
}

template<class values>
std::vector<values> fill_vector_regressive(int count)
{
    std::vector<values> res(count);
    values val(count - 1);
    for(auto &i : res) {
        i = val--;
    }
    return res;
}

template<class values>
std::vector<values> fill_vector_random(int count)
{
    std::srand(std::time(nullptr));
    std::vector<values> res(count);
    for(auto &i : res) {
        i = std::rand() % 10;
    }
    return res;
}

template<class values>
void test_templ(void(*func)(std::vector<values>&), const std::string& title);

template<class values>
void test_templ(void(*func)(std::vector<values>&), const std::string& title)  
{
    std::cout << title << " is testing...\n";
	const int array_size = 10000;

	std::vector<values> empty = {};
	std::vector<values> single_element = {1} ;
	auto zeroes = std::vector<values>(array_size, 0);
	auto int_max = std::vector<values>(array_size, std::numeric_limits<int>::max());
	auto best = fill_vector_progressive<values>(array_size);
    auto worst = fill_vector_regressive<values>(array_size);
    auto random = fill_vector_random<values>(array_size);

	auto duration_wrapper = [&func](std::vector<int>& conteiner, const std::string& occasion){
		auto start = std::chrono::system_clock::now();
		func(conteiner);
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = end-start;

		std::cout << "\n\t" << occasion << "\ttime spended: " << diff.count()*1000 << " ms\n";
	};

	duration_wrapper(empty, "empty case");

	duration_wrapper(single_element, "single case");

	duration_wrapper(zeroes, "zeroes case");

	duration_wrapper(int_max, "int_max case");

	duration_wrapper(best, "best case");

    duration_wrapper(worst, "worst case");

    duration_wrapper(random, "random case");

	std::cout << "\n";
}


template<class values>
	std::map<void(*)(std::vector<values>&), const char*> tested_functions{
		{bac::sort_by_selection, "Selection sort"},
		{bac::sort_by_insertion, "Insertion sort"},
		{bac::sort_bubble, "Bubble sort"},
		{bac::sort_by_merge, "Merge sort"}

	};

int main()
{

	for (const auto i : tested_functions<int>)
	{
		test_templ<int>(i.first, i.second);
	}

    return 0;
}
