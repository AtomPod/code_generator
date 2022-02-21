#include "code_generator/StringCodeWriter.hpp"

const String StringCodeWriter::INDENTATION = "  ";
const String StringCodeWriter::SPACER = " ";
const char StringCodeWriter::SPEICAL_CHAR = '$';
const char StringCodeWriter::CRLF = '\n';

StringCodeWriter::StringCodeWriter()
  : m_indent(0)
  , m_nextCharIsSpecial(false)
  , m_isNewLine(false)
{

}

int StringCodeWriter::writeString(const String &str) {
  for (size_t i = 0; i < str.size(); ++i) {
    char s = str[i];

    if (nextCharIsSpecial()) {
      handleSpecialChar(s);
    } else {
      if (!checkSpecial(s)) {
        handleNewLine();
        m_str.push_back(s);
        checkCRLF(s);
      }
    }
  }
  return 0;
}

void StringCodeWriter::handleSpecialChar(char c)
{
  switch (c) {
  case '>':
    m_indent++;
    break;
  case '<':
    m_indent--;
    break;
  case 's':
    m_str.append(StringCodeWriter::SPACER);
    break;
  case '^':
    setIsNewLine(false);
    break;
  default:
    break;
  }
  setNextCharIsSpecial(false);
}

bool StringCodeWriter::isNewLine() const
{
  return m_isNewLine;
}

void StringCodeWriter::setIsNewLine(bool isNewLine)
{
  m_isNewLine = isNewLine;
}

bool StringCodeWriter::checkSpecial(char c)
{
  if (c == StringCodeWriter::SPEICAL_CHAR) {
    setNextCharIsSpecial(true);
    return true;
  }
  return false;
}

void StringCodeWriter::checkCRLF(char c)
{
  if (c == CRLF) {
    setIsNewLine(true);
  }
}

void StringCodeWriter::handleNewLine()
{
  if (isNewLine()) {
    for (int i = 0; i < m_indent; ++i) {
      m_str.append(StringCodeWriter::INDENTATION);
    }
    setIsNewLine(false);
  }
}

bool StringCodeWriter::nextCharIsSpecial() const
{
  return m_nextCharIsSpecial;
}

void StringCodeWriter::setNextCharIsSpecial(bool nextCharIsSpecial)
{
  m_nextCharIsSpecial = nextCharIsSpecial;
}
