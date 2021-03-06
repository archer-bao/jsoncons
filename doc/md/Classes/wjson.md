```c++
jsoncons::wjson

typedef basic_json<wchar_t,
                   JsonTraits = json_traits<wchar_t>,
                   Allocator = std::allocator<wchar_t>> wjson
```
The `wjson` class is an instantiation of the `basic_json` class template that uses `wchar_t` as the character type. The order of an object's name/value pairs is not preserved, they are sorted alphabetically by name. If you want to preserve the original insertion order, use [owjson](owjson) instead.

The `jsoncons` library will always rebind the supplied allocator from the template parameter to internal data structures.

### Header
```c++
#include <jsoncons/json.hpp>
```
### Interface

The interface is the same as [json](json), substituting wide character instantiations of classes - `std::wstring`, `std::wistream`, etc. - for narrow character ones.

### See also

- [owjson](owjson) constructs a wide character json value that preserves the original insertion order of an object's name/value pairs

- [json](json) constructs a narrow character json value that sorts name-value members alphabetically

- [ojson](ojson) constructs a narrow character json value that preserves the original insertion order of an object's name/value pairs

