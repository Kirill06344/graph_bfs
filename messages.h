#ifndef MESSAGES_H
#define MESSAGES_H
#include "iosfwd"

namespace istaev {
  std::ostream& printInvalidCommand(std::ostream& out);
  std::ostream& graphIsEmpty(std::ostream& out);
  std::ostream& invalidArguments(std::ostream& out);
}
#endif
