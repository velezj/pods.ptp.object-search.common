
add_executable( object-search.common-test-stat-counter
  test-stat-counter.cpp
)
pods_use_pkg_config_packages( object-search.common-test-stat-counter
  object-search.common
)
pods_install_executables( object-search.common-test-stat-counter )


#add_executable( object-search.common-test-logging
#  test-logging.cpp
#)
#pods_use_pkg_config_packages( object-search.common-test-logging
#  object-search.common boost-1.54.0  boost-1.54.0-system boost-1.54.0-log
#)
#pods_install_executables( object-search.common-test-logging )



add_executable( object-search.common-test-stat-context
  test-stat-context.cpp
)
pods_use_pkg_config_packages( object-search.common-test-stat-context
  object-search.common
)
pods_install_executables( object-search.common-test-stat-context )
