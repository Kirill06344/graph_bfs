#include "commands.h"
#include <iostream>
#include "messages.h"

namespace {
  bool correctInput(std::istream& in)
  {
    return !(!in && !in.eof());
  }

  void skip(std::istream& in) {
    in.clear();
    in.ignore();
  }

}

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
  int v;
  in_ >> v;
  if (!correctInput(in_)) {
    invalidArguments(out_) << "\n";
    skip(in_);
    return;
  }
  if (in_.peek() == '\n') {
    graph.insertNode(v);
    return;
  }
  std::list< int > nbrs;
  std::string tmp;
  in_ >> tmp;
  while (tmp.length() != 0) {
    int node;
    try {
      size_t inx = tmp.find(',');
      node = (inx == std::string::npos) ? std::stoi(tmp) : std::stoi(tmp.substr(0, inx));
      nbrs.push_back(node);
      if (inx == std::string::npos) {
        tmp.clear();
      } else {
        tmp.erase(0, inx + 1);
      }
    } catch (const std::exception& ex) {
      invalidArguments(out_) << "\n";
      return;
    }
  }
  graph.insertNode(v, std::move(nbrs));
}

istaev::RemoveVertex::RemoveVertex(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::RemoveVertex::operator()(istaev::Graph &graph) {
  int v;
  in_ >> v;
  if (!correctInput(in_)) {
    invalidArguments(out_) << "\n";
    skip(in_);
    return;
  }
  if (!graph.isEmpty() && graph.isNodeInGraph(v)) {
    graph.removeVertex(v);
  }
}


istaev::InsertEdge::InsertEdge(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::InsertEdge::operator()(istaev::Graph &graph) {
  int v1, v2;
  in_ >> v1;
  if (!correctInput(in_)) {
    invalidArguments(out_) << "\n";
    skip(in_);
    return;
  }

  if (in_.peek() == '\n') {
    invalidArguments(out_) << "\n";
    return;
  }

  in_ >> v2;
  if (!correctInput(in_)) {
    invalidArguments(out_) << "\n";
    skip(in_);
    return;
  }
  graph.insertEdgeBetweenNodes(v1, v2);
}

istaev::CheckEdge::CheckEdge(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::CheckEdge::operator()(istaev::Graph &graph) {
  int v1, v2;
  in_ >> v1;
  if (!correctInput(in_)) {
    invalidArguments(out_) << "\n";
    skip(in_);
    return;
  }

  if (in_.peek() == '\n') {
    invalidArguments(out_) << "\n";
    return;
  }

  in_ >> v2;
  if (!correctInput(in_)) {
    invalidArguments(out_) << "\n";
    skip(in_);
    return;
  }

  if (!graph.isEmpty()) {
    if (graph.isEdgeBetweenNodes(v1, v2)) {
      istaev::edgeIsPresent(out_) << '\n';
    } else {
      istaev::edgeIsAbsent(out_) << '\n';
    }
  }
}

istaev::Bfs::Bfs(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::Bfs::operator()(istaev::Graph &graph) {
  int v;
  in_ >> v;
  if (!correctInput(in_)) {
    invalidArguments(out_) << "\n";
    skip(in_);
    return;
  }
  if (graph.isEmpty() || !graph.isNodeInGraph(v)) {
    istaev::vertexIsAbsent(out_) << '\n';
    return;
  }
  auto paths = graph.findShortPathsForVertex(v);
  for (auto& it : paths) {
    out_ << it.first << " - " << it.second << '\n';
  }
}

istaev::CalcDiameter::CalcDiameter(std::istream &in, std::ostream &out):
  in_(in),
  out_(out)
{}

void istaev::CalcDiameter::operator()(istaev::Graph &graph) {
  if (graph.isTree()) {
    out_ << "Diameter of tree = " << graph.calculateDiameter() << '\n';
  } else {
    out_ << "Graph is not a tree!" << '\n';
  }
}
