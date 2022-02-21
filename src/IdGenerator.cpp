#include "code_generator/IdGenerator.hpp"

uint32_t IdGenerator::nextID()
{
  static std::atomic_uint32_t idSerial(0);
  return idSerial.fetch_add(1);
}
