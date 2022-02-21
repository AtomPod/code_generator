/**
 * @file Function.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "Code.hpp"
#include "FunctionDeclare.hpp"
#include "NamedType.hpp"
#include "CodeBlock.hpp"
#include "TypeDefinition.hpp"
#include "Var.hpp"
#include <vector>

class Function;
typedef RefObject<Function> FunctionRef;

class Function : public CodeBlock {
  public:
    static const uint16_t ID;

  public:
    static FunctionRef create(const String &name,
                              TypeRef ret,
                              const FunctionType::ParamsContainer &params,
                              const CodeContainer &codeContainer);

  public:
    Function(const String &name,
             TypeRef ret,
             const FunctionType::ParamsContainer &params,
             const CodeContainer &codeContainer);
    virtual ~Function() override;

  public:
    virtual int write(CodeWriter &writer) override;
    virtual CodeType codeType() const override { return Code::CodeType_Function; }
    virtual uint16_t id() const override { return Function::ID; }

  public:
    NamedTypeRef declare() const {
      return m_namedFunc;
    }

    FunctionTypeRef type() const {
      return m_declare;
    }

    CodeRef call(const CodeContainer &codeContainer, const VarRef &var = nullptr);

    /**
     * @brief var 转换为一个变量类型
     * @return
     */
    VarRef var();

  public:
    void setName(const String &name);
    String name() const;

  private:
    FunctionTypeRef m_declare;
    NamedTypeRef m_namedFunc;
    CodeContainer m_codeContainer;
};

inline FunctionRef func_(const String &name,
                          TypeRef ret,
                          const FunctionType::ParamsContainer &params,
                         const Function::CodeContainer &codeContainer) {
  return Function::create(name, ret, params, codeContainer);
}

#endif // FUNCTION_HPP
