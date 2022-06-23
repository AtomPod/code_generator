/**
 * @file TypeDefinition.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef TYPEDEFINITION_HPP
#define TYPEDEFINITION_HPP

#include "Type.hpp"
#include "CodeContainer.hpp"
#include <vector>

/**
 * @brief The TypeDefinition class 类型定义
 */
class TypeDefinition : public Type
{
  public:
    TypeDefinition(const String &name,
                   TypeRef declare);
  public:
    /**
     * @brief declare 返回一个纯类型，无命名
     * @return
     */
    TypeRef declare() const;

    /**
     * @brief name 获取类型名称
     * @return
     */
    String name() const;

  private:
    String m_name;
};

class BlockTypeDefinition : public TypeDefinition {
  public:
    enum Position {
      Position_Start = 0x01,
      Position_End = 0x02
    };

    static bool hasPosition(int pos, Position check);

    /**
     * @brief indexToPosition
     * @param idx
     * @param count
     * @return
     */
    static int indexToPosition(int idx, int count);

  public:
    typedef ::CodeContainer CodesContainer;

  public:
    BlockTypeDefinition(const String &name,
                        TypeRef declare,
                        const CodesContainer &codeContainer);
    virtual ~BlockTypeDefinition() override;

  public:
    const CodesContainer &codeContainer() const;

  public:
    virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) override;
    virtual Kind kind() const override { return Code::CodeBlock; }

  protected:
    void addCode(CodeRef code);

    /**
     * @brief writeCode
     * @param code
     */
    void writeCode(CodeRef code, int position, Dequque &larea, Dequque &rarea);
  private:
    CodesContainer m_codeContainer;
};

#endif // TYPEDEFINITION_HPP
