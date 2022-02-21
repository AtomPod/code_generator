#include "code_generator/NamedType.hpp"
#include "code_generator/Ptr.hpp"
#include "code_generator/Array.hpp"
#include "code_generator/FunctionDeclare.hpp"

const uint16_t NamedType::ID = IdGenerator::nextID();

NamedTypeRef NamedType::create(const String &name, TypeRef parent)
{
  return createRefObject<NamedType>(name, parent);
}

NamedType::NamedType(const String &name, TypeRef parent) : Type(parent), m_name(name) {

}

int NamedType::typeWrite(Type::Dequque &leftSide, Type::Dequque &rightSide) {
  TypeRef oriType = parent();
  if (oriType == nullptr) {
    return -EINVAL;
  }

  int ecode = oriType->typeWrite(leftSide, rightSide);
  if (ecode != 0) {
    return ecode;
  }

  if (!skipSpace(oriType)) {
    leftSide.push_back("$s");
  }
  leftSide.push_back(m_name);
  return 0;
}

bool NamedType::skipSpace(TypeRef origin)
{
  bool foundPtr = false;
  TypeRef parent = origin;
  while (parent != nullptr) {
    if (foundPtr) {
      return parent->id() == Array::ID || parent->id() == FunctionType::ID;
    } else if (parent->id() == Ptr::ID) {
      foundPtr = true;
    }
    parent = parent->parent();
  }
  return false;
}

void NamedType::setName(const String &name)
{
  m_name = name;
}

TypeRef NamedType::type() const
{
  return parent();
}

String NamedType::name() const
{
    return m_name;
}
