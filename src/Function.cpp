#include "code_generator/Function.hpp"
#include "code_generator/StringCodeWriter.hpp"
#include "code_generator/RawCode.hpp"
#include "code_generator/Ptr.hpp"
#include "code_generator/Array.hpp"

const uint16_t Function::ID = IdGenerator::nextID();

FunctionRef Function::create(const String &name,
                             TypeRef ret,
                             const FunctionType::ParamsContainer &params,
                             const CodeBlock::CodeContainer &codeContainer)
{
  return createRefObject<Function>(name, ret, params, codeContainer);
}

Function::Function(const String &name, TypeRef ret, const FunctionType::ParamsContainer &params, const CodeBlock::CodeContainer &codeContainer)
  : CodeBlock(codeContainer)
  , m_declare(createRefObject<FunctionType>(ret, params))
  , m_namedFunc(createRefObject<NamedType>(name, m_declare))
  , m_codeContainer(codeContainer) {

}

Function::~Function()
{

}

int Function::write(CodeWriter &writer) {
  if (m_namedFunc == nullptr)
    return -1;

  m_namedFunc->write(writer);
  writer.writeString("$s");
  return CodeBlock::write(writer);
}

CodeRef Function::call(const CodeBlock::CodeContainer &codeContainer, const VarRef &var)
{
  StringCodeWriter writer;
  if (var != nullptr) {
    writer.writeString(var->name());
    TypeRef typ = var->type();
    // TODO 检查类型是否是有调用能力得
    if (typ->id() == Ptr::ID) {
      writer.writeString("->");
    } else {
      writer.writeString(".");
    }
  }
  writer.writeString(name());
  writer.writeString("(");
  for (size_t i = 0; i < codeContainer.size(); ++i) {
    auto &code = codeContainer[i];
    code->write(writer);
    if (i != codeContainer.size() - 1) {
      writer.writeString(",$s");
    }
  }
  writer.writeString(")");
  return RawCode::create(writer.str(), CodeType_Var);
}

VarRef Function::var()
{
  return Var::create(name(), type());
}

void Function::setName(const String &name)
{
  m_namedFunc = createRefObject<NamedType>(name, m_declare);
}

String Function::name() const
{
  return m_namedFunc->name();
}


