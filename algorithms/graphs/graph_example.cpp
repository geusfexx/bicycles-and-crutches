#include <map>
#include <set>
#include <vector>
#include <iostream>


class GraphTypeSimple
{
public:
typedef int32_t Vertex;
typedef std::set<Vertex> Vertexes;
typedef std::set<std::pair<Vertex, Vertex> > EdgesSet;

    class GraphTypeSimple_exception: public std::exception
    {
    public:
        GraphTypeSimple_exception(const std::string& message): iMessage(message)
        {}
        const char* what() const noexcept override
        {
            return iMessage.c_str();
        }
    private:
        std::string iMessage;
    };

        GraphTypeSimple(){}
        GraphTypeSimple(const int32_t& vertexes_amount, const EdgesSet& edges) :
			 iVertexesAmount(vertexes_amount), iEdges(edges){}

        void fill_edges(const int32_t& vertexes_amount, const EdgesSet& edges)
        {
            if (vertexes_amount == 0 and edges.empty() or
                                        vertexes_amount != 0){
                iEdges = edges;
                iVertexesAmount = vertexes_amount;
                return;
            }

            throw GraphTypeSimple_exception("Impossible to create any edges without vertexes!");
        }

	void print_edges() const
	{
		std::cout << "Vertexes amount: " << iVertexesAmount << "\n{";
                for (const auto& edge : iEdges)
		{
			std::cout << " {" << edge.first << ", " << edge.second << "}";
		}
		std::cout << " }\n";
	}

        void clean()
        {
            iVertexesAmount = 0;
            iEdges.clear();
        }

public:
        int32_t iVertexesAmount = 0;
        EdgesSet iEdges = {};
};

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

    for (auto params: subjects)
    {
        try {
            g.fill_edges(params.first, params.second);
            g.print_edges();
            g.clean();
        } catch (const GraphTypeSimple::GraphTypeSimple_exception& ex) {
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
