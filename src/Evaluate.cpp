#include "code_generator/Evaluate.hpp"
#include <fmt/args.h>

const uint16_t Evaluate::ID = IdGenerator::nextID();

EvaluateRef Evaluate::create(const String &format, const Evaluate::CodeArguments &arguments)
{
  return createRefObject<Evaluate>(format, arguments);
}

Evaluate::Evaluate()
{

}

Evaluate::Evaluate(const String &format,
                   const Evaluate::CodeArguments &arguments)
    : m_format(format)
    , m_arguments(arguments)
{

}

String Evaluate::toString()
{
    auto store = fmt::dynamic_format_arg_store<fmt::format_context>();
    for (auto arg : arguments()) {
        if (arg != nullptr) {
            store.push_back(arg->toString());
        }
    }
    return fmt::vformat(format(), store);
}

int Evaluate::write(CodeWriter &writer)
{
    writer.writeString(toString());
    return 0;
}

String Evaluate::format() const
{
    return m_format;
}

void Evaluate::setFormat(const String &format)
{
    m_format = format;
}

const Evaluate::CodeArguments &Evaluate::arguments() const
{
    return m_arguments;
}

void Evaluate::setArguments(const CodeArguments &arguments)
{
    m_arguments = arguments;
}
