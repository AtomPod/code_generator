/**
 * @file FunctionDeclare.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef FUNCTIONDECLARE_HPP
#define FUNCTIONDECLARE_HPP

#include "Type.hpp"
#include <vector>

class FunctionType;
typedef RefObject<FunctionType> FunctionTypeRef;

/**
 * @brief The FunctionDeclare class 函数定义
 */
class FunctionType : public Type {
  public:
    typedef std::vector<TypeRef> ParamsContainer;

  public:
    static const uint16_t ID;

  public:
    static FunctionTypeRef create(TypeRef ret, const ParamsContainer &params);

  public:
    FunctionType(TypeRef ret, const ParamsContainer &params);
    virtual ~FunctionType() override;

  public:
    virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) override;

    virtual uint16_t id() const override {
      return FunctionType::ID;
    }

    virtual Kind kind() const override { return Code::Kind::CodeStatment; }

  public:
    TypeRef getReturn() const;
    void setReturn(TypeRef ret);

    const ParamsContainer &paramsContainer() const;
    void setParamsContainer(const ParamsContainer &paramsContainer);

  private:
    TypeRef m_return;
    ParamsContainer m_paramsContainer;
};


#endif // FUNCTIONDECLARE_HPP
