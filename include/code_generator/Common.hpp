/**
 * @file Common.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef COMMON_HPP
#define COMMON_HPP

#include <memory>

template<typename T>
using RefObject = std::shared_ptr<T>;

template <typename T, typename ...Args>
inline RefObject<T> createRefObject(Args&&... args) {
  return std::make_shared<T>(std::forward<Args>(args)...);
}

template <typename T>
using EnableSharedRefObject = std::enable_shared_from_this<T>;

template <typename T, typename Y>
inline RefObject<T> StaticCastRefObject(RefObject<Y> o)  {
  return std::static_pointer_cast<T>(o);
}

#endif // COMMON_HPP
