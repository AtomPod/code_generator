/**
 * @file File.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef FILE_HPP
#define FILE_HPP

#include "CodeGenerator.hpp"
#include <vector>
#include <set>

class File
{
public:
    typedef std::set<String> IncludeContainer;
    typedef std::vector<CodeRef> CodeContainer;
    typedef std::vector<TypeRef> TypeContainer;

public:
    File();

public:
    int write(CodeWriter &writer);

public:
    /**
     * @brief includes 获取导入头文件
     * @return
     */
    IncludeContainer includes() const;

    /**
     * @brief addInclude 添加头文件路径
     * @param path
     */
    void addInclude(const String &path);

    /**
     * @brief numOfIncludes
     * @return
     */
    size_t numOfInclude() const { return m_includes.size(); }

    /**
     * @brief headers 获取文件头部
     * @return
     */
    CodeContainer headers() const;

    /**
     * @brief addHeader 添加头部代码
     * @param code
     */
    void addHeader(const CodeRef &code);

    /**
     * @brief numOfHeader
     * @return
     */
    size_t numOfHeader() const { return m_headers.size(); }

    /**
     * @brief declares 获取声明信息
     * @return
     */
    TypeContainer declares() const;

    /**
     * @brief addDeclare 添加声明信息
     * @param declare
     */
    void addDeclare(const TypeRef declare);

    /**
     * @brief numOfDeclare
     * @return
     */
    size_t numOfDeclare() const { return m_declares.size(); }

    /**
     * @brief definitions 获取定义信息
     * @return
     */
    CodeContainer definitions() const;

    /**
     * @brief addDefinition 添加定义
     * @param code
     */
    void addDefinition(const CodeRef &code);

    /**
     * @brief numOfDefinition
     * @return
     */
    size_t numOfDefinition() const { return m_definitions.size(); }

    /**
     * @brief globalVars 获取全局变量
     * @return
     */
    CodeContainer globalVars() const;

    /**
     * @brief addGlobalVar 添加全局变量
     * @param code
     */
    void addGlobalVar(const CodeRef &code);

    /**
     * @brief numOfGlobalVar
     * @return
     */
    size_t numOfGlobalVar() const { return m_globalVars.size(); }

    /**
     * @brief codes 获取其他代码部分
     * @return
     */
    CodeContainer codes() const;

    /**
     * @brief addCode
     * @param code
     */
    void addCode(const CodeRef &code);

    /**
     * @brief numOfCode
     * @return
     */
    size_t numOfCode() const { return m_codes.size(); }
protected:
    void writeCodes(const CodeContainer &codes, CodeWriter &writer);
    void writeTypes(const TypeContainer &types, CodeWriter &writer);
    void writeIncludes(const IncludeContainer &includes, CodeWriter &writer);

private:
    CodeContainer m_headers;
    IncludeContainer m_includes;
    TypeContainer m_declares;
    CodeContainer m_definitions;
    CodeContainer m_globalVars;
    CodeContainer m_codes;
};

#endif // FILE_HPP
