# SpendScan

A **terminal-based** expense overview tool for **high-level personal finance insights**.


## Assumptions

The program expects that a given CSV file contains fields for `description`, `date`, `amount`, and `end_balance`. The script `prepcsv.sed` (which is called by `prepcsv`) expects a specific CSV format, namely that provided by CapitalOne, and modifies it accordingly. As this is a personal project, I have no intention at this time to generalize this script.


## Usage

    $ prepcsv /path/to/original/csv /path/to/new/csv
    $ ./spendscan < /path/to/new/csv


## Feature Roadmap

- Implement the `Transaction::Analyze()` function for sorting transactions
- Enable output to file
- Implement a TUI with `ncurses`
