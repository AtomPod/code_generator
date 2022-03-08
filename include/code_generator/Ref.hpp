/**
 * @file Ref.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef REF_HPP
#define REF_HPP

#include "Type.hpp"

class Ref;
typedef RefObject<Ref> RefRef;

class Ref : public Type
{
  public:
    static const uint16_t ID;

  public:
    static RefRef create(TypeRef parent);

  public:
    Ref(TypeRef parent);

  public:
    virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) override;

    virtual uint16_t id() const override {
      return Ref::ID;
    }
};

inline RefRef ref_(TypeRef parent) {
    return Ref::create(parent);
}

#endif // REF_HPP
