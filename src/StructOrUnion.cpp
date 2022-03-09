#include "code_generator/StructOrUnion.hpp"
#include "code_generator/RawCode.hpp"

const uint16_t Struct::ID = IdGenerator::nextID();
const uint16_t Union::ID = IdGenerator::nextID();

StructRef Struct::create(const StructorType::MembersContainer &fields, const String &name)
{
  return createRefObject<Struct>(fields, name);
}

Struct::Struct(const StructorType::MembersContainer &fields, const String &name)
  : StructorType(fields, "struct", name) {

}

void Struct::addFunction(const Struct::Permission &permission, FunctionRef func)
{
    m_functions[permission].push_back(func);
}

void Struct::addField(const Struct::Permission &persmission, FieldRef field)
{
    m_fields[persmission].push_back(field);
}

void Struct::addFields(const Struct::Permission &persmission,
                       const Struct::FieldContainer &container)
{
    for (auto &field : container) {
        m_fields[persmission].push_back(field);
    }
}

int Struct::typeWrite(Type::Dequque &larea, Type::Dequque &rarea)
{
  for (size_t i = 0; i < PERMISSION_COUNT; ++i) {
    if (m_functions[i].size() != 0) {
      addPermissionFunc(Permission(i), m_functions[i]);
    }
  }

  for (size_t i = 0; i < PERMISSION_COUNT; ++i) {
    if (m_fields[i].size() != 0) {
      addPermissionField(Permission(i), m_fields[i]);
    }
  }
  return StructorType::typeWrite(larea, rarea);
}

void Struct::addPermissionFunc(Struct::Permission p, const Struct::FunctionContainer &container)
{
  switch (p) {
  case PUBLIC:
    addCode(RawCode::create("$^$spublic:"));
    break;
  case PROTECTED:
    addCode(RawCode::create("$^$sprotected:"));
    break;
  case PRIVATE:
    addCode(RawCode::create("$^$sprivate:"));
    break;
  default:
    break;
  }

  for (size_t i = 0; i < container.size(); ++i) {
    addCode(container[i]);
  }
}

void Struct::addPermissionField(Struct::Permission p, const Struct::FieldContainer &container)
{
    switch (p) {
    case PUBLIC:
      addCode(RawCode::create("$^$spublic:"));
      break;
    case PROTECTED:
      addCode(RawCode::create("$^$sprotected:"));
      break;
    case PRIVATE:
      addCode(RawCode::create("$^$sprivate:"));
      break;
    default:
      break;
    }

    for (size_t i = 0; i < container.size(); ++i) {
      addCode(container[i]);
    }
}

UnionRef Union::create(const StructorType::MembersContainer &fields, const String &name)
{
  return createRefObject<Union>(fields, name);
}

Union::Union(const StructorType::MembersContainer &fields, const String &name)
  : StructorType(fields, "union", name) {

}
