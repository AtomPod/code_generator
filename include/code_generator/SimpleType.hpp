/**
 * @file SimpleType.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef SIMPLETYPE_HPP
#define SIMPLETYPE_HPP

#include "Type.hpp"

class SimpleType;
typedef RefObject<SimpleType> SimpleTypeRef;

class SimpleType : public Type {
  public:
    static const uint16_t ID;

  public:
    static SimpleTypeRef create(const String &codeType, TypeRef parent = nullptr);

  public:
    SimpleType(const String &codeType, TypeRef parent = nullptr);

  public:
    virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) override;

    virtual uint16_t id() const override {
      return SimpleType::ID;
    }

  private:
    String m_type;
};

inline SimpleTypeRef simpleType_(const String &codeType, TypeRef parent = nullptr) {
  return SimpleType::create(codeType, parent);
}

#endif // SIMPLETYPE_HPP
