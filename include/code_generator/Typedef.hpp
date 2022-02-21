/**
 * @file Typedef.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef TYPEDEF_HPP
#define TYPEDEF_HPP

#include "NamedType.hpp"

class Typedef;
typedef RefObject<Typedef> TypedefRef;


class Typedef : public NamedType {
  public:
    static const uint16_t ID;

  public:
    static TypedefRef create(TypeRef origin, const String &name);

  public:
    Typedef(TypeRef origin, const String &name);

    virtual int write(CodeWriter &writer);

    virtual Kind kind() const {
      return Code::Kind::CodeStatment;
    }

  private:
    String m_name;
};

inline TypedefRef typedef_(TypeRef origin, const String &name) {
  return Typedef::create(origin, name);
}

#endif // TYPEDEF_HPP
