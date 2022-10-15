#include <iostream>
#include "Graph.h"

int main(int argv, char** argc) {
  istaev::Graph graph;

  graph.insertNode(1, {2, 3, 4});
  graph.printGraph();
  std::cout << std::endl;
  graph.insertNode(4);
  graph.printGraph();
  std::cout << std::endl;
  graph.insertNode(8, {1, 4, 7});
  graph.printGraph();
  std::cout << std::endl;
}
