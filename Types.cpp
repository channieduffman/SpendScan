#include <string>
#include <unordered_map>

#include "Types.h"

/*
 * Returns a map of integers to transaction types as strings
 */
std::unordered_map<int, std::string> MapTypes() {
  std::unordered_map<int, std::string> types = {
    {0, "Undefined"},
    {1, "Income"},
    {2, "Expense"},
    {3, "Savings"},
    {4, "Offset"}
  };
  return types;
}

/*
 * Returns a transaction type as a string given an integer
 */
std::string ExtractTypeString(int type_index) {
  std::unordered_map<int, std::string> types = MapTypes();
  return types.at(type_index);
}

/*
 * Returns the number of keys in the map
 */
int NumTypes() {
  std::unordered_map<int, std::string> types = MapTypes();
  return types.size();
}
