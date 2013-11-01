
#include "stat_counter.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>
#include <boost/variant.hpp>

namespace p2l { namespace common {

    //====================================================================

    // Description:
    // The variant type for stats (from the defined macro in the header
    // of from the user)
    typedef __P2L_COMMON_stat_counter_possible_types__ variant_types_seq_t;
    typedef boost::make_variant_over< variant_types_seq_t >::type variant_t;

    //====================================================================

    // Description:
    // THe global map of stat ids to vector of logged stats
    typedef std::unordered_map< std::string, std::vector< variant_t > > stat_map_t;
    static stat_map_t _g_global_stat_map;

    //====================================================================

    template< typename T >
    log_stat( const std::string& id,
	      const T& stat )
    {
      // add a new entry for id if none previously added
      if( _g_global_stat_map.find( id ) == _g_global_stat_map.end() ) {
	_g_global_stat_map[ id ] = std::vector< variant_t >();
      }

      // add the stat to the end of the vector
      variant_t stat_v = stat;
      _g_global_stat_map[ id ].push_back( stat_v );
    }

    //====================================================================

    std::vector<std::string>
    known_stat_ids()
    {
      std::vector<std::string> ids;
      for( auto iter : _g_global_stat_map ) {
	ids.push_back( iter->first );
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
      for( auto iter : stats ) {
	os << (*iter);
	if( iter + 1 != stats.end() ) {
	  oss << ",";
	}
      }
      os << "]";
    }

    //====================================================================

    template< class Vec_T >
    class stat_collect_visitor
      : public boost::static_visitor<>
    {
    public:

      std::vector< Vec_T > _vec;
      stat_collect_visitor( std::vector< Vec_T >& v )
	: _vec( v )
      {}

      template< typename T >
      void operator( T& op ) {
	_vec.push_back( op );
      }
    };

    //====================================================================

    template< typename Vec_T >
    void collect_stats( const std::string& id ,
			std::vector< Vec_T >& vec )
    {
      if( _g_global_stat_map.find( id ) == _g_global_stat_map.end() ) {
	return;
      }
      
      std::vector<variant_t> stats = _g_global_stat_map[ id ];
      stat_collect_visitor<Vec_T> v(vec);
      std::for_each( stats.begin(), stats.end(),
		     boost::apply_visitor( v ) );
    }

    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    //====================================================================
    


  }
}