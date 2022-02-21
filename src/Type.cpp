#include "code_generator/Type.hpp"
#include "code_generator/StringCodeWriter.hpp"

Type::Type(TypeRef parent) : m_parent(parent) {}

Type::~Type()
{

}

TypeRef Type::parent() const
{
  return m_parent;
}

String Type::toString() {
  StringCodeWriter writer;
  write(writer);
  return writer.str();
}

int Type::write(CodeWriter &writer) {

  Dequque leftSide;
  Dequque rightSide;

  int ecode = typeWrite(leftSide, rightSide);
  if (ecode != 0) {
    return ecode;
  }

  while (!leftSide.empty()) {
    std::string code = leftSide.front();
    leftSide.pop_front();
    writer.writeString(code);
  }

  while (!rightSide.empty()) {
    std::string code = rightSide.back();
    rightSide.pop_back();
    writer.writeString(code);
  }
  return 0;
}
