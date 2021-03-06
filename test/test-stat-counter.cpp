
#define __P2L_COMMON_stat_counter_possible_types__ boost::mpl::vector< std::string, double >
#include <object-search.common/stat_counter.hpp>
#include <iostream>

using namespace p2l;
using namespace p2l::common;

int main( int argc, char** argv )
{

  // log some stats with names
  log_stat( "stat.a", 1.0 );
  log_stat( "stat.a", 1.2 );
  log_stat( "stat.a", 1.4 );
  log_stat( "stat.b", 3.2 );
  log_stat( "stat.c", "hey there!" );
  log_stat( "stat.c", "hi hi" );
  
  // print out the name of known stats
  std::vector< std::string > ids = known_stat_ids();
  std::cout << "known stats: ";
  for( auto iter : ids ) {
    std::cout << iter << ", ";
  }
  std::cout << std::endl;

  // print out hte stats
  std::cout << "stat.a = ";
  print_stats( "stat.a", std::cout );
  std::cout << std::endl;

  
  // collect stat.b
  std::vector<double> stat_b;
  collect_stats( "stat.b", stat_b );
  std::cout << "stat.b (collected) = ";
  for( auto iter : stat_b ) {
    std::cout << iter << ",";
  }
  std::cout << std::endl;

  // collect stat.c
  std::vector<std::string> stat_c;
  collect_stats( "stat.c", stat_c );
  std::cout << "stat.c (collected) = ";
  for( auto iter : stat_c ) {
    std::cout << iter << ",";
  }
  std::cout << std::endl;
}
