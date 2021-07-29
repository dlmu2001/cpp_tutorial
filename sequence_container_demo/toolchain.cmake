## related env var : CROSS_COMPILE,TOOLCHAIN_ROOT,SYSROOT_PATH,TOOLCHAIN
## CMAKE var: TOOLCHAIN_PREFIX
if(DEFINED ENV{CROSS_COMPILE})
    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_VERSION 1)
    set(CMAKE_CROSSCOMPILING 1)

    if(DEFINED ENV{TOOLCHAIN_ROOT})
    	set(CMAKE_SYSROOT $ENV{TOOLCHAIN_ROOT})
    endif()
    if(DEFINED ENV{SYSROOT_PATH})
        set(CMAKE_FIND_ROOT_PATH $ENV{SYSROOT_PATH})
    endif()
    if(NOT DEFINED TOOLCHAIN_PREFIX)
        set(TOOLCHAIN_PREFIX arm-linux-gnueabihf)
    endif()

    # Force the compilers
    # Skip the platform compiler checks for cross compiling
    SET(CMAKE_C_COMPILER_FORCED TRUE)
    SET(CMAKE_CXX_COMPILER_FORCED TRUE)    
    #set(CMAKE_CXX_COMPILER_WORKS TRUE)
    #set(CMAKE_C_COMPILER_WORKS TRUE)

    if(NOT DEFINED ENV{TOOLCHAIN}) 
        message(FATAL_ERROR, "TOOLCHAIN DIR not configured")
	return()
    else()
        list(APPEND CMAKE_PROGRAM_PATH $ENV{TOOLCHAIN})
    endif()
    
    if(NOT DEFINED CMAKE_C_COMPILER)
        find_program(CMAKE_C_COMPILER NAMES ${TOOLCHAIN_PREFIX}-gcc PATHS $ENV{TOOLCHAIN})
        message("find ${TOOLCHAIN_PREFIX}-gcc result ${CMAKE_C_COMPILER}")
    endif()
    if(NOT DEFINED CMAKE_CXX_COMPILER)
        find_program(CMAKE_CXX_COMPILER NAMES ${TOOLCHAIN_PREFIX}-g++ PATHS $ENV{TOOLCHAIN})
        message("find ${TOOLCHAIN_PREFIX}-g++ result ${CMAKE_CXX_COMPILER}")
    endif()
else()
    set(CMAKE_C_COMPILER /usr/bin/gcc)
    set(CMAKE_CXX_COMPILER /usr/bin/g++)
endif()




