set(cproj_sources cproj.c)

add_executable(cproj ${cproj_sources})
target_include_directories(cproj PUBLIC "../")

install(TARGETS cproj DESTINATION bin)
