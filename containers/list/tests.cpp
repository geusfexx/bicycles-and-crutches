//There are only some debug tests. It's required to supplement with unit-tests.

#include <singly_linked_list.cpp>
#include <iostream>

using namespace bac;

int main(void)
{
    std::cout << "Test 1" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(3);
        list.push_back(0);
        list.push_back(-11);
        std::cout << list.size() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Test 2" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(3);
        list.push_back(0);
        list.push_back(-11);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl << "\n";
    }
    std::cout << "Test 3" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(3);
        list.push_back(0);
        list.push_back(-11);
        list[2] = 9;
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }        std::cout << std::endl;
        std::cout << std::endl << "\n";
    }
    std::cout << "Test 4" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << list.size() << std::endl << "\n";
        std::cout << std::endl;
        std::cout << std::endl << "\n";
        list.pop_front();
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << list.size() << std::endl;
    }
    std::cout << "Test 5" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << list.size() << std::endl << "\n";
        std::cout << std::endl;
        std::cout << std::endl << "\n";
        list.clear();
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << list.size() << std::endl;
    }
}
