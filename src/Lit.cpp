#include "code_generator/Lit.hpp"
#include "code_generator/StringCodeWriter.hpp"
#include <fmt/format.h>

const uint16_t Lit::ID = IdGenerator::nextID();

LitRef Lit::create(const String &str)
{
  return createRefObject<Lit>(str);
}

Lit::Lit(const String &str)
  : m_value(str)
{

}

String Lit::toString()
{
  StringCodeWriter writer;
  write(writer);
  return writer.str();
}

int Lit::write(CodeWriter &writer)
{
  writer.writeString(fmt::format("\"{}\"", value()));
  return 0;
}

const String &Lit::value() const
{
  return m_value;
}

void Lit::setValue(const String &value)
{
  m_value = value;
}
