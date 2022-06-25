#ifndef _CAST_HPP_
#define _CAST_HPP_

class Base {
	public :
		virtual ~Base( void ){};
};

class A : public Base{
	public :
		A( void ){n = "A";};
		std::string n;
};

class B : public Base{
	public :
		B( void ){n = "B";};
		std::string n;
};

class C : public Base{
	public :
		C( void ){n = "C";};
		std::string n;
};


#endif
