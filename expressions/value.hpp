#ifndef FLOW_EXPRESSIONS_VALUE_HPP
#define FLOW_EXPRESSIONS_VALUE_HPP

#include <cstdint>

namespace flow {

class Value {
public:
  Value() = delete;

  Value(const std::int64_t value);

  std::int64_t getVal() const;

private:
  const std::int64_t m_value;
};

}

#endif
