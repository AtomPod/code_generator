/**
 * @file StringCodeWriter.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef STRINGCODEWRITER_HPP
#define STRINGCODEWRITER_HPP

#include "CodeWriter.hpp"

/**
 * @brief The StringCodeWriter class 字符串代码写入
 */
class StringCodeWriter : public CodeWriter {
  public:
    static const String INDENTATION;
    static const String SPACER;
    static const char SPEICAL_CHAR;
    static const char CRLF;

  public:
    StringCodeWriter();

  public:
    virtual int writeString(const String &str);

  public:
    const String &str() const { return m_str; }

  protected:
    bool nextCharIsSpecial() const;
    void setNextCharIsSpecial(bool nextCharIsSpecial);

    bool isNewLine() const;
    void setIsNewLine(bool isNewLine);

  protected:
    bool checkSpecial(char c);
    void checkCRLF(char c);
    void handleNewLine();
    void handleSpecialChar(char c);

  private:
    int m_indent;
    bool m_nextCharIsSpecial = false;
    bool m_isNewLine;
    String m_str;
};

#endif // STRINGCODEWRITER_HPP
