
HEADERS += \
  $$PWD/include/code_generator/Argument.hpp \
  $$PWD/include/code_generator/Array.hpp \
  $$PWD/include/code_generator/Code.hpp \
  $$PWD/include/code_generator/CodeBlock.hpp \
  $$PWD/include/code_generator/CodeGenerator.hpp \
  $$PWD/include/code_generator/CodeWriter.hpp \
  $$PWD/include/code_generator/Common.hpp \
  $$PWD/include/code_generator/Enum.hpp \
  $$PWD/include/code_generator/Evaluate.hpp \
  $$PWD/include/code_generator/File.hpp \
  $$PWD/include/code_generator/FlowControl.hpp \
  $$PWD/include/code_generator/Function.hpp \
  $$PWD/include/code_generator/FunctionDeclare.hpp \
  $$PWD/include/code_generator/HeaderFile.hpp \
  $$PWD/include/code_generator/IdGenerator.hpp \
  $$PWD/include/code_generator/Lit.hpp \
  $$PWD/include/code_generator/Macro.hpp \
  $$PWD/include/code_generator/NamedType.hpp \
  $$PWD/include/code_generator/Ptr.hpp \
  $$PWD/include/code_generator/RawCode.hpp \
  $$PWD/include/code_generator/Ref.hpp \
  $$PWD/include/code_generator/SimpleType.hpp \
  $$PWD/include/code_generator/StringCodeWriter.hpp \
  $$PWD/include/code_generator/StructOrUnion.hpp \
  $$PWD/include/code_generator/StructorType.hpp \
  $$PWD/include/code_generator/Type.hpp \
  $$PWD/include/code_generator/TypeDefinition.hpp \
  $$PWD/include/code_generator/TypeModifier.hpp \
  $$PWD/include/code_generator/Typedef.hpp \
  $$PWD/include/code_generator/Types.hpp \
  $$PWD/include/code_generator/Var.hpp \
  $$PWD/include/code_generator/While.hpp \
  $$PWD/include/code_generator/Return.hpp

LIBS += -L$$PWD/lib code_generator.lib
INCLUDEPATH += $$PWD/include

include($$PWD/libs/fmt/libfmt.pri)
