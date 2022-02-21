﻿#include "code_generator/Var.hpp"
#include "code_generator/Array.hpp"
#include "code_generator/Ptr.hpp"
#include "fmt/format.h"
#include "code_generator/StringCodeWriter.hpp"
#include <stdexcept>

const uint16_t Var::ID = IdGenerator::nextID();
const uint16_t VarDefinition::ID = IdGenerator::nextID();

VarRef Var::create(const String &name, TypeRef parent)
{
    return createRefObject<Var>(name, parent);
}

Var::Var(const String &name, TypeRef parent)
    : m_type (parent)
    , m_name (name)
{

}

VarRef Var::assign(const CodeRef &code)
{
  return this->operator=(code);
}

VarRef Var::operator=(const CodeRef &code)
{
  VarRef newVar = Var::create(name(), type());
  newVar->m_value = code;
  return newVar;
}

VarRef Var::index(size_t idx)
{
  TypeRef p = type();
  if (p == nullptr)
    return nullptr;

  if (p->id() != Array::ID) {
    return nullptr;
  }

  ArrayRef array = StaticCastRefObject<Array>(p);
  if (array == nullptr)
    return nullptr;

  String idxName = fmt::format("{}[{}]", name(), idx);
  if (idx >= array->size()) {
    throw std::out_of_range("Var::index: out of range, value is " + idxName);
  }

  return Var::create(idxName, array->parent());
}

VarRef Var::ref()
{
  TypeRef p = type();
  if (p == nullptr)
    return nullptr;

  return nullptr;
}

VarRef Var::element()
{
  TypeRef p = type();
  if (p == nullptr)
    return nullptr;

  if (p->id() != Ptr::ID) {
    throw std::domain_error("Var::element: could not unref for a not ptr type");
  }

  TypeRef typ = p->parent();
  if (typ == nullptr) {
    throw std::domain_error("Var::element: could not create a empty type");
  }

  String eName = fmt::format("*{}", name());
  return Var::create(eName, typ);
}

VarRef Var::address()
{
  TypeRef p = type();
  if (p == nullptr)
    return nullptr;

  String eName = fmt::format("&{}", name());
  return Var::create(eName, Ptr::create(p));
}

String Var::toString()
{
  StringCodeWriter writer;
  write(writer);
  return writer.str();
}

int Var::write(CodeWriter &writer)
{
  writer.writeString(name());
  if (value() != nullptr) {
    writer.writeString("$s=$s");
    value()->write(writer);
  }
  return 0;
}

Code::Kind Var::kind() const {
  if (m_type == nullptr)
    return CodeStatment;

  return m_type->kind();
}

CodeRef Var::value() const
{
  return m_value;
}

TypeRef Var::type() const
{
  return m_type;
}

String Var::name() const
{
  return m_name;
}

VarDefinitionRef Var::definition() const
{
  return VarDefinition::create(name(), type());
}

VarDefinitionRef VarDefinition::create(const String &name, TypeRef typ, const CodeRef &value)
{
  return createRefObject<VarDefinition>(name, typ, value);
}

VarDefinition::VarDefinition(const String &name, TypeRef parent, const CodeRef &value)
  : m_namedType (NamedType::create(name, parent))
  , m_value(value) {

}

String VarDefinition::toString()
{
  return m_namedType->toString();
}

int VarDefinition::write(CodeWriter &writer)
{
   m_namedType->write(writer);
  if (value() != nullptr) {
    writer.writeString("$s=$s");
    value()->write(writer);
  }
  return 0;
}

Code::Kind VarDefinition::kind() const
{
  if (m_namedType == nullptr)
    return CodeStatment;

  return m_namedType->kind();
}

CodeRef VarDefinition::value() const
{
  return m_value;
}

TypeRef VarDefinition::type() const
{
  return m_namedType->type();
}

String VarDefinition::name() const
{
  return m_namedType->name();
}

VarDefinitionRef VarDefinition::assign(const CodeRef &code)
{
  VarDefinitionRef vardef = VarDefinition::create(name(), type(), code);
  return vardef;
}