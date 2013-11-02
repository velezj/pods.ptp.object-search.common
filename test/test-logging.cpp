
#define BOOST_LOG_DYN_LINK 1
#include <p2l-common/logging.hpp>
#include <iostream>

using namespace p2l;
using namespace p2l::common;


int main(int argc, char** argv )
{
  L_( trace ) << "A Default Trace";
  L_( debug ) << "A Default Debug";
  L_( info ) << "A Default Info";
  L_( warning ) << "A Default Warning";
  L_( error ) << "A Default Error";
  L_( fatal ) << "A Default Fatal";

  L_STAT( trace ) << "A Stat Trace";
  L_STAT( debug ) << "A Stat Debug";
  L_STAT( info ) << "A Stat Info";
  L_STAT( warning ) << "A Stat Warning";
  L_STAT( error ) << "A Stat Error";
  L_STAT( fatal ) << "A Stat Fatal";
  
}
