/**
 * @file Ptr.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef PTR_HPP
#define PTR_HPP

#include "Type.hpp"

class Ptr;
typedef RefObject<Ptr> PtrRef;

/**
 * @brief The Ptr class 指针类型
 */
class Ptr : public Type {
  public:
    static const uint16_t ID;

  public:
    static PtrRef create(TypeRef parent);

  public:
    Ptr(TypeRef parent);

  public:
    virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) override;

    virtual uint16_t id() const override {
      return Ptr::ID;
    }
};

inline PtrRef ptr_(TypeRef parent) {
  return Ptr::create(parent);
}

#endif // PTR_HPP
