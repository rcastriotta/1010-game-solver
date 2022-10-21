# <small>nlohmann::</small>json_sax

```cpp
template<typename BasicJsonType>
struct json_sax;
```

This class describes the SAX interface used by [sax_parse](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/basic_json/sax_parse.md). Each function is called in
different situations while the input is parsed. The boolean return value informs the parser whether to continue
processing the input.

## Template parameters

`BasicJsonType`
:   a specialization of [`basic_json`](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/basic_json/index.md)

## Member types

- [**number_integer_t**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/basic_json/number_integer_t.md) - `BasicJsonType`'s type for numbers (integer)
- [**number_unsigned_t**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/basic_json/number_unsigned_t.md) - `BasicJsonType`'s  type for numbers (unsigned)
- [**number_float_t**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/basic_json/number_float_t.md) - `BasicJsonType`'s type for numbers (floating-point)
- [**string_t**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/basic_json/string_t.md) - `BasicJsonType`'s type for strings
- [**binary_t**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/basic_json/binary_t.md) - `BasicJsonType`'s type for binary arrays

## Member functions

- [**binary**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/binary.md) (_virtual_) - a binary value was read
- [**boolean**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/boolean.md) (_virtual_) - a boolean value was read
- [**end_array**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/end_array.md) (_virtual_) - the end of an array was read
- [**end_object**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/end_object.md) (_virtual_) - the end of an object was read
- [**key**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/key.md) (_virtual_) - an object key was read
- [**null**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/null.md) (_virtual_) - a null value was read
- [**number_float**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/number_float.md) (_virtual_) - a floating-point number was read
- [**number_integer**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/number_integer.md) (_virtual_) - an integer number was read
- [**number_unsigned**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/number_unsigned.md) (_virtual_) - an unsigned integer number was read
- [**parse_error**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/parse_error.md) (_virtual_) - a parse error occurred
- [**start_array**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/start_array.md) (_virtual_) - the beginning of an array was read
- [**start_object**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/start_object.md) (_virtual_) - the beginning of an object was read
- [**string**](Desktop/1010-ai-master/lib/json/doc/mkdocs/docs/api/json_sax/string.md) (_virtual_) - a string value was read

## Version history

- Added in version 3.2.0.
- Support for binary values (`binary_t`, `binary`) added in version 3.8.0.
