#include <iostream>
#include "test.h"

#define DEBUG_MODE

void knapsack_solve_test()
{
	std::cout << "knapsack_solve is testing..." << std::endl << std::endl;

	const uint32_t capacity = 6;

	std::vector<std::pair<uint32_t, uint32_t> > items_correct_case = {{2,3},{4,2},{5,5},{3,2},{3,8}};
	std::vector<std::pair<uint32_t, uint32_t> > items_overweight_case = {{9,3},{9,2},{9,5},{9,2},{9,8}};
	std::vector<std::pair<uint32_t, uint32_t> > items_all_included_case = {{1,3},{1,2},{1,5},{1,2},{1,8}};
	std::vector<std::pair<uint32_t, uint32_t> > items_last_included_case = {{9,3},{9,2},{9,5},{9,2},{3,8}};
	std::vector<std::pair<uint32_t, uint32_t> > items_first_included_case = {{2,3},{9,2},{9,5},{9,2},{9,8}};
	std::vector<std::pair<uint32_t, uint32_t> > items_empty_case = {};
	std::vector<std::pair<uint32_t, uint32_t> > items_zeroes1_case = {{0,3},{0,2},{0,5},{0,2},{0,8}};
	std::vector<std::pair<uint32_t, uint32_t> > items_zeroes2_case = {{0,0},{0,0},{0,0},{0,0},{0,0}};
	std::vector<std::pair<uint32_t, uint32_t> > items_zeroes3_case = {{2,0},{4,0},{5,0},{3,0},{3,0}};


#ifdef DEBUG_MODE
	std::cout << "\tresult for 6 capacity is:\t" << knapsack_solve(items_correct_case, capacity) << std::endl;
	std::cout << "\tresult for 6 capacity is:\t" << knapsack_solve(items_overweight_case, capacity) << std::endl;
	std::cout << "\tresult for 6 capacity is:\t" << knapsack_solve(items_all_included_case, capacity) << std::endl;
	std::cout << "\tresult for 6 capacity is:\t" << knapsack_solve(items_empty_case, capacity) << std::endl;
	std::cout << "\tresult for 6 capacity is:\t" << knapsack_solve(items_zeroes1_case, capacity) << std::endl;
	std::cout << "\tresult for 6 capacity is:\t" << knapsack_solve(items_zeroes2_case, capacity) << std::endl;
	std::cout << "\tresult for 6 capacity is:\t" << knapsack_solve(items_zeroes3_case, capacity) << std::endl;
	std::cout << "\tresult for 6 capacity is:\t" << knapsack_solve(items_last_included_case, capacity) << std::endl;
	std::cout << "\tresult for 6 capacity is:\t" << knapsack_solve(items_first_included_case, capacity) << std::endl;


	std::cout << "\tresult for 0 capacity is:\t" << knapsack_solve(items_correct_case, 0) << std::endl;
	std::cout << "\tresult for 0 capacity is:\t" << knapsack_solve(items_overweight_case, 0) << std::endl;
	std::cout << "\tresult for 0 capacity is:\t" << knapsack_solve(items_all_included_case, 0) << std::endl;
	std::cout << "\tresult for 0 capacity is:\t" << knapsack_solve(items_empty_case, 0) << std::endl;
	std::cout << "\tresult for 0 capacity is:\t" << knapsack_solve(items_zeroes1_case, 0) << std::endl;
	std::cout << "\tresult for 0 capacity is:\t" << knapsack_solve(items_zeroes2_case, 0) << std::endl;
	std::cout << "\tresult for 0 capacity is:\t" << knapsack_solve(items_zeroes3_case, 0) << std::endl;
	std::cout << "\tresult for 0 capacity is:\t" << knapsack_solve(items_last_included_case, 0) << std::endl;
	std::cout << "\tresult for 0 capacity is:\t" << knapsack_solve(items_first_included_case, 0) << std::endl;
#else
	//FIXME
#endif
}


void levenshtein_distance_test()
{
	std::cout << "levenshtein_distance is testing..." << std::endl << std::endl;

#ifdef DEBUG_MODE
	std::cout << levenshtein_distance("", "") << '\n';
	std::cout << levenshtein_distance("ABCD", "ABCD") << '\n';
	std::cout << levenshtein_distance("ABCD", "AXCD") << '\n';
	std::cout << levenshtein_distance("ABCD", "XXCD") << '\n';
	std::cout << levenshtein_distance("ABCD", "XXXD") << '\n';
	std::cout << levenshtein_distance("ABCD", "XXXX") << '\n';
	std::cout << levenshtein_distance("ABCD", "XCD") << '\n';
	std::cout << levenshtein_distance("ABCD", "CD") << '\n';
	std::cout << levenshtein_distance("ABCD", "D") << '\n';
	std::cout << levenshtein_distance("ABCD", "DCBA") << '\n';
	std::cout << levenshtein_distance("ABCD", "CBAD") << '\n';
	std::cout << levenshtein_distance("ABCD", "BACD") << '\n';
	std::cout << levenshtein_distance("ABCD", "DBCD") << '\n';
	std::cout << levenshtein_distance("ABCD", "DCBX") << '\n';
	std::cout << levenshtein_distance("ABCD", "CBXX") << '\n';
	std::cout << levenshtein_distance("ABCD", "BXXX") << '\n';

	//Wiki's examples
	std::cout << levenshtein_distance("kitten", "sitten") << '\n'; // 1
	std::cout << levenshtein_distance("sitten", "sittin") << '\n'; // 1
	std::cout << levenshtein_distance("sittin", "sitting") << '\n';// 1
	std::cout << levenshtein_distance("kitten", "sitting") << '\n';// 3
#else
	//FIXME
#endif
}

int main()
{

	//FIXME
	std::cout << chess_king_rec(10,15) << '\n';
	std::cout << chess_king_dyn(10,15) << std::endl << std::endl;

	//knapsack_solve_test();

	levenshtein_distance_test();

    return 0;
}
