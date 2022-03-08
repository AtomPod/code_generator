/**
 * @file Return.hpp
 * @author huangjian
 * @date 2022-03-08
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef RETURNS_HPP
#define RETURNS_HPP

#include "Evaluate.hpp"

#define return_(code) Evaluate::create("return {};", code)

#endif // RETURNS_HPP
