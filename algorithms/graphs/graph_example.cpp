#include "graph_example.h"

void GraphTypeSimple::fill_edges(const int32_t& vertexes_amount, const EdgesSet& edges)
{
    if (vertexes_amount == 0 and edges.empty() or
                                vertexes_amount != 0){
        iEdges = edges;
        iVertexesAmount = vertexes_amount;
        return;
    }

    throw GraphTypeSimple_exception("Impossible to create any edges without vertexes!");
}

void GraphTypeSimple::print_edges() const
{
	std::cout << "Vertexes amount: " << iVertexesAmount << "\n{";
    for (const auto& edge : iEdges)
	{
		std::cout << " {" << edge.first << ", " << edge.second << "}";
	}
	std::cout << " }\n";
}

void GraphTypeSimple::clean()
{
    iVertexesAmount = 0;
    iEdges.clear();
}

