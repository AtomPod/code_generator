/**
 * @file StructorType.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef STRUCTORTYPE_H
#define STRUCTORTYPE_H

#include "TypeDefinition.hpp"
#include <vector>

class StructorTypeDeclare : public Type {
  public:
    static const uint16_t ID;

  public:
    StructorTypeDeclare(const String &keyword, const String &name);
    virtual ~StructorTypeDeclare() override;

  public:
    virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) override;

    virtual uint16_t id() const override {
      return StructorTypeDeclare::ID;
    }

    virtual Kind kind() const override { return Code::Kind::CodeStatment; }
  private:
    String m_name;
    String m_keyword;
};


/**
 * @brief The StructorType class 类结构化类型（比如struct、union等）
 */
class StructorType : public BlockTypeDefinition {
  public:
    typedef std::vector<CodeRef> MembersContainer;

  public:
    static const uint16_t ID;

  public:
    StructorType(const MembersContainer &fields,
                 const String &keyword,
                 const String &name = "");
    virtual ~StructorType() override;

  public:
    virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) override;

    virtual uint16_t id() const override {
      return StructorType::ID;
    }

    virtual Kind kind() const override { return Code::Kind::CodeBlock; }
  private:
    String m_name;
};

typedef RefObject<StructorType> StructorTypeRef;
typedef RefObject<StructorTypeDeclare> StructorTypeDeclareRef;

#endif // STRUCTORTYPE_H
