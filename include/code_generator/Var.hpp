/**
 * @file Var.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef VAR_HPP
#define VAR_HPP

#include "NamedType.hpp"
#include <vector>

class Var;
typedef RefObject<Var> VarRef;

class VarDefinition;
typedef RefObject<VarDefinition> VarDefinitionRef;

class VarDefinition : public Code, public EnableSharedRefObject<VarDefinition> {
public:
    enum AssignKind {
        EQUAL,
        CONSTRUCTOR
    };

    typedef std::vector<CodeRef> CodeRefList;

public:
  static const uint16_t ID;

public:
  static VarDefinitionRef create(const String &name,
                                 TypeRef typ,
                                 const CodeRef &value = nullptr);

public:
  VarDefinition(const String &name, TypeRef parent, const CodeRef &value = nullptr);

public:
  virtual String toString() override;
  virtual int write(CodeWriter &writer) override;
  virtual CodeType codeType() const override { return CodeType_VarDef; }
  virtual uint16_t id() const override { return ID; }
  virtual Kind kind() const override;

public:
  CodeRef value() const;
  TypeRef type() const;
  String name() const;

public:
  VarDefinitionRef assign(const CodeRef &code);
  VarDefinitionRef construct(const CodeRef &code);
  VarDefinitionRef construct(const CodeRefList &codes);

protected:
  AssignKind assignKind() const;
  void setAssignKind(const AssignKind &assignKind);

private:
  NamedTypeRef m_namedType;
  CodeRef m_value;
  AssignKind m_assignKind;
};

class Var : public Code, public EnableSharedRefObject<Var>
{
public:
  static const uint16_t ID;

public:
  static VarRef create(const String &name,
                       TypeRef parent);

public:
  Var(const String &name, TypeRef parent);

public:
  VarRef assign(const CodeRef &code);
  VarRef operator=(const CodeRef &code);

public:
  /**
     * @brief index 获取下标为idx的数组值
     * @param idx
     * @return 若不是数组，那么返回nullptr
     *         若数组越界，抛出out_of_range异常
     */
  VarRef index(size_t idx);

  /**
   * @brief ref 返回一个引用值
   * @return 若不能进行引用，抛出logic_error异常
   */
  VarRef ref();

  /**
   * @brief element 取地址值
   * @return 若不能取地址值，那么直接返回nullptr
   */
  VarRef element();

  /**
   * @brief address 取地址
   * @return 若不能取地址，那么直接返回nullptr
   */
  VarRef address();

public:
  virtual String toString() override;
  virtual int write(CodeWriter &writer) override;
  virtual CodeType codeType() const override { return CodeType_Var; }
  virtual uint16_t id() const override { return ID; }
  virtual Kind kind() const override;

public:
  CodeRef value() const;
  TypeRef type() const;
  String name() const;
  VarDefinitionRef definition() const;

private:
  CodeRef m_value;
  TypeRef m_type;
  String m_name;
};

inline VarRef var_(const String &name, TypeRef parent) {
  return Var::create(name, parent);
}

#endif // VAR_HPP
