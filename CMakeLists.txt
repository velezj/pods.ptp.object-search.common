cmake_minimum_required(VERSION 2.6.0)

# pull in the pods macros. See cmake/pods.cmake for documentation
set(POD_NAME object-search.common)
include(cmake/pods.cmake)


add_definitions( -std=c++0x -Wall -fdiagnostics-show-option -fPIC -Wno-unused-local-typedefs)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")

option ( USE_PEDANTIC "Turn on -pendantic mode in gcc. This will spit out *lots* of warnings from lcm :-(, but hopefully none from the rest of the code" OFF)
if( USE_PEDANTIC )
    add_definitions( -pedantic )
endif (USE_PEDANTIC)



# the common library 
add_library( object-search.common SHARED
  src/context.cpp
  src/stat_counter_impl.cpp
  src/plots.cpp
  )
pods_use_pkg_config_packages(object-search.common boost-1.54.0 boost-1.54.0-chrono boost-1.54.0-system )
pods_install_libraries( object-search.common )
pods_install_headers(
    src/gcc_diagnostics.hpp
    src/stat_counter.hpp
    src/stat_counter.cpp
    src/context.hpp
    src/simple_svg_1.0.0.hpp
    src/plots.hpp
    DESTINATION
    object-search.common)
pods_install_pkg_config_file( object-search.common
    CFLAGS 
    LIBS -lobject-search.common
    REQUIRES boost-1.54.0 boost-1.54.0-chrono boost-1.54.0-system
    VERSION 0.0.1 )



add_subdirectory( test )
