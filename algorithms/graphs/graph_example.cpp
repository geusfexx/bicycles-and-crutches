#include <map>
#include <set>
#include <iostream>


class GraphType
{
public:
typedef int32_t Vertex;
typedef std::set<Vertex> Vertexes;
typedef std::set<std::pair<Vertex, Vertex> > EdgesSet;

	GraphType(){}
	GraphType(const int32_t& vertexes_amount, const EdgesSet& edges) :
			 iVertexesAmount(vertexes_amount), iEdges(edges){}

	void fill_edges(const int32_t& vertexes_amount, const EdgesSet& edges) {}
	void print_edges() const
	{
		std::cout << "Vertexes amount: " << iVertexesAmount << "\n{";
		for (auto edge : iEdges)
		{
			std::cout << " {" << edge.first << ", " << edge.second << "}";
		}
		std::cout << " }\n";
	}

public:
	int32_t iVertexesAmount;
	EdgesSet iEdges;

};

int main()
{
	GraphType::EdgesSet eges = {{1,3},{4,1},{2,3},{2,4},{3,4}};
	GraphType g(4, eges);
	
	g.print_edges();

	return 0;
}
