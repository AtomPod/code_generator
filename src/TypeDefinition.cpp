#include "code_generator/TypeDefinition.hpp"

TypeDefinition::TypeDefinition(const String &name,
                               TypeRef declare)
  : Type(declare)
  , m_name(name)
{

}

TypeRef TypeDefinition::declare() const
{
  return parent();
}

String TypeDefinition::name() const
{
  return m_name;
}

bool BlockTypeDefinition::hasPosition(int pos, BlockTypeDefinition::Position check)
{
  return (pos & check) == check;
}

int BlockTypeDefinition::indexToPosition(int idx, int count)
{
  int position = 0;
  if (idx == count - 1) {
    position |= Position_End;
  } else if (idx == 0) {
    position |= Position_Start;
  }
  return position;
}

BlockTypeDefinition::BlockTypeDefinition(const String &name,
                                         TypeRef declare,
                                         const BlockTypeDefinition::CodesContainer &codeContainer)
  : TypeDefinition(name, declare)
  , m_codeContainer(codeContainer)
{

}

BlockTypeDefinition::~BlockTypeDefinition()
{

}

const BlockTypeDefinition::CodesContainer &BlockTypeDefinition::codeContainer() const
{
  return m_codeContainer;
}

int BlockTypeDefinition::typeWrite(Dequque &leftSide, Dequque &rightSide)
{
  leftSide.push_back("{$>\n");

  for (size_t i = 0; i < m_codeContainer.size(); ++i) {
    auto& field = m_codeContainer[i];
    writeCode(field, indexToPosition(int(i), int(m_codeContainer.size())), leftSide, rightSide);
  }
  leftSide.push_back("}");
  return 0;
}

void BlockTypeDefinition::addCode(CodeRef code)
{
  m_codeContainer.push_back(code);
}

void BlockTypeDefinition::writeCode(CodeRef code, int position, Dequque &larea, Dequque &/*rarea*/)
{
  bool isStart = hasPosition(position, Position_Start);
  bool isEnd = hasPosition(position, Position_End);


  String fieldStr = code->toString();
  larea.push_back(fieldStr);
  if (code->codeType() != Code::CodeType_Text && code->codeType() != Code::CodeType_Normal) {
    larea.push_back(";");
  }

  if (isEnd) {
    larea.push_back("$<");
  }
  larea.push_back("\n");

  if (code->kind() == Code::Kind::CodeBlock) {
    if (!isStart) {
      larea.push_back("\n");
    }

    if (isEnd) {
      larea.push_back("\n");
    }
  }
}
