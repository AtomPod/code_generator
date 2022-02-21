/**
 * @file Evaluate.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef EVALUATE_HPP
#define EVALUATE_HPP

#include "Code.hpp"
#include <vector>
#include <fmt/format.h>
#include <fmt/ranges.h>

class Evaluate;
typedef RefObject<Evaluate> EvaluateRef;

class Evaluate : public Code
{
public:
    typedef std::vector<CodeRef> CodeArguments;

public:
    static const uint16_t ID;

public:
    static EvaluateRef create(const String &format, const CodeArguments &arguments = CodeArguments());

    template<typename... Args>
    static EvaluateRef create(const String &format, Args&&... args) {
      String value = fmt::format<Args...>(format, std::forward<Args>(args)...);
      return create(value, {});
    }

public:
    Evaluate();
    Evaluate(const String &format, const CodeArguments &arguments = CodeArguments());

public:
    virtual String toString() override;
    virtual int write(CodeWriter &writer) override;
    virtual Kind kind() const override { return Code::CodeStatment; }
    virtual CodeType codeType() const override { return CodeType_Normal; }
    /**
     * @brief id 类型ID
     * @return
     */
    virtual uint16_t id() const override { return ID; }

public:
    String format() const;
    void setFormat(const String &format);

    const CodeArguments &arguments() const;
    void setArguments(const CodeArguments &arguments);

private:
    String m_format;
    CodeArguments m_arguments;
};

#define $(...) Evaluate::create(__VA_ARGS__)

#endif // EVALUATE_HPP


