#include "code_generator/Macro.hpp"
#include "code_generator/StringCodeWriter.hpp"
#include <fmt/format.h>

const uint16_t Macro::ID = IdGenerator::nextID();
const uint16_t Define::ID = IdGenerator::nextID();

MacroRef Macro::create(const String &content)
{
  return createRefObject<Macro>(content);
}

Macro::Macro()
{

}

Macro::Macro(const String &content)
    : m_content(content)
{

}

String Macro::toString()
{
    StringCodeWriter writer;
    write(writer);
    return writer.str();
}

int Macro::write(CodeWriter &writer)
{
    writer.writeString("$^");
    writer.writeString(content());
    return 0;
}

String Macro::content() const
{
    return m_content;
}

void Macro::setContent(const String &content)
{
    m_content = content;
}

Define::Define()
{

}

Define::Define(const String &name, const String &value)
    : Macro(fmt::format("#define {} {}", name, value))
    , m_name(name)
    , m_value(value)
{

}

int Define::write(CodeWriter &writer)
{
    setMacroContent(name(), value());
    return Macro::write(writer);
}

String Define::name() const
{
    return m_name;
}

void Define::setName(const String &name)
{
    m_name = name;
}

String Define::value() const
{
    return m_value;
}

void Define::setValue(const String &value)
{
    m_value = value;
}

void Define::setMacroContent(const String &name, const String &value)
{
   setContent(fmt::format("#define {} {}", name, value));
}
