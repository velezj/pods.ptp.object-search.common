
add_executable( p2l-common-test-stat-counter
  test-stat-counter.cpp
)
pods_use_pkg_config_packages( p2l-common-test-stat-counter
  p2l-common
)
pods_install_executables( p2l-common-test-stat-counter )


#add_executable( p2l-common-test-logging
#  test-logging.cpp
#)
#pods_use_pkg_config_packages( p2l-common-test-logging
#  p2l-common boost-1.54.0  boost-1.54.0-system boost-1.54.0-log
#)
#pods_install_executables( p2l-common-test-logging )



add_executable( p2l-common-test-stat-context
  test-stat-context.cpp
)
pods_use_pkg_config_packages( p2l-common-test-stat-context
  p2l-common
)
pods_install_executables( p2l-common-test-stat-context )
