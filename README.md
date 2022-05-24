# cpp-cppcli-dotnet-interop

C++ - C++/CLI - DotNet 6 interoperations

## Projects

* `CSharpApp` is a dll which contains C# implementation for a library that will be used by unmanaged C++
* `CoreClassLib` is a dll wrapper written in C++/CLI for `CSharpApp` which creates the adaption with the unmanaged C++ code
* `client_app` is an unmanaged C++ application (executable) which takes use of the `CSharpApp` through the use of `CoreClassLib`

## References

[Cpp Dot Net Data Types Marshaling](https://docs.microsoft.com/en-us/cpp/dotnet/overview-of-marshaling-in-cpp?view=msvc-170)
