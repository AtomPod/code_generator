#include "code_generator/Array.hpp"

const uint16_t Array::ID = IdGenerator::nextID();

ArrayRef Array::create(int n, TypeRef parent)
{
  return createRefObject<Array>(n, parent);
}

Array::Array(int n, TypeRef parent) : Type(parent) , m_size(n) {

}

int Array::size() const
{
  return m_size;
}

void Array::setSize(int size)
{
  m_size = size;
}

int Array::typeWrite(Type::Dequque &leftSide, Type::Dequque &rightSide) {
  TypeRef oriType = parent();
  if (oriType == nullptr) {
    return -EINVAL;
  }

  int ecode = oriType->typeWrite(leftSide, rightSide);
  if (ecode != 0) {
    return ecode;
  }

  char formated[32];
  snprintf(formated, sizeof (formated), "[%d]", size());
  rightSide.push_back(formated);
  return 0;
}
