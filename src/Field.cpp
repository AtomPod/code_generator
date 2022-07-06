#include "code_generator/Field.hpp"
#include "code_generator/Ptr.hpp"
#include "code_generator/Array.hpp"
#include "code_generator/FunctionDeclare.hpp"
#include "code_generator/StringCodeWriter.hpp"

const uint16_t Field::ID = IdGenerator::nextID();

FieldRef Field::create(const String &name, TypeRef parent) 
{
  return createRefObject<Field>(name, parent);
}

VarRef Field::visit(VarRef self) 
{
  StringCodeWriter writer;
  writer.writeString(self->name());
  TypeRef typ = self->type();
  // TODO 检查类型是否是有调用能力的
  if (typ->id() == Ptr::ID) {
    writer.writeString("->");
  } else {
    writer.writeString(".");
  }

  writer.writeString(name());
  return Var::create(writer.str(), type());
}