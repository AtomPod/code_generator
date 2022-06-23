/**
 * @file CodeContainer.hpp
 * @author huangjian
 * @date 2022-06-23
 * @version 1.0
 * @copyright huangjian
 **/
#pragma once

#include "Code.hpp"
#include <vector>

/// CodeContainer 用于存放代码的容器，添加新的数据扩展
class CodeContainer : public std::vector<CodeRef> {
  public:
    using std::vector<CodeRef>::vector;

  public:
    /// 添加+=的支持，支持添加一个CodeRef列表，不再需要一直push_back写法
    inline CodeContainer &operator+=(std::initializer_list<CodeRef> &&codeList) {
      insert(end(), codeList.begin(), codeList.end());
      return *this;
    }

	/// 添加+=的支持，支持添加一个CodeRef
    inline CodeContainer &operator+=(const CodeRef &codeList) {
      insert(end(), codeList);
      return *this;
    }

    /// 添加函数调用方式进行添加
    inline CodeContainer &operator()(std::initializer_list<CodeRef> &&codeList) {
      return (*this) += std::move(codeList);
    }

	/// 添加函数调用方式进行添加
	inline CodeContainer &operator()(const CodeRef &code) {
	  return (*this) += code;
	}
};
