#include "code_generator/Ref.hpp"
#include "code_generator/Array.hpp"
#include "code_generator/Function.hpp"
#include "code_generator/Ptr.hpp"

const uint16_t Ref::ID = IdGenerator::nextID();

RefRef Ref::create(TypeRef parent)
{
  if (parent->id() == Ptr::ID) {
    throw std::invalid_argument("Ref::create: could not reference a pointer");
  }

  return createRefObject<Ref>(parent);
}

Ref::Ref(TypeRef parent)
  : Type(parent)
{

}

int Ref::typeWrite(Type::Dequque &leftSide, Type::Dequque &rightSide)
{
  TypeRef oriType = parent();
  if (oriType == nullptr) {
    return -EINVAL;
  }

  int ecode = oriType->typeWrite(leftSide, rightSide);
  if (ecode != 0) {
    return ecode;
  }

  if (oriType->id() == Array::ID) {
    leftSide.push_back("(");
    leftSide.push_back("&");
    rightSide.push_back(")");
  } else {
    leftSide.push_back("&");
  }
  return 0;
}
