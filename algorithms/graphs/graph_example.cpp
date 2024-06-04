#include "graph_example.h"

void GraphTypeSimple::fill_edges(const int32_t& vertexes_amount, const EdgesSet& edges)
{
    if (vertexes_amount == 0 and edges.empty() or
                                vertexes_amount != 0){
        iEdges = edges;
        iVertexesAmount = vertexes_amount;
        return;
    }

    throw Parent::GraphTypeException("Impossible to create any edges without vertexes!");
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

AdjacencyMatrix::AdjacencyMatrix(const int32_t& vertexes_amount, const EdgesSet& edges)
{
    if (vertexes_amount == 0 and edges.empty() or
                                vertexes_amount != 0){
		Parent::iVertexesAmount = vertexes_amount;
		iEdges = EdgesMatrix(vertexes_amount, std::vector<bool>(vertexes_amount, 0));

		for (auto i : edges)
		{
			iEdges[i.first][i.second] = 1;
			iEdges[i.second][i.first] = 1;
		}
		return;
	}
	throw Parent::GraphTypeException("Impossible to create any edges without vertexes!");
}

void AdjacencyMatrix::fill_edges(const int32_t& vertexes_amount, const EdgesSet& edges)
{
    if (vertexes_amount == 0 and edges.empty() or
                                vertexes_amount != 0){
		Parent::iVertexesAmount = vertexes_amount;
		iEdges = EdgesMatrix(vertexes_amount + 1, std::vector<bool>(vertexes_amount + 1, 0));

		for (auto i : edges)
		{
			iEdges[i.first][i.second] = 1;
			iEdges[i.second][i.first] = 1;
		}
		return;
	}
    throw Parent::GraphTypeException("Impossible to create any edges without vertexes!");
}

void AdjacencyMatrix::print_edges() const
{
	std::cout << "Vertexes amount: " << iVertexesAmount << "\n";
	std::cout << "{\n";
	for (auto rows : iEdges)
	{
		for (auto i : rows)
		{
			std::cout << " " << i ;
	
		}
		std::cout << "\n";
	}
	std::cout << "}\n";
}

void AdjacencyMatrix::clean()
{
    iVertexesAmount = 0;
    iEdges.clear();
}
