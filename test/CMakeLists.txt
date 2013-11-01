
add_executable( p2l-common-test-stat-counter
  test-stat-counter.cpp
)
pods_use_pkg_config_packages( p2l-common-test-stat-counter
  p2l-common
)
pods_install_executables( p2l-common-test-stat-counter )