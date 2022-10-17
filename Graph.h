#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <list>
#include <iosfwd>

namespace istaev {
  using adjacencyList = std::map< int, std::list< int > >;
  class Graph {
    public:
      bool isEmpty();
      adjacencyList::iterator isNodeInGraph(int vertex);
      bool isEdgeBetweenNodes(int v1, int v2);
      adjacencyList::iterator insertNode(int v);
      adjacencyList::iterator insertNode(int v, std::list< int >&& nodes);
      void removeNode(int v);
      void insertEdgeBetweenNodes(int v1, int v2);
      void printGraph(std::ostream& out);
      void findShortPathsForVertex(int v);
    private:
      std::map<int, std::list< int >> vertexes;
      std::map< int, int > paths;
      void preparePathsForBfs();
      void bfs(int s);
  };
}
#endif
