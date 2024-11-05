#include <string>
#include "Transaction.h"

/* Constructors */

Transaction::Transaction() : description(""), date(""), amount(0.0), end_balance(0.0) { }

Transaction::Transaction(
  std::string m_description, std::string m_date, float m_amount, float m_end_balance
) : description(m_description), date(m_date), amount(m_amount), end_balance(m_end_balance) { }


/* Accessor Methods for Private Attributes */

std::string Transaction::get_description() const { return description; }

float Transaction::get_amount() const { return amount; }

float Transaction::get_end_balance() const { return end_balance; }

TransType Transaction::get_type() const { return type; }


/* Modifier Methods for `type` Attribute */

TransType Transaction::Analyze() {
  TransType t = UNDEFINED;

  if (description.contains("Purchase")) {
    t = EXPENSE;
  } else if (description.contains("Withdrawal")) {
    if (description.contains("STASH") || description.contains("BETTERMENT")) {
      t = SAVINGS;
    } else {
      t = EXPENSE;
    }
  } else if (description.contains("Deposit")) {
    t = INCOME;
  }

  return t;
}

void Transaction::Categorize() {
  type = Analyze();
}
