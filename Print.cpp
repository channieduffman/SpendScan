#include <iostream>
#include <iomanip>

#include <sys/ioctl.h>
#include <unistd.h>

#include "Print.h"

const char SIDE_BORDER = '|';
const char TOP_BOT_BORDER = '-';

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

/*
 * Prints a row of transaction data
 *
 * u: undefined value converted to string
 * i: income value converted to string
 * e: expense value converted to string
 * s: savings value converted to string
 * col_width: the width of each column
 *
 */
void PrintRow(const std::string &u, 
              const std::string &i,
              const std::string &e,
              const std::string &s,
              int col_width) 
{
  std::cout << SIDE_BORDER << " " << std::setw(col_width) << std::left << u;
  std::cout << SIDE_BORDER << " " << std::setw(col_width) << std::left << i;
  std::cout << SIDE_BORDER << " " << std::setw(col_width) << std::left << e;
  std::cout << SIDE_BORDER << " " << std::setw(col_width) << std::left << s << SIDE_BORDER << std::endl;
}

/*
 * Prints a table of transactions to the terminal
 *
 * u: deque of undefined transactions
 * i: deque of income transactions
 * e: deque of expense transactions
 * s: deque of savings transactions
 *
 */
void Print(std::deque<Transaction*> &u,
           std::deque<Transaction*> &i,
           std::deque<Transaction*> &e,
           std::deque<Transaction*> &s) 
{

  // Get terminal width and set field width
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  // Column width; - 2 to account for border and padding
  int col_width = (w.ws_col / 4) - 2;

  /* Print Header */

  Line(w.ws_col, TOP_BOT_BORDER); 
  PrintRow("Undefined", "Income", "Expense", "Savings", col_width);
  Line(w.ws_col, TOP_BOT_BORDER); 

  /* Print Values */

  while (!u.empty() || !i.empty() || !e.empty() || !s.empty()) {
    
    std::string u_val, i_val, e_val, s_val; 

    // Check for undefined values
    if (!u.empty()) {
      Transaction *t = u.front();
      u_val = std::to_string(t->get_amount());
      u.pop_front();
    } else { u_val = ""; }

    // Check for income values
    if (!i.empty()) {
      Transaction *t = i.front();
      i_val = std::to_string(t->get_amount());
      i.pop_front();
    } else { i_val = ""; }

    // Check for expense values
    if (!e.empty()) {
      Transaction *t = e.front();
      e_val = std::to_string(t->get_amount());
      e.pop_front();
    } else { e_val = ""; }

    // Check for savings values
    if (!s.empty()) {
      Transaction *t = s.front();
      s_val = std::to_string(t->get_amount());
      s.pop_front();
    } else { s_val = ""; }

    PrintRow(u_val, i_val, e_val, s_val, col_width);
  }

  Line(w.ws_col, TOP_BOT_BORDER); 
}

