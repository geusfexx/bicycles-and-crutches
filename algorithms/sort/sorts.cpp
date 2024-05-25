#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

namespace bac {

//complexity f = O(n^2)
template<class values>
void sort_by_selection(std::vector<values>& collection)
{
	if (collection.empty())
		return;

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
	if (collection.empty())
		return;

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
	if (collection.empty())
		return;

    for (int i(0); i < collection.size() - 1; ++i)      //unsorted part
    {
        for (int j(0); j < collection.size() - i - 1; ++j) {        //sorted part
            if (collection[j] > collection[j + 1]) {
                std::swap(collection[j], collection[j + 1]);
            }
        }
    }
}

template <typename Iterator>
void inner_sort(Iterator from, Iterator to)
{
	auto size = std::distance(from, to);
	if (1 > size)
		return;

	auto left_to = std::next(from, size/2);
	auto left_from = from;
	auto right_from = std::prev(to, size/2);
	

	inner_sort(left_from, left_to);
	inner_sort(right_from, to);

}

template<class values>
void sort_by_merge(std::vector<values>& collection)
{
	inner_sort(collection.begin(), collection.end());
}



}
