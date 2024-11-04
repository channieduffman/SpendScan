#include "FieldsError.h"


FieldsError::FieldsError(int m_expected, int m_given) : expected(m_expected), given(m_given) { }

void FieldsError::Message() {
  std::cout << "FieldsError: expected " << expected << ", given " << given << std::endl;
}
