#ifndef GraphTypeSimple_h
#define GraphTypeSimple_h

#include <map>
#include <set>
#include <vector>
#include <iostream>

class GraphTypeBase
{
public:
typedef int32_t 								Vertex;
typedef std::set<Vertex>						Vertexes;
typedef std::vector<Vertex>						AdjacencyList;

typedef std::set<std::pair<Vertex, Vertex> >	EdgesSet;
typedef std::vector<std::vector<bool> >			EdgesMatrix;

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

    virtual void fill(const int32_t& vertexes_amount, const EdgesSet& edges) = 0;

    virtual void print() const = 0;

    virtual void clean() = 0;

	virtual ~GraphTypeBase(){iVertexesAmount = 0;}

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

    virtual void fill(const int32_t& vertexes_amount, const EdgesSet& edges);

	virtual void print() const;

    virtual void clean();

	virtual ~GraphTypeSimple() {clean();}

protected:
    EdgesSet iEdges = {};
};


class AdjacencyMatrix : public GraphTypeBase
{
public:
typedef GraphTypeBase Parent;

    AdjacencyMatrix(){}
    AdjacencyMatrix(const int32_t& vertexes_amount, const EdgesSet& edges);

    virtual void fill(const int32_t& vertexes_amount, const EdgesSet& edges);

	virtual void print() const;

    virtual void clean();

	virtual ~AdjacencyMatrix() {clean();}

protected:
    EdgesMatrix iEdges;
};

class AdjacencyListType : public GraphTypeBase
{
public:
typedef GraphTypeBase Parent;

    AdjacencyListType(){}
    AdjacencyListType(const int32_t& vertexes_amount, const EdgesSet& edges);

    virtual void fill(const int32_t& vertexes_amount, const EdgesSet& edges);

	virtual void print() const;

    virtual void clean();

	virtual ~AdjacencyListType() {clean();}

protected:
    AdjacencyList iAdjacencies;
	std::vector<uint32_t> iOffset;
};
#endif // #ifndef GraphTypeSimple_h
