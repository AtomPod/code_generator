#pragma once

#include "NamedType.hpp"
#include "Var.hpp"

class Field;
typedef RefObject<Field> FieldRef;

/**
 * @brief The Field class 成员字段类
 */
class Field : public NamedType {
public:
    static const uint16_t ID;

public:
    using NamedType::NamedType;

public:
  static FieldRef create(const String &name, TypeRef parent);

public:
  /**
   * @brief visit 用于访问该字段
   * @param self  对应变量
   * @return 字段的变量 self->name
   **/
  VarRef visit(VarRef self);

  /**
   * @brief id 类型id
   * @return id
   **/
  virtual uint16_t id() const override {
    return Field::ID;
  }
};

inline FieldRef field_(const String &name, TypeRef parent) {
  return Field::create(name, parent);
}