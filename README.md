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

auto fn = func_("print",
	type_("void"),
	{
		argument_("value", type_("int")),
	},
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

# 功能支持
- [x] 代码片段复用
- [x] 文件写入支持
- [x] 类函数支持
- [ ] 构造函数支持
- [ ] 模板支持