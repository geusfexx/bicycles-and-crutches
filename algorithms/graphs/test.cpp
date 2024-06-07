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
        {4, {{0,1},{0,2},{2,3}}},				// directed uncycled
        {4, {{0,1},{1,2},{3,2},{1,3}}},			//directed with broken cycle
        {4, {{0,1},{2,1},{1,3},{3,2}}},			//directed cycled
        {5, {{0,1},{3,2},{2,0},{1,0},{2,3},{1,4},{4,1},{0,2}}}, // undirected
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
					reinterpret_cast<AdjacencyMapType*>(i)->dfs(2);
					reinterpret_cast<AdjacencyMapType*>(i)->bfs(0);
					reinterpret_cast<AdjacencyMapType*>(i)->bfs(2);
					bool result = reinterpret_cast<AdjacencyMapType*>(i)->is_DAG();
					std::cout << "DAG: " << std::boolalpha << result << "\n";
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
