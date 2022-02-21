/**
 * @file FlowControl.hpp
 * @author huangjian
 * @date 2022-02-21
 * @version 1.0
 * @copyright huangjian
 **/
#ifndef FLOWCONTROL_H
#define FLOWCONTROL_H

#include "Code.hpp"
#include "CodeBlock.hpp"
#include <vector>

class FlowControl;
typedef RefObject<FlowControl> FlowControlRef;

class FlowControl : public CodeBlock
{
  public:
    static const uint16_t ID;

  public:
    static FlowControlRef create(const String &name,
                                 const CodeRef condition,
                                 const CodeContainer &codeContainer);

  public:
    FlowControl(const String &name);
    FlowControl(const String &name,
                const CodeRef condition,
                const CodeContainer &codeContainer);

  public:
    virtual String toString() override;
    virtual CodeType codeType() const override { return CodeType_Conditaion; }
    uint16_t id() const override { return ID; }

  public:
    virtual int write(CodeWriter &writer) override;

  public:
    String name() const;
    void setName(const String &name);

    CodeRef condition() const;
    void setCondition(const CodeRef &condition);

  protected:
    FlowControlRef elseFlowControl() const;
    void setElseFlowControl(const FlowControlRef &elseFlowControl);

    FlowControlRef mainFlowControl() const;
    void setMainFlowControl(const FlowControlRef &mainFlowControl);

  private:
    FlowControlRef m_mainFlowControl;
    FlowControlRef m_elseFlowControl;
    CodeRef m_condition;
    String m_name;
};


class If;
typedef RefObject<If> IfRef;

class Else;
typedef RefObject<Else> ElseRef;

class ElseIf;
typedef RefObject<ElseIf> ElseIfRef;

class Else : public FlowControl {
    friend class ElseIf;
    friend class If;
  public:
    static const uint16_t ID;

  public:
    Else();
    Else(const CodeContainer &codeContainer);

    FlowControlRef endIf();
  public:
    uint16_t id() const override { return ID; }
};

class ElseIf : public FlowControl {
    friend class If;
  public:
    static const uint16_t ID;

  public:
    ElseIf();
    ElseIf(CodeRef condition,
       const CodeContainer &codeContainer);

  public:
    ElseRef elsE(const CodeContainer &codeContainer);

    ElseIfRef elseIF(CodeRef condition,
                    const CodeContainer &codeContainer);

    FlowControlRef endIf();

  public:
    uint16_t id() const override { return ID; }
};

/**
 * @brief The If class
 */
class If : public FlowControl, public EnableSharedRefObject<If> {
  public:
    static const uint16_t ID;

  public:
    static IfRef create(CodeRef condition = nullptr,
                        const CodeContainer &codeContainer = CodeContainer());

  public:
    If();
    If(CodeRef condition,
       const CodeContainer &codeContainer);

  public:
    ElseRef elsE(const CodeContainer &codeContainer);

    ElseIfRef elseIF(CodeRef condition,
                    const CodeContainer &codeContainer);

  public:
    uint16_t id() const override { return ID; }
};


inline IfRef if_(CodeRef condition = nullptr,
                 const If::CodeContainer &codeContainer = If::CodeContainer()) {
    return If::create(condition, codeContainer);
}

#endif // FLOWCONTROL_H
