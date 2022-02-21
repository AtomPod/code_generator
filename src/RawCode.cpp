#include "code_generator/RawCode.hpp"

const uint16_t RawCode::ID = IdGenerator::nextID();
RawCodeRef EMPTY_LINE = RawCode::create("");

RawCodeRef RawCode::create(const String &custom, CodeType typ, Kind kind)
{
  return createRefObject<RawCode>(custom, typ, kind);
}

RawCode::RawCode(const String &custom, CodeType typ, Kind kind)
  : m_custom(custom)
  , m_kind(kind)
  , m_type(typ)
{

}

String RawCode::toString()
{
  return m_custom;
}

int RawCode::write(CodeWriter &writer)
{
  writer.writeString(toString());
  return 0;
}
