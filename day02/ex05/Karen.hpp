#ifndef _KAREN_HPP_
#define _KAREN_HPP_
#include <string>
#include <iostream>

class Karen{
	public:
		Karen( void );
		void complain( std::string level );
		int find_good_number( std::string level );
	private :
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		std::string level[4];
};

#endif