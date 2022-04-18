/**
 * @file RawCode.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef RAWCODE_H
#define RAWCODE_H

#include "Code.hpp"

class RawCode;
typedef RefObject<RawCode> RawCodeRef;

class RawCode : public Code
{
  public:
    static const uint16_t ID;

  public:
    static RawCodeRef create(const String &custom, CodeType typ = CodeType_Normal, Kind kind = CodeStatment);

  public:
    RawCode(const String &custom, CodeType typ = CodeType_Normal, Kind kind = CodeStatment);

  public:
    virtual String toString() override;
    virtual int write(CodeWriter &writer) override;
    virtual Kind kind() const override { return m_kind; }
    virtual CodeType codeType() const override { return m_type; }
    virtual uint16_t id() const override { return RawCode::ID; }

  private:
    String m_custom;
    Kind m_kind;
    CodeType m_type;
};

inline RawCodeRef _(const String &custom) {
    return RawCode::create(custom);
}

extern CODEC_GENERATOR_API RawCodeRef EMPTY_LINE;

#endif // RAWCODE_H
