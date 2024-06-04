#ifndef GraphTypeSimple_h
#define GraphTypeSimple_h

#include <map>
#include <set>
#include <vector>
#include <iostream>

class GraphTypeBase
{
public:
typedef int32_t Vertex;
typedef std::set<Vertex> Vertexes;
typedef std::set<std::pair<Vertex, Vertex> > EdgesSet;
typedef std::vector<std::vector<bool> > EdgesMatrix;

    class GraphTypeException: public std::exception
    {
    public:
        GraphTypeException(const std::string& message): iMessage(message){}

        const char* what() const noexcept override
        {
            return iMessage.c_str();
        }
    private:
        std::string iMessage;
    };

    GraphTypeBase(){}

    virtual void fill_edges(const int32_t& vertexes_amount, const EdgesSet& edges) = 0;

    virtual void print_edges() const = 0;

    virtual void clean() = 0;

protected:
    int32_t iVertexesAmount;

};

class GraphTypeSimple : public GraphTypeBase
{
public:
typedef GraphTypeBase Parent;

    GraphTypeSimple(){}
    GraphTypeSimple(const int32_t& vertexes_amount, const EdgesSet& edges) :
		 					iEdges(edges){Parent::iVertexesAmount = vertexes_amount;}

    virtual void fill_edges(const int32_t& vertexes_amount, const EdgesSet& edges);

	virtual void print_edges() const;

    virtual void clean();

protected:
    EdgesSet iEdges = {};
};


class AdjacencyMatrix : public GraphTypeBase
{
public:
typedef GraphTypeBase Parent;

    AdjacencyMatrix(){}
    AdjacencyMatrix(const int32_t& vertexes_amount, const EdgesSet& edges);

    virtual void fill_edges(const int32_t& vertexes_amount, const EdgesSet& edges);

	virtual void print_edges() const;

    virtual void clean();

protected:
    EdgesMatrix iEdges;
};
#endif // #ifndef GraphTypeSimple_h
