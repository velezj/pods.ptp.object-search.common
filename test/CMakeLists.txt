
add_executable( p2l-common-test-stat-counter
  test/test-stat-counter.cpp
)
pods_use_pkg_config_packages( p2l-common-test-stat-counter
  p2l-common
  boost-1.54.0
)
pods_install_executables( p2l-common-test-stat-counter )