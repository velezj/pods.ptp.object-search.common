
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

// #define STAT( id, stat )					\
//   do { std::ostringstream oss;					\
//     oss << p2l::common::context_stack_id() << "/" << id;	\
//     p2l::common::log_stat( oss.str(), stat );			\
//   } while( false )
#define STAT(id, stat)


//=====================================================================

// Description:
// Logs the given stat, adding the current context stack identifier to 
// the given stat id.
// Include a level with the stats, which determines if the stat actually
// gets logged or not based on the globally set stat level threshold.

// #define STAT_LVL( lvl, id, stat )					\
//   do {									\
//     if( p2l::common::stat_level::lvl >=					\
// 	p2l::common::stat_level_threshold() ) {				\
//       std::ostringstream oss;						\
//       oss << p2l::common::context_stack_id() << "/" << id;		\
//       p2l::common::log_stat( oss.str(), stat );				\
//     }									\
//   } while( false )

#define STAT_LVL( lvl, id, stat )


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

    // Description:
    // Known stat levels
    enum stat_level {
      trace,
      debug,
      info,
      warning,
      error,
      fatal
    };

    // Description:
    // Returns the current stat level
    stat_level stat_level_threshold();
    
    // Description:
    // Sets the current stat level
    void set_stat_level_threshold( const stat_level& lvl );

  }
}

#include "stat_counter.cpp"

#endif

