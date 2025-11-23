set(t_string_sources t_string.c)

add_executable(t_string ${t_string_sources})
target_link_libraries(t_string PRIVATE yisus)
