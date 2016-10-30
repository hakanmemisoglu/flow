#include "expressions/value.hpp"

#include <cstdint>

namespace flow {

Value::Value(const std::int64_t value)
  : m_value(value) {
}

std::int64_t Value::getVal() const {
  return m_value;
}

}
