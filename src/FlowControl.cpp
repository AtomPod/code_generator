#include "code_generator/FlowControl.hpp"
#include "code_generator/StringCodeWriter.hpp"

const uint16_t FlowControl::ID = IdGenerator::nextID();
const uint16_t If::ID = IdGenerator::nextID();
const uint16_t Else::ID = IdGenerator::nextID();
const uint16_t ElseIf::ID = IdGenerator::nextID();

FlowControlRef FlowControl::create(const String &name, const CodeRef condition, const CodeBlock::CodeContainer &codeContainer)
{
  return createRefObject<FlowControl>(name, condition, codeContainer);
}

FlowControl::FlowControl(const String &name)
  : m_name(name)
{

}

FlowControl::FlowControl(const String &name,
                         const CodeRef condition,
                         const CodeContainer &codeContainer)
  : CodeBlock(codeContainer)
  , m_condition(condition)
  , m_name(name)
{

}

String FlowControl::toString()
{
  StringCodeWriter writer;
  write(writer);
  return writer.str();
}

IfRef If::create(CodeRef condition, const CodeBlock::CodeContainer &codeContainer)
{
  return createRefObject<If>(condition, codeContainer);
}

If::If()
  : FlowControl("if")
{

}

If::If(CodeRef condition, const FlowControl::CodeContainer &codeContainer)
  : FlowControl("if", condition, codeContainer)
{

}

ElseRef If::elsE(const CodeBlock::CodeContainer &codeContainer)
{
  auto ref = createRefObject<Else>(codeContainer);
  setElseFlowControl(ref);
  ref->setMainFlowControl(shared_from_this());
  return ref;
}

ElseIfRef If::elseIF(CodeRef condition, const CodeBlock::CodeContainer &codeContainer)
{
  auto ref = createRefObject<ElseIf>(condition, codeContainer);
  setElseFlowControl(ref);
  ref->setMainFlowControl(shared_from_this());
  return ref;
}

int FlowControl::write(CodeWriter &writer)
{
  writer.writeString(name());
  if (condition() != nullptr) {
    writer.writeString("$s(");
    condition()->write(writer);
    writer.writeString(")$s");
  } else {
    writer.writeString("$s");
  }
  CodeBlock::write(writer);

  FlowControlRef elseFC = elseFlowControl();
  if (elseFC != nullptr) {
    writer.writeString("$s");
    elseFC->write(writer);
  }
  return 0;
}

String FlowControl::name() const
{
  return m_name;
}

void FlowControl::setName(const String &name)
{
  m_name = name;
}

CodeRef FlowControl::condition() const
{
  return m_condition;
}

void FlowControl::setCondition(const CodeRef &condition)
{
  m_condition = condition;
}

FlowControlRef FlowControl::elseFlowControl() const
{
  return m_elseFlowControl;
}

void FlowControl::setElseFlowControl(const FlowControlRef &elseFlowControl)
{
  m_elseFlowControl = elseFlowControl;
}

FlowControlRef FlowControl::mainFlowControl() const
{
  return m_mainFlowControl;
}

void FlowControl::setMainFlowControl(const FlowControlRef &mainFlowControl)
{
  m_mainFlowControl = mainFlowControl;
}

Else::Else()
  : FlowControl("else")
{

}

Else::Else(const CodeBlock::CodeContainer &codeContainer)
  : FlowControl("else", nullptr, codeContainer)
{

}

FlowControlRef Else::endIf()
{
  return mainFlowControl();
}

ElseIf::ElseIf()
  : FlowControl("else if")
{

}

ElseIf::ElseIf(CodeRef condition, const CodeBlock::CodeContainer &codeContainer)
  : FlowControl("else if", condition, codeContainer)
{

}

ElseRef ElseIf::elsE(const CodeBlock::CodeContainer &codeContainer)
{
  auto ref = createRefObject<Else>(codeContainer);
  setElseFlowControl(ref);
  ref->setMainFlowControl(mainFlowControl());
  return ref;
}

ElseIfRef ElseIf::elseIF(CodeRef condition, const CodeBlock::CodeContainer &codeContainer)
{
  auto ref = createRefObject<ElseIf>(condition, codeContainer);
  setElseFlowControl(ref);
  ref->setMainFlowControl(mainFlowControl());
  return ref;
}

FlowControlRef ElseIf::endIf()
{
  return mainFlowControl();
}
