#include "commands.h"
#include <iostream>
#include "messages.h"

istaev::PrintGraph::PrintGraph(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::PrintGraph::operator()(istaev::Graph& graph) {
  if (graph.isEmpty()) {
    istaev::graphIsEmpty(out_) << "\n";
    return;
  }
  graph.printGraph(out_);
}


istaev::AddVertex::AddVertex(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::AddVertex::operator()(istaev::Graph &graph) {

}

istaev::RemoveVertex::RemoveVertex(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::RemoveVertex::operator()(istaev::Graph &graph) {

}


istaev::InsertEdge::InsertEdge(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::InsertEdge::operator()(istaev::Graph &graph) {

}

istaev::CheckEdge::CheckEdge(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::CheckEdge::operator()(istaev::Graph &graph) {

}

istaev::Bfs::Bfs(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::Bfs::operator()(istaev::Graph &graph) {

}

istaev::CalcDiameter::CalcDiameter(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::CalcDiameter::operator()(istaev::Graph &graph) {

}
