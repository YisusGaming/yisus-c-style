set(library_includes types.h)

add_library(yisus STATIC)
target_include_directories(yis PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

install(FILES ${library_includes} DESTINATION include/yisus)
