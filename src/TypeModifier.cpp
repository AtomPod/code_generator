#include "code_generator/TypeModifier.hpp"

const uint16_t TypeModifier::ID = IdGenerator::nextID();
const uint16_t StaticType::ID = IdGenerator::nextID();
const uint16_t ConstType::ID = IdGenerator::nextID();

TypeModifierRef TypeModifier::create(const String &modifier, bool header, TypeRef parent)
{
  return createRefObject<TypeModifier>(modifier, header, parent);
}

TypeModifier::TypeModifier(const String &modifier, bool header, TypeRef parent)
  : Type(parent)
  , m_modifier(modifier)
  , m_header(header) {}

int TypeModifier::typeWrite(Type::Dequque &leftSide, Type::Dequque &rightSide) {
  TypeRef oriType = parent();
  if (oriType != nullptr) {
    int ecode = oriType->typeWrite(leftSide, rightSide);
    if (ecode != 0) {
      return ecode;
    }

    if (!m_header) {
      leftSide.push_back("$s");
    }
  }

  if (!m_header) {
    leftSide.push_back(m_modifier);
    leftSide.push_back("$s");
  } else {
    leftSide.push_front("$s");
    leftSide.push_front(m_modifier);
  }
  return 0;
}

ConstTypeRef ConstType::create(TypeRef parent)
{
  return createRefObject<ConstType>(parent);
}

ConstType::ConstType(TypeRef parent) : TypeModifier("const", false, parent) {}

StaticTypeRef StaticType::create(TypeRef parent)
{
  return createRefObject<StaticType>(parent);
}

StaticType::StaticType(TypeRef parent) : TypeModifier("static", true, parent) {}
