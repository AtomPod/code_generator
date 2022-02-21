#include "code_generator/Ptr.hpp"
#include "code_generator/Array.hpp"
#include "code_generator/FunctionDeclare.hpp"
#include "code_generator/Ref.hpp"

const uint16_t Ptr::ID = IdGenerator::nextID();

PtrRef Ptr::create(TypeRef parent)
{
  return createRefObject<Ptr>(parent);
}

Ptr::Ptr(TypeRef parent) : Type(parent) {

}

int Ptr::typeWrite(Type::Dequque &leftSide, Type::Dequque &rightSide) {
  TypeRef oriType = parent();
  if (oriType == nullptr) {
    return -EINVAL;
  }

  int ecode = oriType->typeWrite(leftSide, rightSide);
  if (ecode != 0) {
    return ecode;
  }

  if (oriType->id() == Array::ID || oriType->id() == FunctionType::ID) {
    leftSide.push_back("(");
    leftSide.push_back("*");
    rightSide.push_back(")");
  } else {
    leftSide.push_back("*");
  }
  return 0;
}
