cmake_minimum_required(VERSION 2.6.0)

# pull in the pods macros. See cmake/pods.cmake for documentation
set(POD_NAME p2l-common)
include(cmake/pods.cmake)


add_definitions( -std=c++0x -Wall -fdiagnostics-show-option )
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")

option ( USE_PEDANTIC "Turn on -pendantic mode in gcc. This will spit out *lots* of warnings from lcm :-(, but hopefully none from the rest of the code" OFF)
if( USE_PEDANTIC )
    add_definitions( -pedantic )
endif (USE_PEDANTIC)



# the common library 
add_library( p2l-common SHARED
  src/context.cpp
  src/stat_counter_impl.cpp
  )
pods_use_pkg_config_packages(p2l-common boost-1.54.0 boost-1.54.0-log )
pods_install_libraries( p2l-common )
pods_install_headers(
    src/gcc_diagnostics.hpp
    src/stat_counter.hpp
    src/stat_counter.cpp
    src/context.hpp
    DESTINATION
    p2l-common)
pods_install_pkg_config_file( p2l-common
    CFLAGS 
    LIBS -lp2l-common
    REQUIRES boost-1.54.0
    VERSION 0.0.1 )



add_subdirectory( test )
