cmake_minimum_required(VERSION 3.10)

project(YisusCStyle VERSION 3.0.0 LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src) # library + includes sources and installs
add_subdirectory(src/tools) # CLI tools + installs
