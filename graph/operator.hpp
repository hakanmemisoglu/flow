#ifndef FLOW_GRAPH_OPERATOR_HPP
#define FLOW_GRAPH_OPERATOR_HPP

namespace flow {

enum class OperatorID {
  E_ADD,
  E_SUB,
  E_MUL,
  E_DIV,
  E_MOD,
};

class Operator {
public:
  Operator() = delete;
  Operator(OperatorID op_id);

  Operator(const Operator &other) = delete;
  Operator& operator=(Operator &other) = delete;

private:
  OperatorID m_op_id;
};

}


#endif
