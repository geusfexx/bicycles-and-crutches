#include <iostream>
#include <sorts.cpp>
#include <vector>
#include <chrono>
#include <ctime>

using namespace bac;

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

int main()
{

    std::cout << "test 1\n";
    {
        std::vector<int> a = fill_vector_progressive<int>(10000);
        std::vector<int> b = fill_vector_regressive<int>(10000);
        std::vector<int> c = fill_vector_random<int>(10000);

        auto start = std::chrono::system_clock::now();
        bac::sort_by_selection(a);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end-start;

        //bac::ptint(a);
        std::cout << "\n";
        std::cout << "time left: " << diff.count()*1000 << "ms";
        std::cout << "\n";

        start = std::chrono::system_clock::now();
        bac::sort_by_selection(b);
        end = std::chrono::system_clock::now();
        diff = end-start;

        //bac::ptint(b);
        std::cout << "\n";
        std::cout << "time left: " << diff.count()*1000 << "ms";
        std::cout << "\n";

        start = std::chrono::system_clock::now();
        bac::sort_by_selection(c);
        end = std::chrono::system_clock::now();
        diff = end-start;

        //bac::ptint(c);
        std::cout << "\n";
        std::cout << "time left: " << diff.count()*1000 << "ms";
        std::cout << "\n";
    }
    std::cout << "test 2\n";
    {
        std::vector<int> a = fill_vector_progressive<int>(10000);
        std::vector<int> b = fill_vector_regressive<int>(10000);
        std::vector<int> c = fill_vector_random<int>(10000);

        auto start = std::chrono::system_clock::now();
        bac::sort_by_insertion(a);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end-start;

        //bac::ptint(a);
        std::cout << "\n";
        std::cout << "time left: " << diff.count()*1000 << "ms";
        std::cout << "\n";

        start = std::chrono::system_clock::now();
        bac::sort_by_insertion(b);
        end = std::chrono::system_clock::now();
        diff = end-start;

        //bac::ptint(b);
        std::cout << "\n";
        std::cout << "time left: " << diff.count()*1000 << "ms";
        std::cout << "\n";

        start = std::chrono::system_clock::now();
        bac::sort_by_insertion(c);
        end = std::chrono::system_clock::now();
        diff = end-start;

        //bac::ptint(c);
        std::cout << "\n";
        std::cout << "time left: " << diff.count()*1000 << "ms";
        std::cout << "\n";
    }

    std::cout << "test 3\n";
    {
        std::vector<int> a = fill_vector_progressive<int>(10000);
        std::vector<int> b = fill_vector_regressive<int>(10000);
        std::vector<int> c = fill_vector_random<int>(10000);

        auto start = std::chrono::system_clock::now();
        bac::sort_bubble(a);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end-start;

        //bac::ptint(a);
        std::cout << "\n";
        std::cout << "time left: " << diff.count()*1000 << "ms";
        std::cout << "\n";

        start = std::chrono::system_clock::now();
        bac::sort_bubble(b);
        end = std::chrono::system_clock::now();
        diff = end-start;

        //bac::ptint(b);
        std::cout << "\n";
        std::cout << "time left: " << diff.count()*1000 << "ms";
        std::cout << "\n";

        start = std::chrono::system_clock::now();
        bac::sort_bubble(c);
        end = std::chrono::system_clock::now();
        diff = end-start;

        //bac::ptint(c);
        std::cout << "\n";
        std::cout << "time left: " << diff.count()*1000 << "ms";
        std::cout << "\n";
    }
    return 0;
}
