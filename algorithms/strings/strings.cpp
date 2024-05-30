#include "strings.h"

//#define DEBUG_MODE

//https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
std::vector<uint32_t> prefix_func_kmp(const std::string sample, const std::string incoming_text)
{
	//dirty hack ;)
	//must be fixed
	std::string text = '@' + incoming_text;

	std::vector<uint32_t> result = {};
	std::vector<uint32_t> pi(text.length(), 0);

	// Go through the whole text
	for (size_t i = 1; i < text.length(); ++i) // i - index for text
	{
		size_t k = pi[i - 1];	// k - index for sample
								// k - cannot became greater than sample lenght

		// loop searchs index of max length prefix
		while (k > 0 and text[i] != sample[k])
		{
			k = pi[k-1];
		}

		// It suitable for max length prefix and new matching symbol
		if (text[i] == sample[k]) {
			++k;
		}

		// it saves the new number of coincidences in the series
		pi[i] = k;

		// it saves the position of full coincidence
		if (pi[i] == sample.length()) {
			result.push_back(i-sample.length());
		}
	}
#ifdef DEBUG_MODE
	return pi;
#endif
	return result;
}
