#include "code_generator/StructorType.hpp"

const uint16_t StructorType::ID = IdGenerator::nextID();
const uint16_t StructorTypeDeclare::ID = IdGenerator::nextID();

StructorType::StructorType(const StructorType::MembersContainer &fields,
                           const String &keyword,
                           const String &name)
  : BlockTypeDefinition(name, createRefObject<StructorTypeDeclare>(keyword, name), fields)
  , m_name(name) {

}

StructorType::~StructorType()
{

}

int StructorType::typeWrite(Type::Dequque &leftSide, Type::Dequque& rightSide) {
  declare()->typeWrite(leftSide, rightSide);
  if (!m_name.empty()) {
    leftSide.push_back("$s");
  }

  return BlockTypeDefinition::typeWrite(leftSide, rightSide);
}

StructorTypeDeclare::StructorTypeDeclare(const String &keyword, const String &name)
  : m_name(name)
  , m_keyword(keyword)
{

}

StructorTypeDeclare::~StructorTypeDeclare()
{

}

int StructorTypeDeclare::typeWrite(Type::Dequque &leftSide, Type::Dequque &/*rightSide*/)
{
  leftSide.push_back(m_keyword);
  leftSide.push_back("$s");
  if (m_name.size() != 0) {
    leftSide.push_back(m_name);
  }
  return 0;
}
