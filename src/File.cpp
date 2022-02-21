#include "code_generator/File.hpp"

File::File()
{

}

int File::write(CodeWriter &writer)
{
    writeCodes(headers(), writer);
    if (numOfHeader() != 0) {
        writer.writeString("\n");
    }

    writeIncludes(includes(), writer);
    if (numOfInclude() != 0) {
        writer.writeString("\n");
    }

    writeTypes(declares(), writer);
    if (numOfDeclare() != 0) {
        writer.writeString("\n");
    }

    writeCodes(definitions(), writer);
    if (numOfDefinition() != 0) {
        writer.writeString("\n");
    }

    writeCodes(globalVars(), writer);
    if (numOfGlobalVar() != 0) {
        writer.writeString("\n");
    }

    writeCodes(codes(), writer);
    return 0;
}

File::IncludeContainer File::includes() const
{
    return m_includes;
}

void File::addInclude(const String &path)
{
    m_includes.insert(path);
}

File::CodeContainer File::headers() const
{
    return m_headers;
}

void File::addHeader(const CodeRef &code)
{
    m_headers.push_back(code);
}

File::TypeContainer File::declares() const
{
    return m_declares;
}

void File::addDeclare(const TypeRef declare)
{
    m_declares.push_back(declare);
}

File::CodeContainer File::definitions() const
{
    return m_definitions;
}

void File::addDefinition(const CodeRef &code)
{
    m_definitions.push_back(code);
}

File::CodeContainer File::globalVars() const
{
    return m_globalVars;
}

void File::addGlobalVar(const CodeRef &code)
{
    m_globalVars.push_back(code);
}

File::CodeContainer File::codes() const
{
    return m_codes;
}

void File::addCode(const CodeRef &code)
{
    m_codes.push_back(code);
}

void File::writeCodes(const CodeContainer &codes, CodeWriter &writer)
{
    for (auto code : codes) {
        code->write(writer);
        if (code->codeType() == Code::CodeType_Type || code->codeType() == Code::CodeType_Var ||
            code->codeType() == Code::CodeType_VarDef) {
          writer.writeString(";");
        }

        if (code->kind() == Code::CodeBlock) {
            writer.writeString("\n");
        }
        writer.writeString("\n");
    }
}

void File::writeTypes(const TypeContainer &types, CodeWriter &writer)
{
    for (auto& code : types) {
        code->write(writer);
        if (code->codeType() == Code::CodeType_Type || code->codeType() == Code::CodeType_Var ||
            code->codeType() == Code::CodeType_VarDef) {
          writer.writeString(";");
        }
        if (code->kind() == Code::CodeBlock) {
            writer.writeString("\n");
        }
        writer.writeString("\n");
    }
}

void File::writeIncludes(const IncludeContainer &includes, CodeWriter &writer)
{
    for (auto& inc : includes) {
        writer.writeString("#include ");
        writer.writeString(inc);
        writer.writeString("\n");
    }
}
