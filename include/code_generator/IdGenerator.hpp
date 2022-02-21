/**
 * @file IdGenerator.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef IDGENERATOR_HPP
#define IDGENERATOR_HPP

#include <atomic>

class IdGenerator
{
  public:
    static uint32_t nextID();
};

#endif // IDGENERATOR_HPP
