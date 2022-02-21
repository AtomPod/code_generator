/**
 * @file Code.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef CODE_HPP
#define CODE_HPP

#include "CodeWriter.hpp"
#include "Common.hpp"
#include "IdGenerator.hpp"

/**
 * @brief The Code class 代码基类
 */
class Code
{
  public:
    enum Kind {
      CodeBlock,    // 代码块
      CodeStatment  // 代码段
    };

    enum CodeType {
      CodeType_Normal,
      CodeType_Type,
      CodeType_Var,
      CodeType_VarDef,
      CodeType_Function,
      CodeType_Conditaion,
      CodeType_Text,
      CodeType_Macro
    };

  public:
    Code() = default;
    virtual ~Code() = default;

  public:
    virtual String toString() = 0;
    virtual int write(CodeWriter &writer) = 0;
    virtual Kind kind() const = 0;
    virtual CodeType codeType() const { return CodeType_Normal; }
    /**
     * @brief id 类型ID
     * @return
     */
    virtual uint16_t id() const = 0;
};

typedef RefObject<Code> CodeRef;

#endif // CODE_HPP
