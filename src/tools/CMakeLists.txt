set(cproj_sources cproj.c)

add_executable(cproj ${cproj_sources})
target_include_directories(cproj PUBLIC "../")
target_link_libraries(cproj yisus)

install(TARGETS cproj DESTINATION bin)
