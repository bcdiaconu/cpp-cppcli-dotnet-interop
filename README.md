# cpp-cppcli-dotnet-interop

C++ - C++/CLI - DotNet 6 interoperations

## Projects

* `CSharpApp` is a dll which contains C# implementation for a library that will be used by unmanaged C++
* `CppCliWrapper` is a dll wrapper written in C++/CLI for `CSharpApp` which creates the adaption with the unmanaged C++ code
* `client_app` is an unmanaged C++ application (executable) which takes use of the `CSharpApp` through the use of `CppCliWrapper`

## Configuration

### CppCliWrapper

In order to generate the `CppCliWrapper.dll` and `CppCliWrapper.lib` files, `DLL_EXPORT` constant should be defined into `Preprocessor Definitions` for all configurations:

1. `CppCliWrapper` project properties
1. `C/C++`/`Preprocessor`
1. Select `All Configurations` and `All Plaforms` at the top
1. In `Preprocessor Definitions` edit and append `DLL_EXPORT` to `<different options>`; it wil result `<different options>; DLL_EXPORT`
1. Press `OK` and `OK` to close all dialogs

### client_app

To find the necessary namespaces and classes, references to `CppCliWrapper` should be added to `client_app`:

1. `client_app` project properties
1. Select `All Configurations` and `All Plaforms` at the top
2. Goto `VC++ Directories`
3. In `Include Directories` append `..\CppCliWrapper`
4. Goto `Linker`/`Input`
5. In `Additional Dependencies` append `CppCliWrapper.lib` at the end of the list

## References

[Cpp Dot Net Data Types Marshaling](https://docs.microsoft.com/en-us/cpp/dotnet/overview-of-marshaling-in-cpp?view=msvc-170)
