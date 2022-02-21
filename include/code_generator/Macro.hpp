/**
 * @file Macro.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef MACRO_HPP
#define MACRO_HPP
#include "Code.hpp"

class Macro;
typedef RefObject<Macro> MacroRef;

class Macro : public Code
{
 public:
    static const uint16_t ID;
 public:
    static MacroRef create(const String &content);

 public:
    Macro();
    Macro(const String &content);

 public:
  virtual String toString() override;
  virtual int write(CodeWriter &writer) override;
  virtual Kind kind() const override { return CodeStatment; }
  virtual CodeType codeType() const override { return CodeType_Macro; }
  /**
   * @brief id 类型ID
   * @return
   */
  virtual uint16_t id() const override { return ID; }

 public:
    String content() const;
    void setContent(const String &content);

private:
    String m_content;
};

class Define;
typedef RefObject<Define> DefineRef;

class Define : public Macro {
  public:
    static const uint16_t ID;

  public:
    Define();
    Define(const String &name, const String &value = String());

  public:
    virtual uint16_t id() const override { return ID; }
    virtual int write(CodeWriter &writer) override;

  public:
    String name() const;
    void setName(const String &name);

    String value() const;
    void setValue(const String &value);

  protected:
    void setMacroContent(const String &name, const String &value);

  private:
    String m_name;
    String m_value;
};

#endif // MACRO_HPP
