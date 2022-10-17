#include "messages.h"
#include <iostream>

std::ostream& istaev::printInvalidCommand(std::ostream& out) {
  return out << "Invalid command";
}

std::ostream &istaev::graphIsEmpty(std::ostream &out) {
  return out << "Graph is empty!";
}

std::ostream &istaev::invalidArguments(std::ostream &out) {
  return out << "Invalid arguments!";
}
