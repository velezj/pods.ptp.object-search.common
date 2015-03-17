
#include <object-search.common/stat_counter.hpp>
#include <object-search.common/context.hpp>
#include <iostream>

using namespace p2l;
using namespace p2l::common;

int foo()
{
  P2L_COMMON_push_function_context();
  
  STAT( "a", 1.1 );
}

int bar()
{
  P2L_COMMON_push_function_context();
  
  STAT( "b", 2.1 );
}

int baz()
{
  P2L_COMMON_push_function_context();

  STAT( "a", 3.2 );
  foo();
  bar();
}

int bur()
{
  P2L_COMMON_push_function_context();
  baz();
}


int main(int argc, char** argv )
{
  P2L_COMMON_push_function_context();
  
  foo();
  bar();
  baz();
  bur();
  
  print_all_stats( std::cout );
  std::cout << std::endl;
}
