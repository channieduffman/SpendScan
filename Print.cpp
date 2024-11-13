#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

#include "Print.h"
#include "Types.h"



void Print(std::vector<std::deque<std::shared_ptr<Transaction>>> &types,
             std::vector<double> &totals)
{
  const int col_count = types.size();

  // Get terminal width and set field width
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  // Column width; - 2 to account for border and padding
  int col_width = (w.ws_col / col_count) - 2;

  // Print the header with borders

  Line(w.ws_col, TOP_BOT_BORDER);
  std::vector<std::string> col_headers;
  for (int i = 0; i < types.size(); i++) {
    col_headers.push_back(ExtractTypeString(i));
  }
  PrintRow(col_headers, col_width);
  Line(w.ws_col, TOP_BOT_BORDER);

  // Print rows

  bool more_vals;
  do {
    more_vals = false;
    for (int i = 0; i < types.size(); i++) {
      if (!types[i].empty()) {
        more_vals = true;
      }
    }
    if (!more_vals) { break; }
    std::vector<std::string> row_vals;
    for (int i = 0; i < types.size(); i++) {
      if (!types[i].empty()) {
        std::shared_ptr<Transaction> t = types[i].front();
        row_vals.push_back(std::to_string(t->get_amount()));
        types[i].pop_front();
      } else {
        row_vals.push_back("");
      }
    }
    PrintRow(row_vals, col_width);
  } while (more_vals);

  // Print totals
  
  Line(w.ws_col, TOP_BOT_BORDER);
  PrintRow(totals, col_width);
  Line(w.ws_col, TOP_BOT_BORDER);
}


/*********************/
/* Utility Functions */
/*********************/


/* 
 * Prints a line of characters the width of the terminal.
 *
 * width: the length of the line to print
 * fill: the char to print
 *
 */
void Line(int width, char fill) {
  for (int i = 0; i < width; i++) {
    std::cout << fill;
  }
  std::cout << '\n';
}

