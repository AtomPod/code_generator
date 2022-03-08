# code_generator
code_genrator 是一个由C++编写的C/C++语言代码生成器，支持struct、enum、函数、变量等等创建支持。使用对象方式进行创建，复用代码片段支持。

# C++支持
- ### C++11

# 外部库
- ### fmtlib https://github.com/fmtlib/fmt

# 代码示例
## 1. struct 结构体创建
### 代码
```C++11
StringCodeWriter writer;

auto person = struct_({
	field_("age", type_("int")),
	field_("name", array_(type_("char"), 20))
}, "person");

person->write(writer);
std::cout << writer.str() << '\n';
```
### 生成输出
```
struct person {
  int age;
  char name[20];
}
```
## 2. function 函数创建
### 代码
```C++11
StringCodeWriter writer;

auto fn = func_("print", type_("void"), { argument_("value", type_("int")) },
	{
		var_("tmp", type_("int"))->definition()->assign($("value")),
		$("std::cout << tmp << '\\n'")
	});

fn->write(writer);
std::cout << writer.str() << '\n';
```
### 生成输出
```
void print(int value) {
  int tmp = value;
  std::cout << tmp << '\n'
}
```
## 3. 结构体+编解码
### 代码
```C++11
FunctionRef CreateEncodeFunc(StructRef stc, const char *fnName) {
    const String thiz = "thiz";
    auto buffer = var_("buffer", type_("QByteArray"));

    auto personFields = stc->fields();
    Function::CodeContainer container;
    container.push_back(buffer->definition());
    container.push_back($("QBuffer$srbuffer(&{});", buffer->name()));
    container.push_back($("rbuffer.open(QBuffer::ReadWrite);"));
    container.push_back($("QDataStream$sstream(&rbuffer);"));
    for (const auto &field : personFields) {
        FieldRef nfield = std::reinterpret_pointer_cast<Field>(field);
        container.push_back($("stream$s<<$s{}->{};", thiz, nfield->name()));
        container.push_back(
        if_($("stream.status() != QDataStream::Ok"), {
            return_("QByteArray()"),
        }));
    }
    container.push_back(return_(buffer->name()));
    return func_(fnName, type_("QByteArray"), { argument_(thiz, ptr_(stc->declare())) }, container);
}

FunctionRef CreateDecodeFunc(StructRef stc, const char *fnName) {
    const String thiz = "thiz";
    auto buffer = var_("buffer", type_("QByteArray"));

    auto personFields = stc->fields();
    Function::CodeContainer decodeContainer;
    decodeContainer.push_back($("QDataStream$sstream({});", buffer->name()));
    for (const auto &field : personFields) {
        FieldRef nfield = std::reinterpret_pointer_cast<Field>(field);
        decodeContainer.push_back($("stream$s>>$s{}->{};", thiz, nfield->name()));
        decodeContainer.push_back(
        if_($("stream.status() != QDataStream::Ok"), {
            return_(""),
        }));
    }

    return func_(fnName, BuiltinType::Void, { argument_(thiz, ptr_(stc->declare())),
                                              argument_(buffer->name(), type_("QByteArray")) },
                        decodeContainer);
}

void ParseStruct() {
    StringCodeWriter writer;

    StructRef person = struct_({
        field_("age", BuiltinType::Int),
        field_("name", ptr_(BuiltinType::Char)),
        field_("salary", BuiltinType::Float),
        field_("address", ptr_(BuiltinType::Char))
    }, "person");

    auto encode = CreateEncodeFunc(person, "person_encode");
    auto decode = CreateDecodeFunc(person, "person_decode");

    person->write(writer);
    writer.writeString("\n");
    encode->write(writer);
    writer.writeString("\n");
    decode->write(writer);
    std::cout << writer.str() << '\n';
}
```
### 生成输出
```
struct person {
  int age;
  char* name;
  float salary;
  char* address;
}
QByteArray person_encode(struct person* thiz) {
  QByteArray buffer;
  QBuffer rbuffer(&buffer);
  rbuffer.open(QBuffer::ReadWrite);
  QDataStream stream(&rbuffer);
  stream << thiz->age;

  if (stream.status() != QDataStream::Ok) {
    return QByteArray();
  }
  stream << thiz->name;

  if (stream.status() != QDataStream::Ok) {
    return QByteArray();
  }
  stream << thiz->salary;

  if (stream.status() != QDataStream::Ok) {
    return QByteArray();
  }
  stream << thiz->address;

  if (stream.status() != QDataStream::Ok) {
    return QByteArray();
  }
  return buffer;
}
void person_decode(struct person* thiz, QByteArray buffer) {
  QDataStream stream(buffer);
  stream >> thiz->age;

  if (stream.status() != QDataStream::Ok) {
    return ;
  }
  stream >> thiz->name;

  if (stream.status() != QDataStream::Ok) {
    return ;
  }
  stream >> thiz->salary;

  if (stream.status() != QDataStream::Ok) {
    return ;
  }
  stream >> thiz->address;

  if (stream.status() != QDataStream::Ok) {
    return ;
  }
}
```

# 功能支持
- [x] 代码片段复用
- [x] 文件写入支持
- [x] 类函数支持
- [ ] 构造函数支持
- [ ] 模板支持