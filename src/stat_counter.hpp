
#if !defined( __P2L_COMMON_stat_counter_HPP__ )
#define __P2L_COMMON_stat_counter_HPP__

#include <iosfwd>
#include <boost/mpl/vector.hpp>
#include <vector>

//=====================================================================

// Description:
// The __P2L_COMMON_stat_counter_possible_types__
// defines an MPL sequence of the possible types for statistics.
// By default we only handle double, but the user may define this
// macro *before* including stat_counter.hpp to use their own 
// sequence of potential stat types.
#if !defined( __P2L_COMMON_stat_counter_possible_types__ )
#define __P2L_COMMON_stat_counter_possible_types__ boost::mpl::vector< double, std::string >
#endif

//=====================================================================

// Description:
// Logs the given stat, adding the current context stack identifier to 
// the given stat id
#define STAT( id, stat )			\
  do { std::ostringstream oss;			\
    oss << context_stack_id() << "/" << id;	\
    log_stat( oss.str(), stat );		\
  } while( false )


//=====================================================================


namespace p2l { namespace common {


    // Description:
    // Add a given stat with a given name to the
    // stats log
    template< typename T >
    void log_stat( const std::string& id,
		   const T& stat );

    // Description:
    // Prints out the stats for a given id
    void print_stats( const std::string& id,
		      std::ostream& os );

    // Description:
    // "Collects" the stats for a given id into the given
    // vector
    template< typename T >
    void collect_stats( const std::string& id,
			T& vec );
    
    // Description:
    // Returns a list of all known stat ids
    std::vector<std::string>
    known_stat_ids();

    // Description:
    // Prints out all stats to the given stream
    void print_all_stats( std::ostream& os );

  }
}

#include "stat_counter.cpp"

#endif

