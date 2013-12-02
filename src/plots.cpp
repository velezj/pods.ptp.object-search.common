
#include "plots.hpp"
#include "simple_svg_1.0.0.hpp"
#include <cmath>


namespace p2l { namespace common {


    //====================================================================

    void svg_plot( const std::string& filename,
		   const std::vector<double>& y_data,
		   const std::string& label)
    {

      double max_y = y_data[0];
      for( double y : y_data ) {
	if( y > max_y ) {
	  max_y = y;
	}
      }
      max_y += 0.01 * fabs(max_y);
      double scale_y = 500 * 1.0 / max_y;
      double scale_x = 500 * 1.0 / y_data.size();

      svg::Document doc( filename,
			 svg::Layout( svg::Dimensions( 500, 500 ),
				      svg::Layout::BottomLeft ) );


      svg::LineChart chart;
      std::vector<svg::Point> points;
      for( size_t i = 0; i < y_data.size(); ++i ) {
	points.push_back( svg::Point( scale_x * (double)i, 
				      scale_y * y_data[i] ) );
      }
      svg::Polyline line( svg::Stroke( 1.0, svg::Color::Blue ) );
      for( svg::Point p : points ) {
	line << p;
      }
      chart << line;
      doc << chart;
      if( label.empty() == false ) {
	doc << svg::Text( svg::Point( 0.0, 500 - 20.0 ), label,
			  svg::Fill( svg::Color::Black ) );
      }
      doc.save();
    }

    //====================================================================


  }
}
