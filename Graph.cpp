#include "Graph.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>

using namespace std::placeholders;

bool istaev::Graph::isEmpty() {
  return vertexes.empty();
}

istaev::adjacencyList::iterator istaev::Graph::isNodeInGraph(int vertex) {
  return vertexes.find(vertex);
}

bool istaev::Graph::isEdgeBetweenNodes(int v1, int v2) {
  auto it = vertexes.find(v1);
  return !(it == vertexes.end()) && std::find(it->second.begin(), it->second.end(), v2) != it->second.end();
}

std::map<int, std::list<int>>::iterator istaev::Graph::insertNode(int v, std::list< int >&& nodes) {
  for (auto it : nodes) {
    insertEdgeBetweenNodes(v, it);
  }
  auto result = vertexes.insert(std::make_pair(v, std::move(nodes)));
  return result.first;
}

istaev::adjacencyList::iterator istaev::Graph::insertNode(int v) {
  return insertNode(v, {});
}

void istaev::Graph::removeNode(int v) {
  vertexes.erase(v);
  for (auto it: vertexes) {
    std::remove(it.second.begin(), it.second.end(), v);
  }
}

void istaev::Graph::insertEdgeBetweenNodes(int v1, int v2) {
  if (!isEdgeBetweenNodes(v1, v2)) {
    auto first = insertNode(v1);
    auto second = insertNode(v2);
    first->second.push_back(v2);
    second->second.push_back(v1);
  }
}

void istaev::Graph::printGraph() {
  for (auto it : vertexes) {
    std::cout << it.first << " -> ";
    std::copy(it.second.begin(), it.second.end(), std::ostream_iterator< int >(std::cout, " "));
    std::cout << std::endl;
  }
}






