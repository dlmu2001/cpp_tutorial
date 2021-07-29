cmake_minimum_required(VERSION 3.5)
set(CMAKE_TOOLCHAIN_FILE ./toolchain.cmake)
PROJECT(hello)

add_compile_options(-Wno-unused-variable -Wno-unused-parameter
-Wall -Wextra -Wpointer-arith -Wvla -Wwrite-strings -Wno-error=extra -Wno-error=unused-function
-Wno-error=deprecated-declarations -Wno-error=sign-compare -Wno-error=strict-aliasing -Wno-error=type-limits
-Wno-undef -Wno-error=uninitialized -Wno-uninitialized -Wno-error=unused-result)

set(C_WARNINGS "-Waggregate-return -Wnested-externs -Wold-style-definition -Wstrict-prototypes")
set(CXX_WARNINGS "-Wno-reorder -Wno-missing-field-initializers")

MESSAGE(STATUS "CMAKE_C_FLAGS_DEBUG= " ${CMAKE_C_FLAGS_DEBUG})
MESSAGE(STATUS "CMAKE_C_FLAGS_RELEASE= " ${CMAKE_C_FLAGS_RELEASE})
MESSAGE(STATUS "CMAKE_CXX_FLAGS_DEBUG= " ${CMAKE_CXX_FLAGS_DEBUG})
MESSAGE(STATUS "CMAKE_CXX_FLAGS_RELEASE= " ${CMAKE_CXX_FLAGS_RELEASE})
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  ${WARNINGS} ${C_WARNINGS} -funroll-loops -fPIC -fsigned-char -funwind-tables -fexceptions -pthread -pg" )
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -pipe")

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  ${WARNINGS} ${CXX_WARNINGS}  -funroll-loops -fPIC -fsigned-char -funwind-tables -fexceptions -fpermissive -pthread" )
SET(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG} "-O0 -pipe")

ADD_SUBDIRECTORY(src bin)
