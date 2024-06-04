#ifndef GraphTypeSimple_h
#define GraphTypeSimple_h

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
        GraphTypeSimple_exception(const std::string& message): iMessage(message){}

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

    void fill_edges(const int32_t& vertexes_amount, const EdgesSet& edges);

	void print_edges() const;

    void clean();

public:
        int32_t iVertexesAmount = 0;
        EdgesSet iEdges = {};
};

#endif // #ifndef GraphTypeSimple_h
