#include <typeinfo>
#include <map>
#include <set>
#include <vector>
#include <iostream> // WTF? it causes "still reachable: 72,704 bytes in 1 blocks"
#include "test.h"
#include "graph_example.cpp"

void test()
{
    std::vector<std::pair<int32_t, GraphTypeSimple::EdgesSet>> subjects = {
        {4, {{0,2},{3,0},{1,2},{1,3},{2,3}}},	// ways only
        {3, {{0,2},{1,2},{2,0},{1,0}}},			// ways only
        {5, {{0,1},{3,2},{2,0},{1,0},{2,3},{1,4},{4,1},{0,2}}},
        {3, {}},
        {0, {}},
        {0, {{1,3},{2,3},{3,1},{2,1}}},
        {0, {{}}}
    };
	std::vector<GraphTypeBase*> tested_graphs_types = {
					new GraphTypeSimple(),
					new AdjacencyMatrix(),
					new AdjacencyListType(),
					new AdjacencyMapType};

	for (auto i : tested_graphs_types)
	{
		std::cout << "\n" << " ========= Testing of " << typeid(*i).name() << " =========\n\n";
		for (const auto& params: subjects)
		{
		    try {
		        i->fill(params.first, params.second);
		        i->print();
				if (typeid(*i) == typeid(AdjacencyMapType)) {
					reinterpret_cast<AdjacencyMapType*>(i)->dfs(0);
				}
		        i->clean();
		    } catch (const GraphTypeBase::GraphTypeException& ex) {
		        std::cout << ex.what() << "\n";
		    } catch (const std::exception&) {
		        std::cout << "Something else wrong"<< std::endl;
		    }
		}
		delete i;
	}
}

int main()
{
    test();

    return 0;
}
