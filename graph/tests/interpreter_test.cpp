#include <chrono>
#include <iostream>
#include <random>
#include <string>

#include "graph/aggregate_node.hpp"
#include "graph/table_node.hpp"
#include "graph/filter_node.hpp"
#include "graph/print_node.hpp"

#include "expressions/filter_expression.hpp"
#include "expressions/variable_expression.hpp"
#include "expressions/equal_expression.hpp"
#include "expressions/addition_expression.hpp"
#include "expressions/constant_expression.hpp"
#include "expressions/lessthan_expression.hpp"

int main() {
  flow::TableNodePtr table_node = std::make_shared<flow::TableNode>("TableNode1", "Lineorder");

  flow::ExpressionPtr const_e1 = std::make_shared<flow::ConstantExpression>(10);
  flow::VariableExpressionPtr var_e1 = std::make_shared<flow::VariableExpression>("x");
  flow::ExpressionPtr addition_e1 = std::make_shared<flow::AdditionExpression>(var_e1, const_e1);
  flow::ExpressionPtr const_e2 = std::make_shared<flow::ConstantExpression>(30);

  flow::ExpressionPtr cond_e1 = std::make_shared<flow::LessThanExpression>(addition_e1, const_e2);

  flow::ParameterExpressionPtr param = std::make_shared<flow::ParameterExpression>("x");
  flow::FilterExpressionPtr filter_e = std::make_shared<flow::FilterExpression>("filter",
                                                                          param,
                                                                          cond_e1);

  flow::FilterNodePtr filter_node = std::make_shared<flow::FilterNode>("FilterNode1",
                                                                       table_node,
                                                                       filter_e);

  //flow::AggregateNodePtr agg_node = std::make_shared<flow::AggregateNode>("AggNode1", table_node, flow::AggregateType::SUM);

  flow::PrintNodePtr print_node = std::make_shared<flow::PrintNode>("PrintNode1",
                                                                    filter_node);

  /*
  for (std::int64_t i = 0; i < 60; ++i) {
    table_node->insert(i);
  } */

  std::mt19937 rand_gen;
  rand_gen.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> uni_dist(0,100);
  for (std::int64_t i = 0; i < 100000000; ++i) {
    table_node->insert(uni_dist(rand_gen));
  }

  auto query_begin = std::chrono::high_resolution_clock::now();
  print_node->open();
  while (print_node->hasNext()) {
    print_node->next();
  }
  auto query_end = std::chrono::high_resolution_clock::now();

  std::cout << "Query     : "
            << std::chrono::duration_cast<std::chrono::microseconds>(
                   query_end - query_begin)
                   .count()
            << " microseconds."
            << std::endl;
}
