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
        std::cout << "Size is " << list.size() << std::endl;
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
        std::cout << "Size is " << list.size() << std::endl;
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
        }
        std::cout << "Size is " << list.size() << std::endl;
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
        std::cout << "Size is " << list.size() << std::endl;
        list.push_front(99);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 5" << std::endl;
    {
        singly_linked_list<int> list;
        std::cout << "Size is " << list.size() << std::endl;
        list.push_front(99);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }
    std::cout << "Test 6" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
        list.clear();
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 7" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
        list.insert(99, 2);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 8" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
        try {
            list.insert(99, -1);
        } catch (std::invalid_argument ex) {
            std::cout << ex.what() << std::endl;
        }
        std::cout << "Size after insert(99, -1) is " << list.size() << std::endl;
    }

    std::cout << "Test 9" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
        try {
            list.insert(99, 0);
        } catch (std::out_of_range ex) {
            std::cout << ex.what() << std::endl;
        }
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size after insert(99, 0) is " << list.size() << std::endl;
    }

    std::cout << "Test 10" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
        list.insert(99, 5);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 11" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(-99);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
        list.pop_back();
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 12" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
        list.pop_back();
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 13" << std::endl;
    {
        singly_linked_list<int> list;
        std::cout << "Size is " << list.size() << std::endl;
        try {
            list.pop_back();
        } catch (std::out_of_range ex) {
            std::cout << ex.what() << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 14" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(99);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
        list.pop_front();
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 15" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
        list.pop_front();
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 16" << std::endl;
    {
        singly_linked_list<int> list;
        std::cout << "Size is " << list.size() << std::endl;

        list.pop_front();

        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 17" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;

        list.resize(5);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 18" << std::endl;
    {
        singly_linked_list<int> list;
        std::cout << "Size is " << list.size() << std::endl;

        list.resize(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 19" << std::endl;
    {
        singly_linked_list<int> list;
        std::cout << "Size is " << list.size() << std::endl;

        list.resize(0);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 20" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        std::cout << "Size is " << list.size() << std::endl;

        list.resize(0);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 21" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;

        list.resize(2);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 22" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;

        list.resize(2, 5);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 23" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;

        list.resize(3, 5);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 24" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;

        list.resize(0, 5);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 25" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;

        try {
            list.resize(-5, 5);
        } catch (std::invalid_argument ex) {
            std::cout << ex.what() << std::endl;
        }

        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 26" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;

        list.resize(5, 5);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 27" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;

        list.remove_at(0);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 28" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
        try {
            list.remove_at(-1);
        } catch (std::invalid_argument ex) {
            std::cout << ex.what() << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 29" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;

        list.remove_at(1);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 30" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;

        list.remove_at(2);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }

    std::cout << "Test 31" << std::endl;
    {
        singly_linked_list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
        try {
            list.remove_at(5);
        } catch (std::out_of_range ex) {
            std::cout << ex.what() << std::endl;
        }
        for (size_t i(0); i < list.size();++i) {
            std::cout << list[i] << std::endl;
        }
        std::cout << "Size is " << list.size() << std::endl;
    }
}
