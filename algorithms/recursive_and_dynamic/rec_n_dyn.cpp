#include "rec_n_dyn.h"

//finds paths amount from 1, 1 to pos_x, pos_y coordinates
//chess_king can move right and down only
uint64_t chess_king_rec(uint64_t pos_x, uint64_t pos_y)
{
	//Base Case
	if (pos_x == 1 || pos_y == 1) {
		return 1;
	}

	return chess_king_rec(pos_x, pos_y -1) + chess_king_rec(pos_x -1, pos_y);
}

//finds paths amount from 1, 1 to pos_x, pos_y coordinates
//chess_king can move right and down only
uint64_t chess_king_dyn(uint64_t pos_x, uint64_t pos_y)
{

	std::vector<std::vector<uint64_t> > ways(pos_y + 1, (std::vector<uint64_t>(pos_x + 1)));

	//Base Cases
	for (size_t i(0); i <= pos_x; ++i)
	{
		ways[1][i] = 1;
	}

	for (size_t i(0); i <= pos_y; ++i)
	{
		ways[i][1] = 1;
	}

	//Conquered cases
	for (size_t i(2); i <= pos_y; ++i)
	{
		for (size_t j(2); j <= pos_x; ++j)
		{
			ways[i][j] = ways[i][ j - 1] + ways[i - 1][j];
		}
	}

	return ways[pos_y][pos_x];
}

uint32_t knapsack_solve(std::vector<std::pair<uint32_t, uint32_t> > items, const uint32_t capacity)
{
	//Create matrix of possible combinations like:
	//maximum from best previous combination and current value + best combination without current value
	std::vector<std::vector<uint32_t> > combinations(capacity + 1, std::vector<uint32_t>(items.size() + 1));

	//Base Cases
	for (size_t item(0); item <= items.size(); ++item)
	{
		combinations[0][item] = 0;
	}

	for (size_t value(0); value <= capacity; ++value)
	{
		combinations[value][0] = 0;
	}

	//doubtful, but okay
	if (capacity == 0) {
		return 0;
	}

	//Conquered cases
	for (size_t item(1); item <= items.size(); ++item)
	{
		auto current_item = items[item - 1].first;
		auto current_value = items[item - 1].second;

		for (size_t value(1); value <= capacity; ++value)
		{
			combinations[value][item] = combinations[value][item - 1];
		}

		for (size_t value(current_item); value <= capacity; ++value)
		{
			combinations[value][item] = std::max(combinations[value][item - 1], //take only previous combination
											 	current_value + combinations[value - current_item][item - 1] //take current + previous combination
												);
		}
	}

	return combinations[capacity][items.size()]; // The last combination is a result
}


uint32_t levenshtein_distance(const std::string a, const std::string b)
{
	//https://en.wikipedia.org/wiki/Levenshtein_distance
	std::vector<std::vector<uint32_t> > lev_matrix(a.size() + 1, std::vector<uint32_t>(b.size() + 1));

	//Base Cases
	for (size_t i(0); i <= a.length(); ++i)
	{
		lev_matrix[i][0] = i;
	}

	for (size_t j(0); j <= b.length(); ++j)
	{
		lev_matrix[0][j] = j;
	}

	//Conquered cases
	for (size_t i(1); i <= a.length(); ++i)
	{
		for (size_t j(1); j <= b.length(); ++j)
		{
			if (a[i-1] == b[j - 1])
			{
				lev_matrix[i][j] = lev_matrix[i - 1][j - 1];
			} else {
				lev_matrix[i][j] = std::min(std::min(lev_matrix[i - 1][j], lev_matrix[i][j - 1]), lev_matrix[i - 1][j - 1]) + 1;
			}

		}
	}

	return lev_matrix[a.length()][b.length()]; // The last combination is a result
}

