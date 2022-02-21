/**
 * @file Lit.h
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef LIT_H
#define LIT_H
#include "Code.hpp"

class Lit;
typedef RefObject<Lit> LitRef;

class Lit : public Code
{
public:
  static const uint16_t ID;

public:
  static LitRef create(const String &str);

public:
  Lit(const String &str);

public:
  virtual String toString() override;
  virtual int write(CodeWriter &writer) override;
  virtual Kind kind() const override { return CodeStatment; }
  virtual CodeType codeType() const override { return CodeType_Text; }
  virtual uint16_t id() const override { return ID; }

public:
  const String &value() const;
  void setValue(const String &value);

private:
  String m_value;
};

#endif // LIT_H
