/**
 * @file StructOrUnion.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef STRUCTORUNION_HPP
#define STRUCTORUNION_HPP

#include "StructorType.hpp"
#include "Function.hpp"
#include <vector>

class Struct;
class Union;
typedef RefObject<Struct> StructRef;
typedef RefObject<Union> UnionRef;

/**
 * @brief The Struct class 结构体
 */
class Struct : public StructorType {
  public:
    enum Permission {
      PUBLIC,
      PROTECTED,
      PRIVATE,
      PERMISSION_COUNT
    };

  public:
    typedef std::vector<FunctionRef> FunctionContainer;
    typedef std::vector<FieldRef> FieldContainer;

  public:
    static const uint16_t ID;

  public:
    static StructRef create(const MembersContainer &fields, const String &name = "");

  public:
    Struct(const MembersContainer &fields, const String &name = "");

  public:
    virtual uint16_t id() const override {
      return Struct::ID;
    }

  public:
    /**
     * @brief addFunction 添加成员函数
     * @param permission
     * @param func
     */
    void addFunction(const Permission &permission, FunctionRef func);

    /**
     * @brief addField 添加成员字段
     * @param persmission
     * @param field
     */
    void addField(const Permission &persmission, FieldRef field);

    /**
     * @brief addFields 批量添加成员字段
     * @param persmission
     * @param container
     */
    void addFields(const Permission &persmission, const FieldContainer &container);

    /**
     * @brief typeWrite
     * @param larea
     * @param rarea
     * @return
     */
    virtual int typeWrite(Dequque &larea, Dequque &rarea) override;

  protected:
    void addPermissionFunc(Permission p, const FunctionContainer &container);
    void addPermissionField(Permission p, const FieldContainer &container);

  private:
    FunctionContainer m_functions[PERMISSION_COUNT];
    FieldContainer m_fields[PERMISSION_COUNT];
};

/**
 * @brief The Union class 联合
 */
class Union : public StructorType {
  public:
    static const uint16_t ID;

  public:
    static UnionRef create(const MembersContainer &fields, const String &name = "");

  public:
    Union(const MembersContainer &fields, const String &name = "");

  public:
    virtual uint16_t id() const override {
      return Union::ID;
    }
};

inline StructRef struct_(const Struct::MembersContainer &fields, const String &name = "") {
  return Struct::create(fields, name);
}

inline UnionRef union_(const Struct::MembersContainer &fields, const String &name = "") {
  return Union::create(fields, name);
}

#endif // STRUCTORUNION_HPP
