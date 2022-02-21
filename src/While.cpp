#include "code_generator/While.hpp"

const uint16_t While::ID = IdGenerator::nextID();

WhileRef While::create(const CodeRef condition, const CodeBlock::CodeContainer &codeContainer)
{
    return createRefObject<While>(condition, codeContainer);
}

While::While()
  : FlowControl ("while")
{

}

While::While(CodeRef condition, const CodeBlock::CodeContainer &codeContainer)
  : FlowControl ("while", condition, codeContainer)
{

}
