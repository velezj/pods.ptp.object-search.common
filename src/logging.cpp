
#include "logging.hpp"
#include <fstream>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sinks.hpp>

namespace p2l { namespace common {

    //=====================================================================

    void _init_logging()
    {
      boost::log::add_common_attributes();
      boost::log::core::get()->set_filter
	(
	 boost::log::trivial::severity >= boost::log::trivial::trace
	 );
   
      typedef boost::log::sinks::synchronous_sink< boost::log::sinks::text_ostream_backend > text_sink;

      // the file sink for hte default logger
      boost::shared_ptr< text_sink > default_sink = boost::make_shared< text_sink >();
      default_sink->locked_backend()->add_stream
	( boost::make_shared< std::ofstream >( "default_log.log" ) );
      boost::log::core::get()->add_sink( default_sink );

      // the file sink for hte stat logger
      boost::shared_ptr< text_sink > stat_sink = boost::make_shared< text_sink >();
      stat_sink->locked_backend()->add_stream
	( boost::make_shared< std::ofstream >( "stat_log.log" ) );
      boost::log::core::get()->add_sink( stat_sink );
    }

    //=====================================================================
    //=====================================================================
    //=====================================================================
    //=====================================================================
    //=====================================================================
    //=====================================================================
    //=====================================================================
    //=====================================================================
    //=====================================================================
    //=====================================================================
    //=====================================================================
    

  }
}
