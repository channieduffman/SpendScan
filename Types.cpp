#include <string>
#include <unordered_map>
#include "Types.h"

std::string ExtractTypeString(int type_index) {
  std::unordered_map<int, std::string> types = {
    {0, "Undefined"},
    {1, "Income"},
    {2, "Expense"},
    {3, "Savings"},
    {4, "Offset"}
  };
  return types.at(type_index);
}
