#include <map>
#include <set>



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
	void print_edges() const{}

public:
	int32_t iVertexesAmount;
	EdgesSet iEdges;

};


int main()
{
	GraphType::EdgesSet eges = {{},{},{},{},{}};
	GraphType g;
	
	g.print_edges();

	return 0;
}
