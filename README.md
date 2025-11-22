<div align="center">
    <h1>Yisus C Style</h1>
    
    The way I write my C code.
</div>

### What is this?
In short, it's a simple library that provides some utilities like macros and functions.
More over, it's the way I use to write and format my C code.

2025 edit: So, this thing is very old. I still keep it around because I usually use cproj. Yeeep...

### Project Features
* A Dynamic String implementation.
* Custom type definitions.
* Useful macros.
* A CLI tool that generates _"c projects"_ (it generates a directory with .clang-format and CMakeLists.txt files inside, and an empty `src` directory).

### Using this
If you've already [compiled the project](#building), then...

If all you want is to use the utilities in the library, then all you have to do is link your program with the library. Linking is only needed when using the String implementation. The rest of the features can be used with just the header files.

If you also want the code formatting and project structure, you can use the `cproj` tool to generate this for you.


### Building
> <!> The project hasn't been tested in other systems, and it might be Windows only for now.

To build the project all you'll need is:
* A C compiler (clang was used for this project).
* CMake (at least version 3.10). 

First you'll configure the project. For example, here's a release configuration with Unix Makefiles (it should work fine with other generators):
```sh
cmake -S . -B build -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
```
After that, you can go ahead and build the project with this command:
```sh
cmake --build build

# some generators may need a command like this to build in release:
# cmake --build build --config Release
```

It should just build sucessfully. Once it's done, you can install it in some directory with something like this:
```
cmake --install build --prefix /path/to/folder
```
This will install all the includes in `/path/to/folder/include/yisus`, the tools in `/path/to/folder/bin/`, and the library in `/path/to/folder/lib/yisus`.

# License
Licensed under the MIT License.

See [LICENSE](LICENSE) for details.
