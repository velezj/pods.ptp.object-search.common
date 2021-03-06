
#if !defined( __P2L_COMMON_CONTEXT_HPP__ )
#define __P2L_COMMON_CONTEXT_HPP__


#include <string>
#include <fstream>
#include <sstream>
#include <boost/optional.hpp>
#include "stat_counter.hpp"
#include <boost/chrono.hpp>


//=================================================================

// Description:
// Pushes the current function name into the context stack
// #define P2L_COMMON_push_function_context() p2l::common::scoped_context_stack_push __p2l_common_function_context_stack_push( p2l::common::context_t( __FUNCTION__ ) )

#define P2L_COMMON_push_function_context() 


//=================================================================


namespace p2l { namespace common {


    // Description:
    // An identifier for a context
    struct context_t
    {
      std::string id;  
      context_t( const std::string& id )
	: id(id)
      {}
    };
    
    // Description:
    // "Chain" the current context by adding thes given one at end and
    // return this new chained context
    context_t chain_context( const context_t& new_context );
    
    // Description:
    // Switches the current context to the given one.
    // Returns the previuous context_t object, if any
    boost::optional<context_t> set_context( const boost::optional<context_t>& c );
    
    // Description:
    // Returns the current context, if any
    boost::optional<context_t> get_current_context();

    // Description:
    // Push the given context onto the context stack
    void push_context( const boost::optional<context_t>& c );
    
    // Description:
    // Pops the context stack
    void pop_context();
    
    // Description:
    // Returns a new filename prepended with the current context
    // and with the given name
    std::string context_filename( const std::string& name );

    // Description:
    // Returns a string identifier for the entire context stack
    std::string context_stack_id();
    
    // Description:
    // A scoped context switch.
    // When created, pushes the given context onto the stack
    // then pops the context stack at scope exit.
    class scoped_context_stack_push
    {
    public:
      boost::chrono::steady_clock::time_point start_time;
      scoped_context_stack_push( const boost::optional<context_t>& new_context )
      {
	start_time = boost::chrono::steady_clock::now();
	push_context( new_context );
      }
      virtual ~scoped_context_stack_push()
      {
	boost::chrono::steady_clock::time_point stop_time = 
	  boost::chrono::steady_clock::now();
	double seconds = ( stop_time - start_time ).count() * 
	  ( (double)boost::chrono::steady_clock::period::num /
	    boost::chrono::steady_clock::period::den );
	STAT_LVL( info, "profile.seconds", seconds );
	pop_context();
      }
    };
    
  }
}

#endif

