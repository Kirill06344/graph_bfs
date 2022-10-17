#include <iostream>
#include <functional>
#include <limits>
#include "Graph.h"
#include "messages.h"
#include "commands.h"

int main(int argv, char** argc) {
  istaev::Graph graph;

  std::map< std::string, std::function< void(istaev::Graph&)> > commands {
    {"print", istaev::PrintGraph(std::cin, std::cout)},
    {"add_vertex", istaev::AddVertex(std::cin, std::cout)},
    {"remove_vertex", istaev::RemoveVertex(std::cin, std::cout)},
    {"insert_edge", istaev::InsertEdge(std::cin, std::cout)},
    {"check_edge", istaev::CheckEdge(std::cin, std::cout)},
    {"bfs", istaev::Bfs(std::cin, std::cout)},
    {"calculate_diameter", istaev::CalcDiameter(std::cin, std::cout)}
  };

  std::string command = "";
  while (std::cin >> command) {
    try {
      commands.at(command)(graph);
    } catch (const std::exception& ex) {
      istaev::printInvalidCommand(std::cout) << "\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

}
