#include "test.h"

void test()
{
    std::vector<std::pair<int32_t, GraphTypeSimple::EdgesSet>> subjects = {
        {4, {{1,3},{4,1},{2,3},{2,4},{3,4}}},
        {3, {{1,3},{2,3},{3,1},{2,1}}},
        {3, {}},
        {0, {}},
        {0, {{1,3},{2,3},{3,1},{2,1}}},
        {0, {{}}}
    };

    GraphTypeSimple g;

    for (const auto& params: subjects)
    {
        try {
            g.fill_edges(params.first, params.second);
            g.print_edges();
            g.clean();
        } catch (const GraphTypeBase::GraphTypeException& ex) {
            std::cout << ex.what() << "\n";
        } catch (const std::exception&) {
            std::cout << "Something else wrong"<< std::endl;
        }
    }

	AdjacencyMatrix am;
    for (const auto& params: subjects)
    {
        try {
            am.fill_edges(params.first, params.second);
            am.print_edges();
            am.clean();
        } catch (const GraphTypeBase::GraphTypeException& ex) {
            std::cout << ex.what() << "\n";
        } catch (const std::exception&) {
            std::cout << "Something else wrong"<< std::endl;
        }
    }

}

int main()
{
    test();

    return 0;
}
