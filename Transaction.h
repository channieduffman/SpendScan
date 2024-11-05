#ifndef TRANSACTION_H
#define TRANSACTION_H


#include <string>

enum TransType { UNDEFINED = 0, INCOME = 1, EXPENSE = 2, SAVINGS = 3 };

class Transaction {

private:

  std::string   description;
  std::string   date;
  float         amount;
  float         end_balance;
  TransType     type;

  TransType Analyze();

public:

  Transaction();
  Transaction(std::string m_description, std::string m_date, float m_amount, float m_end_balance);

  std::string get_description() const;
  float get_amount() const;
  float get_end_balance() const;
  TransType get_type() const;
  
  void Categorize();
};

#endif
