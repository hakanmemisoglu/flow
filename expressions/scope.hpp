#ifndef FLOW_EXPRESSIONS_SCOPE_HPP
#define FLOW_EXPRESSIONS_SCOPE_HPP

#include <unordered_map>
#include <string>

#include <libgccjit.h>

namespace flow {

class Scope {
public:
  Scope() = default;

  Scope(const Scope &other) = delete;
  Scope& operator=(const Scope &other) = delete;

  gcc_jit_param* get_parameter(const std::string &name) const;

  void set_parameter(const std::string &name, gcc_jit_param *param);

private:
  std::unordered_map<std::string, gcc_jit_param *> m_mapping;
};

}

#endif
