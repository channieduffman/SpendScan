#include <iostream>
#include <iomanip>
#include <memory>
#include <optional>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

#include "Print.h"
#include "Types.h"


/*
 * Prints a table of transaction values to the terminal
 *
 * types:  a vector of deques of transactions
 * totals: total values for each column
 *
 */
void Print(std::vector<std::deque<std::shared_ptr<Transaction> > > &types,
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
    std::vector<double> row_vals;
    for (int i = 0; i < types.size(); i++) {
      if (!types[i].empty()) {
        std::shared_ptr<Transaction> t = types[i].front();
        row_vals.push_back(t->get_amount());
        types[i].pop_front();
      } else {
        row_vals.push_back(0.0);
      }
    }
    PrintDouble(row_vals, col_width);
  } while (more_vals);

  // Print totals
  
  Line(w.ws_col, TOP_BOT_BORDER);
  PrintDouble(totals, col_width);
  Line(w.ws_col, TOP_BOT_BORDER);

  // Print gross

  std::cout << SIDE_BORDER << " Gross Income:\t" << totals[INCOME] << std::endl;

  // Print net

  double net = totals[INCOME] - totals[EXPENSE] + totals[OFFSET];
  std::cout << SIDE_BORDER << " Net Income:\t" << net << std::endl;

  Line(w.ws_col, TOP_BOT_BORDER);
}


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

void PrintDouble(std::vector<double> &values, int col_width) {
  for (auto value : values) {
    if (value > 0) {
      std::cout << SIDE_BORDER << " " << std::setw(col_width) << std::right << std::fixed << std::setprecision(2) << value;
    } else {
      std::cout << SIDE_BORDER << " " << std::setw(col_width) << "";
    }
  }
  std::cout << SIDE_BORDER << std::endl;
}
