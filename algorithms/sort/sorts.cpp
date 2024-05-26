#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

namespace bac {

template<class values>
void ptint(std::vector<values>& v)
{
    std::cout << "{ ";
    for (const auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << "}\n";
}

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
	//Base case
	auto size = std::distance(from, to);
	if (size < 2)
		return;

	//divide et impera (recursive cases)
	auto left_to = std::next(from, size/2);
	auto left_from = from;
	auto right_from = std::prev(to, size/2);

	inner_sort(left_from, left_to);
	inner_sort(right_from, to);

	//Merge both (folding implementation)
	std::vector<typename Iterator::value_type> temp_collection(size);
	auto temp_iter = temp_collection.begin();

	//Compares elements between both chunks and insert lessers into output vector
	while (left_from != left_to || right_from != to)
	{
		if (*left_from < *right_from)
		{
			*temp_iter = std::move(*left_from);
			++left_from;
		} else {
			*temp_iter = std::move(*right_from);
			++right_from;
		}

		++temp_iter;

		if (left_from == left_to)
		{
			std::copy(right_from, to, temp_iter);
			break;
		}

		if (right_from == to)
		{
			std::copy(left_from, left_to, temp_iter);
			break;
		}
	}

	//fill original vector with sorted elements from temporary collection
	std::copy(temp_collection.begin(), temp_collection.end(), from);

}

template<class values>
void sort_by_merge(std::vector<values>& collection)
{
	inner_sort(collection.begin(), collection.end());
}



} // namespace bac
