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
