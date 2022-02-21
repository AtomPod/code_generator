/**
 * @file Type.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef TYPE_HPP
#define TYPE_HPP

#include "Code.hpp"
#include "IdGenerator.hpp"
#include <deque>

class Type;

typedef RefObject<Type> TypeRef;

/**
 * @brief The Type class 类型基类
 */
class Type : public Code
{
  public:
    typedef std::deque<String> Dequque;

  public:
    Type(TypeRef parent = nullptr);
    virtual ~Type() override;

  public:
    /**
     * @brief kind 种类
     * @return
     */
    virtual Kind kind() const override { return Code::Kind::CodeStatment; }

    /**
     * @brief type 代码类型
     * @return
     */
    virtual CodeType codeType() const override { return CodeType::CodeType_Type; }

    /**
     * @brief parent 父类型
     * @return
     */
    TypeRef parent() const;

  public:
    virtual String toString() override;
    virtual int write(CodeWriter &writer) override;

  public:
    virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) = 0;

  private:
    TypeRef m_parent;
};

#endif // TYPE_HPP
