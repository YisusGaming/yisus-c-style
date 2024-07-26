set(library_includes types.h types.hpp dynstr.h util.h)
set(library_sources string.c)

add_library(yisus STATIC ${library_sources})
target_include_directories(yisus PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

install(FILES ${library_includes} DESTINATION include/yisus)
install(TARGETS yisus DESTINATION lib/yisus)
