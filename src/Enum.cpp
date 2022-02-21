#include "code_generator/Enum.hpp"

const uint16_t Enum::ID = IdGenerator::nextID();
const uint16_t EnumDeclare::ID = IdGenerator::nextID();

EnumRef Enum::create(const Enum::EnumNameContainer &fields, const String &name)
{
  return createRefObject<Enum>(fields, name);
}

Enum::Enum(const Enum::EnumNameContainer &fields, const String &name)
  : Type(nullptr)
  , m_declare(EnumDeclare::create(name))
  , m_fields(fields)
  , m_name(name) {

}

int Enum::typeWrite(Type::Dequque &leftSide, Type::Dequque& rightSide) {
  declare()->typeWrite(leftSide, rightSide);
  if (!m_name.empty()) {
    leftSide.push_back("$s");
  }
  leftSide.push_back("{$>\n");


  for (size_t i = 0; i < m_fields.size(); ++i) {
    auto& field = m_fields[i];
    leftSide.push_back(field);

    if (i == m_fields.size() - 1) {
      leftSide.push_back("$<");
    } else {
      leftSide.push_back(",");
    }
    leftSide.push_back("\n");
  }
  leftSide.push_back("}");
  return 0;
}

Enum::EnumNameContainer Enum::fields() const
{
  return m_fields;
}

void Enum::setFields(const EnumNameContainer &fields)
{
  m_fields = fields;
}

String Enum::name() const
{
  return m_name;
}

void Enum::setName(const String &name)
{
  m_name = name;
}

EnumDeclareRef Enum::declare() const
{
  return m_declare;
}

EnumDeclareRef EnumDeclare::create(const String &name)
{
  return createRefObject<EnumDeclare>(name);
}

EnumDeclare::EnumDeclare(const String &name)
  : m_name(name)
{

}

int EnumDeclare::typeWrite(Type::Dequque &leftSide, Type::Dequque &/*rightSide*/)
{
  leftSide.push_back("enum$s");
  if (m_name.size() != 0) {
    leftSide.push_back(m_name);
  }
  return 0;
}

String EnumDeclare::name() const
{
    return m_name;
}

void EnumDeclare::setName(const String &name)
{
    m_name = name;
}
