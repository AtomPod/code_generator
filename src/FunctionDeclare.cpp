#include "code_generator/FunctionDeclare.hpp"

const uint16_t FunctionType::ID = IdGenerator::nextID();

FunctionTypeRef FunctionType::create(TypeRef ret, const FunctionType::ParamsContainer &params)
{
  return createRefObject<FunctionType>(ret, params);
}

FunctionType::FunctionType(TypeRef ret, const FunctionType::ParamsContainer &params)
  : Type(ret)
  , m_return(ret)
  , m_paramsContainer(params) {

}

FunctionType::~FunctionType()
{

}

int FunctionType::typeWrite(Type::Dequque &leftSide, Type::Dequque &rightSide) {
  if (m_return != nullptr) {
    m_return->typeWrite(leftSide, rightSide);
  }
  rightSide.push_back(")");

  for (int64_t i = int64_t(m_paramsContainer.size()) - 1; i >= 0; --i) {
    auto param = m_paramsContainer[i];
    rightSide.push_back(param->toString());
    if (i != 0) {
      rightSide.push_back("$s");
      rightSide.push_back(",");
    }

  }
  rightSide.push_back("(");
  return 0;
}

const FunctionType::ParamsContainer &FunctionType::paramsContainer() const
{
    return m_paramsContainer;
}

void FunctionType::setParamsContainer(const ParamsContainer &paramsContainer)
{
    m_paramsContainer = paramsContainer;
}

TypeRef FunctionType::getReturn() const
{
    return m_return;
}

void FunctionType::setReturn(TypeRef ret)
{
    m_return = ret;
}
