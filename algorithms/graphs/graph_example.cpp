#include "graph_example.h"

void GraphTypeSimple::fill(const int32_t& vertexes_amount, const EdgesSet& edges)
{
    if (vertexes_amount == 0 and edges.empty() or
                                vertexes_amount != 0){
        iEdges = edges;
        iVertexesAmount = vertexes_amount;
        return;
    }
    throw Parent::GraphTypeException("Impossible to create any edges without vertexes!");
}

void GraphTypeSimple::print() const
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
                                vertexes_amount != 0)
	{
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

void AdjacencyMatrix::fill(const int32_t& vertexes_amount, const EdgesSet& edges)
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

void AdjacencyMatrix::print() const
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

AdjacencyListType::AdjacencyListType(const int32_t& vertexes_amount, const EdgesSet& edges)
{
	fill(vertexes_amount,edges);
}

void AdjacencyListType::fill(const int32_t& vertexes_amount, const EdgesSet& edges)
{
    if (vertexes_amount == 0 and edges.empty() or
                                vertexes_amount != 0)
	{
		Parent::iVertexesAmount = vertexes_amount;
		uint32_t shift(0);
		iOffset.push_back(0);
		for (uint32_t v(0); v < vertexes_amount;v++)
		{
			for (const auto& edge : edges)
			{
				if (v == edge.first) {
					iAdjacencies.push_back(edge.second);
					shift++;
				} //else {break;}
			}
			iOffset.push_back(shift);
		}
		return;
	}
	throw Parent::GraphTypeException("Impossible to create any edges without vertexes!");
}

void AdjacencyListType::print() const
{
	std::cout << "Vertexes amount: " << iVertexesAmount << "\n";
#ifdef DEBUG_MODE
	std::cout << "{ ";
	for (auto i : iAdjacencies)
	{
		std::cout << i << ", ";
	}
	std::cout << "}\n";
	std::cout << "{ ";
	for (auto i : iOffset)
	{
		std::cout << i << ", ";
	}
	std::cout << "}\n";
#endif //DEBUG_MODE
	if (iAdjacencies.empty()) {
		std::cout << "Edges amount: 0\n\n";
		return;
	}
	std::cout << "Vertex:\twith:\n";
	std::cout << "\n";
	for (uint32_t v(0); v < iVertexesAmount;v++)
	{
		std::cout << v << ":\t";
		for (uint32_t i(iOffset[v]); i < iOffset[v+1];i++)
		{
			std::cout << iAdjacencies[i] << ", ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void AdjacencyListType::clean()
{
    iVertexesAmount = 0;
    iAdjacencies.clear();
	iOffset.clear();
}
