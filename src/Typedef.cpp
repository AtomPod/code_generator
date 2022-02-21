#include "code_generator/Typedef.hpp"

const uint16_t Typedef::ID = IdGenerator::nextID();

TypedefRef Typedef::create(TypeRef origin, const String &name)
{
  return createRefObject<Typedef>(origin, name);
}

Typedef::Typedef(TypeRef origin, const String &name) : NamedType(name, origin) {}

int Typedef::write(CodeWriter &writer) {
  writer.writeString("typedef$s");
  return NamedType::write(writer);
}
