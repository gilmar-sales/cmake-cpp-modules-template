module;

#include <print>

export module HelloWorld;

namespace hello {

export void world() { std::println("Hello {}", "World!"); }

} // namespace hello
