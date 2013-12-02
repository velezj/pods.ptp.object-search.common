
#include "stat_counter.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <boost/variant.hpp>




namespace p2l { namespace common {

    stat_map_t _g_global_stat_map;

    static stat_level _g_stat_level_threshold = stat_level::info;

    //====================================================================

    std::vector<std::string>
    known_stat_ids()
    {
      std::vector<std::string> ids;
      for( auto iter : _g_global_stat_map ) {
	ids.push_back( iter.first );
      }
      return ids;
    }

    //====================================================================

    void print_stats( const std::string& id,
		      std::ostream& os)
    {
      if( _g_global_stat_map.find( id ) == _g_global_stat_map.end() ) {
	return;
      }

      std::vector<variant_t> stats = _g_global_stat_map[ id ];
      os << "[";
      for( size_t i = 0; i < stats.size(); ++i) {
	os << stats[i];
	if( i + 1 < stats.size() ) {
	  os << ",";
	}
      }
      os << "]";
    }

    //====================================================================

    void print_all_stats( std::ostream& os )
    {
      os << "{";
      os << "\"stats\" : {" << std::endl;
      for( auto id : known_stat_ids() ) {
	os << "\"" << id << "\" : ";
	print_stats( id, os );
	os << ",";
	os << std::endl;
      }
      os << "}}";
    }

    //====================================================================

    stat_level stat_level_threshold()
    {
      return _g_stat_level_threshold;
    }

    //====================================================================

    void set_stat_level_threshold( const stat_level& lvl )
    {
      _g_stat_level_threshold = lvl;
    }

    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================


  }
}

