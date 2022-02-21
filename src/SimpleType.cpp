#include "code_generator/SimpleType.hpp"

const uint16_t SimpleType::ID = IdGenerator::nextID();

SimpleTypeRef SimpleType::create(const String &type, TypeRef parent)
{
  return createRefObject<SimpleType>(type, parent);
}

SimpleType::SimpleType(const String &type, TypeRef parent) : Type(parent), m_type(type) {

}

int SimpleType::typeWrite(Type::Dequque &leftSide, Type::Dequque &rightSide) {
  TypeRef oriType = parent();
  if (oriType != nullptr) {
    int ecode = oriType->typeWrite(leftSide, rightSide);
    if (ecode != 0) {
      return ecode;
    }
  }

  leftSide.push_back(m_type);
  return 0;
}
