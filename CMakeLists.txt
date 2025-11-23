cmake_minimum_required(VERSION 3.10)

project(YisusCStyle VERSION 1.1.0 LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src) # library + includes sources and installs
add_subdirectory(src/tools) # CLI tools + installs

if(BUILD_TESTS)
    message("-- Building project tests")
    add_subdirectory(tests)
endif()
