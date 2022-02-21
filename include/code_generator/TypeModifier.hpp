/**
 * @file TypeModifier.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef TYPEMODIFIER_HPP
#define TYPEMODIFIER_HPP

#include "Type.hpp"

class TypeModifier;
class ConstType;
class StaticType;
typedef RefObject<TypeModifier> TypeModifierRef;
typedef RefObject<ConstType> ConstTypeRef;
typedef RefObject<StaticType> StaticTypeRef;

/**
 * @brief The TypeModifier class 类型修饰符
 */
class TypeModifier : public Type {
  public:
    static const uint16_t ID;

  public:
    static TypeModifierRef create(const String &modifier, bool header, TypeRef parent = nullptr);

  public:
    TypeModifier(const String &modifier, bool header, TypeRef parent = nullptr);

  public:
    virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) override;

    virtual uint16_t id() const override {
      return TypeModifier::ID;
    }
  private:
    String m_modifier;
    bool m_header;
};

/**
 * @brief The ConstType class 常量类型修饰符
 */
class ConstType : public TypeModifier {
  public:
    static const uint16_t ID;

  public:
    static ConstTypeRef create(TypeRef parent = nullptr);

  public:
    ConstType(TypeRef parent = nullptr);

  public:
    virtual uint16_t id() const override {
      return ID;
    }
};

/**
 * @brief The StaticType class 静态类型修饰符
 */
class StaticType : public TypeModifier {
  public:
    static const uint16_t ID;

  public:
    static StaticTypeRef create(TypeRef parent = nullptr);

  public:
    StaticType(TypeRef parent = nullptr);

  public:
    virtual uint16_t id() const override {
      return ID;
    }
};

inline ConstTypeRef const_(TypeRef parent = nullptr) {
  return ConstType::create(parent);
}

inline StaticTypeRef static_(TypeRef parent = nullptr) {
  return StaticType::create(parent);
}

#endif // TYPEMODIFIER_HPP
