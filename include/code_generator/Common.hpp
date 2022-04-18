/**
 * @file Common.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef COMMON_HPP
#define COMMON_HPP

#include "Config.h"
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

#ifdef WIN32
  #ifdef CODE_GENERATOR_STATIC
    #define CODEC_GENERATOR_API
  #elif CODE_GENERATOR_SHARED_LIBRARY 
    #if defined(CODEC_GENERATOR_EXPORT)
      #pragma warning (disable:4251)
      #define CODEC_GENERATOR_API __declspec(dllexport) 
    #else
      #pragma warning (disable:4251)
      #define CODEC_GENERATOR_API __declspec(dllimport)
    #endif
  #else
    #define CODEC_GENERATOR_API 
  #endif
#else
  #define CODEC_GENERATOR_API
#endif


#endif // COMMON_HPP
