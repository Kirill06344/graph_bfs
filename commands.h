#ifndef COMMANDS_H
#define COMMANDS_H
#include <iosfwd>
#include "Graph.h"
namespace istaev {
  struct PrintGraph {
    PrintGraph() = delete;
    PrintGraph(std::istream& in, std::ostream& out);
    void operator()(istaev::Graph& graph);
    private:
    std::istream& in_;
    std::ostream& out_;
  };

  struct AddVertex {
    AddVertex() = delete;
    AddVertex(std::istream& in, std::ostream& out);
    void operator()(istaev::Graph& graph);
  private:
    std::istream& in_;
    std::ostream& out_;
  };

  struct RemoveVertex {
    RemoveVertex() = delete;
    RemoveVertex(std::istream& in, std::ostream& out);
    void operator()(istaev::Graph& graph);
  private:
    std::istream& in_;
    std::ostream& out_;
  };

  struct InsertEdge {
    InsertEdge() = delete;
    InsertEdge(std::istream& in, std::ostream& out);
    void operator()(istaev::Graph& graph);
  private:
    std::istream& in_;
    std::ostream& out_;
  };

  struct CheckEdge {
    CheckEdge() = delete;
    CheckEdge(std::istream& in, std::ostream& out);
    void operator()(istaev::Graph& graph);
  private:
    std::istream& in_;
    std::ostream& out_;
  };

  struct Bfs {
    Bfs() = delete;
    Bfs(std::istream& in, std::ostream& out);
    void operator()(istaev::Graph& graph);
  private:
    std::istream& in_;
    std::ostream& out_;
  };

  struct CalcDiameter {
    CalcDiameter() = delete;
    CalcDiameter(std::istream& in, std::ostream& out);
    void operator()(istaev::Graph& graph);
  private:
    std::istream& in_;
    std::ostream& out_;
  };
}
#endif
