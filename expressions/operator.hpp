#ifndef FLOW_EXPRESSIONS_OPERATOR_HPP
#define FLOW_EXPRESSIONS_OPERATOR_HPP

namespace flow {

enum class OperatorID {
  E_ADD,  // +
  E_SUB,  // -
  E_MUL,  // *
  E_DIV,  // /
  E_MOD,  // %
  E_EQ,   // ==
  E_NEQ,  // !=
  E_GT,   // >
  E_GTE,  // >=
  E_LT,   // <
  E_LTE,  // <=
  E_CONST, // Constant value
  E_VAR,   // Variable
  E_FILTER, // Filter function
  E_FILTERBODY, // body
  E_PARAM, // Parameter
};

class Operator {
public:
  Operator() = delete;
  Operator(OperatorID op_id);

  Operator(const Operator &other) = default;
  Operator& operator=(Operator &other) = default;

private:
  OperatorID m_op_id;
};

}


#endif
