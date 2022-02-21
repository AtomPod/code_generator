/**
 * @file Array.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Type.hpp"

class Array;
typedef RefObject<Array> ArrayRef;

/**
 * @brief The Array class 数组类
 */
class Array : public Type {
  public:
    static const uint16_t ID;

  public:
    static ArrayRef create(int n, TypeRef parent);

  public:
    Array(int n, TypeRef parent);

  public:
    int size() const;
    void setSize(int size);

  public:
    virtual int typeWrite(Dequque &leftSide, Dequque &rightSide) override;

    virtual uint16_t id() const override {
      return Array::ID;
    }

  private:
    int m_size;
};

inline ArrayRef array_(int n, TypeRef parent) {
  return Array::create(n, parent);
}

#endif // ARRAY_HPP
