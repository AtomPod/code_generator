/**
 * @file While.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef WHILE_HPP
#define WHILE_HPP

#include "FlowControl.hpp"

class While;
typedef RefObject<While> WhileRef;

class While : public FlowControl
{
public:
  static const uint16_t ID;

public:
  static WhileRef create(const CodeRef condition,
                        const CodeContainer &codeContainer);
public:
  While();
  While(CodeRef condition,
     const CodeContainer &codeContainer);

public:
  uint16_t id() const override { return ID; }
};

inline WhileRef while_(const CodeRef condition,
                       const While::CodeContainer &codeContainer) {
  return While::create(condition, codeContainer);
}

#endif // WHILE_HPP
