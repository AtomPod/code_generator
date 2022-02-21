#include "code_generator/SimpleType.hpp"

SimpleTypeRef BuiltinType::Void = simpleType_("void");
SimpleTypeRef BuiltinType::Int = simpleType_("int");
SimpleTypeRef BuiltinType::UInt = simpleType_("unsigned int");
SimpleTypeRef BuiltinType::Float = simpleType_("float");
SimpleTypeRef BuiltinType::Double = simpleType_("double");
SimpleTypeRef BuiltinType::Char = simpleType_("char");
SimpleTypeRef BuiltinType::Long = simpleType_("long");
SimpleTypeRef BuiltinType::ULong = simpleType_("unsigned long");
SimpleTypeRef BuiltinType::Short = simpleType_("short");
SimpleTypeRef BuiltinType::UShort = simpleType_("unsigned short");

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
