#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
namespace bac {

template<class values>
void ptint(std::vector<values>& v)
{
    std::cout << "{ ";
    for (const auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << "}";
}

//complexity f = O(n^2)
template<class values>
void sort_by_selection(std::vector<values>& collection)
{
    for (int i(0), min(0); i < collection.size() - 1; ++i)      //sorted part
    {
        min = i;
        for (int j(i + 1); j < collection.size(); ++j) {        //unsorted part
            if (collection[min] > collection[j]) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(collection[i], collection[min]);
        }
    }
}

//complexity f = O(n^2)
// f = O(n) easy case
template<class values>
void sort_by_insertion(std::vector<values>& collection)
{
    for (int i(1), inserted_value(0), inserted_index(0); i < collection.size(); ++i)                            //unsorted part
    {
        inserted_value = collection[i];
        inserted_index = i;
        while ( inserted_index > 0 && collection[inserted_index - 1] > inserted_value  ) {          //sorted part
            collection[inserted_index] =  collection[inserted_index - 1];
            inserted_index--;
        }
        collection[inserted_index] = inserted_value;

    }
}

//complexity f = O(n^2)
template<class values>
void sort_bubble(std::vector<values>& collection)
{
    for (int i(0); i < collection.size() - 1; ++i)      //unsorted part
    {
        for (int j(0); j < collection.size() - i - 1; ++j) {        //sorted part
            if (collection[j] > collection[j + 1]) {
                std::swap(collection[j], collection[j + 1]);
            }
        }
    }
}

}
