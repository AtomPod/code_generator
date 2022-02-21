/**
 * @file Enum.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef ENUM_HPP
#define ENUM_HPP

#include "Type.hpp"
#include <vector>

class Enum;
typedef RefObject<Enum> EnumRef;

class EnumDeclare;
typedef RefObject<EnumDeclare> EnumDeclareRef;

class EnumDeclare : public Type
{
public:
  static EnumDeclareRef create(const String &name = String());

public:
  static const uint16_t ID;

public:
  EnumDeclare();
  EnumDeclare(const String &name);

public:
  virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) override;

  virtual uint16_t id() const override {
    return EnumDeclare::ID;
  }

public:
  String name() const;
  void setName(const String &name);

private:
  String m_name;
};

class Enum : public Type {
public:
  typedef std::vector<String> EnumNameContainer;

public:
  static EnumRef create(const EnumNameContainer &fields = EnumNameContainer(), const String &name = String());

public:
  static const uint16_t ID;

public:
  Enum(const EnumNameContainer &fields, const String &name);

public:
  virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) override;

  virtual uint16_t id() const override {
    return Enum::ID;
  }

public:
  EnumNameContainer fields() const;
  void setFields(const EnumNameContainer &fields);

  String name() const;
  void setName(const String &name);

public:
  EnumDeclareRef declare() const;

private:
  EnumDeclareRef m_declare;
  EnumNameContainer m_fields;
  String m_name;
};

inline EnumRef enum_(const Enum::EnumNameContainer &fields = Enum::EnumNameContainer(), const String &name = String()) {
  return Enum::create(fields, name);
}

#endif // ENUM_HPP
