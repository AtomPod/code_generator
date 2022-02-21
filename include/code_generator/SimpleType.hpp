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

class BuiltinType {
  public:
    static SimpleTypeRef Int;
    static SimpleTypeRef UInt;
    static SimpleTypeRef Float;
    static SimpleTypeRef Double;
    static SimpleTypeRef Char;
    static SimpleTypeRef Long;
    static SimpleTypeRef ULong;
    static SimpleTypeRef Short;
    static SimpleTypeRef UShort;
    static SimpleTypeRef Void;
};

#endif // SIMPLETYPE_HPP
