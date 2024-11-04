#ifndef FIELDS_ERROR_H
#define FIELDS_ERROR_H

#include <string>
#include <iostream>

class FieldsError { 
public:

  FieldsError(int m_expected, int m_given);
  void Message();

private:

  int         expected;
  int         given;
  std::string message;

};

#endif
