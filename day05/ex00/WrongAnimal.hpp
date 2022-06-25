#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal &src );
		virtual ~WrongAnimal( void );
		std::string	getType( void ) const ;
		virtual void makeSound( void ) const;
		WrongAnimal &operator=(const WrongAnimal &src);
};

class WrongCat : public WrongAnimal{
	public:
		WrongCat( void );
		WrongCat( const WrongCat &src);
		void makeSound( void ) const;
		std::string	getType( void ) const;
		~WrongCat( void );
		WrongCat &operator=( const WrongCat &src );
};

#endif
