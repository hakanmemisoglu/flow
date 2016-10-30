#include "expressions/scope.hpp"

namespace flow {

gcc_jit_param* Scope::get_parameter(const std::string &name) const {
  auto iter = m_mapping.find(name);
  if (iter != m_mapping.end()) {
    return iter->second;
  }
  else {
    return nullptr;
  }
}

void Scope::set_parameter(const std::string &name, gcc_jit_param *param) {
  m_mapping[name] = param;
}

}
