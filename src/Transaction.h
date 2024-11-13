#ifndef TRANSACTION_H
#define TRANSACTION_H


#include <string>
#include "Types.h"

class Transaction {

private:

  std::string   description;
  std::string   date;
  double        amount;
  double        end_balance;
  TransType     type;

  TransType Analyze();

public:

  Transaction();
  Transaction(std::string m_description, std::string m_date, double m_amount, double m_end_balance);

  std::string get_description() const;
  double get_amount() const;
  double get_end_balance() const;
  TransType get_type() const;
  
  void Categorize();
};

#endif
