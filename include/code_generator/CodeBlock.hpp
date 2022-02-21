/**
 * @file CodeBlock.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef CODEBLOCK_HPP
#define CODEBLOCK_HPP

#include "Code.hpp"
#include <vector>

class CodeBlock : public Code
{
  public:
    typedef std::vector<CodeRef> CodeContainer;

  public:
    CodeBlock();
    CodeBlock(const CodeContainer &codeContainer);
    virtual ~CodeBlock() override;

  public:
    virtual String toString() override;
    virtual int write(CodeWriter &writer) override;
    virtual Kind kind() const override { return Code::CodeBlock; }

  public:
    CodeContainer codeContainer() const;
    void setCodeContainer(const CodeContainer &codeContainer);
    void addCode(const CodeRef &code);

  private:
    CodeContainer m_codeContainer;
};

#endif // CODEBLOCK_HPP
