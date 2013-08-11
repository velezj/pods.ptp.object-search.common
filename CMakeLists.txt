cmake_minimum_required(VERSION 2.6.0)

# pull in the pods macros. See cmake/pods.cmake for documentation
set(POD_NAME p2l-common)
include(cmake/pods.cmake)


# the common library (currently header only)
#add_library( p2l-common )
pods_install_headers(
    src/gcc_diagnostics.hpp
    DESTINATION
    p2l-common)
pods_install_pkg_config_file( p2l-common
    CFLAGS 
    LIBS
    REQUIRES
    VERSION 0.0.1 )
