
#if !defined( __P2L_COMMON_logging_HPP__ )
#define __P2L_COMMON_logging_HPP__

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/common.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <boost/log/sources/severity_logger.hpp>


//=====================================================================

// Description:
// Logs to the default logger
#define L_( sev ) BOOST_LOG_SEV( p2l::common::default_logger::get(), sev )

// Description:
// Logs to the stat logger
#define L_STAT( sev ) BOOST_LOG_SEV( p2l::common::stat_logger::get(), sev )

//=====================================================================
//=====================================================================



namespace p2l { namespace common {

    //=====================================================================

    enum severity_level {
      trace,
      debug,
      info,
      warning,
      error,
      fatal
    };

    //=====================================================================

    // Description:
    // Several global loggers
    BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT( stat_logger, boost::log::sources::severity_logger_mt< severity_level > )
    BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT( default_logger, boost::log::sources::severity_logger_mt< severity_level > )



    //=====================================================================

    // Description:
    // Initialize the logging module
    void _init_logging();
    

    //=====================================================================

    // Description:
    // A class which is here just to create the logging
    class _logging_initializer_class_t
    {
    public:
      _logging_initializer_class_t() 
      {
	_init_logging();
      }
      ~_logging_initializer_class_t()
      {
      }
    };
    
    static _logging_initializer_class_t _g_logging_initializer_class;

  }
}

#endif

