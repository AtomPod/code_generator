/**
 * @file Argument.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef ARGUMENT_HPP
#define ARGUMENT_HPP
#include "NamedType.hpp"

typedef NamedTypeRef ArgumentRef;

inline ArgumentRef argument_(const String &name, TypeRef parent) {
  return namedType_(name, parent);
}

#endif // ARGUMENT_HPP
