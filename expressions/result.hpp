#ifndef FLOW_EXPRESSIONS_RESULT_HPP
#define FLOW_EXPRESSIONS_RESULT_HPP

#include <cstdint>

enum class ResultType {
  BOOLEAN,
  INT64,
};

struct Result {
  ResultType type;
  union {
    bool bool_value;
    std::int64_t int64_value;
  } value;
};

#endif
