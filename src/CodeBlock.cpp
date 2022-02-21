#include "code_generator/CodeBlock.hpp"
#include "code_generator/StringCodeWriter.hpp"

CodeBlock::CodeBlock()
{

}

CodeBlock::CodeBlock(const CodeBlock::CodeContainer &codeContainer)
  : m_codeContainer(codeContainer)
{

}

CodeBlock::~CodeBlock()
{

}

String CodeBlock::toString()
{
  StringCodeWriter writer;
  write(writer);
  return writer.str();
}

int CodeBlock::write(CodeWriter &writer)
{
  writer.writeString("{$>");

  for (size_t i = 0; i < m_codeContainer.size(); ++i) {
    auto code = m_codeContainer[i];
    writer.writeString("\n");

    if (code->kind() == Code::CodeBlock && i != 0) {
        writer.writeString("\n");
    }

    code->write(writer);
    if (code->codeType() == Code::CodeType_Type || code->codeType() == Code::CodeType_Var ||
        code->codeType() == Code::CodeType_VarDef) {
      writer.writeString(";");
    }
  }

  writer.writeString("$<");
  if (m_codeContainer.size() != 0) {
    writer.writeString("\n");
  }

  writer.writeString("}");
  return 0;
}

CodeBlock::CodeContainer CodeBlock::codeContainer() const
{
    return m_codeContainer;
}

void CodeBlock::setCodeContainer(const CodeContainer &codeContainer)
{
  m_codeContainer = codeContainer;
}

void CodeBlock::addCode(const CodeRef &code)
{
  m_codeContainer.push_back(code);
}
