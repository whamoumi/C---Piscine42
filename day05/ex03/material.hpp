#ifndef _MATERIAL_HPP
#define _MATERIAL_HPP
#include <string>
#include <iostream>

//#include "AMateria.hpp"
//#include "icharactere.hpp"

//-----------------------------------------------------------------------------------------------------------------------
class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

//-----------------------------------------------------------------------------------------------------------------------

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(void){};
		AMateria(std::string const & type);
		AMateria( const AMateria &src){
			*this = src;
		}
		std::string const & getType() const;
		void SetType(std::string type);
		virtual AMateria* clone( void ) const = 0;
		virtual void use(ICharacter& target);
		AMateria &operator=(const AMateria &src){
			this->_type = src.getType();
			return *this;
		};
};

//-----------------------------------------------------------------------------------------------------------------------

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource {
	private :
		AMateria *inventory_learn[4];
		bool index[4];
	public :
		MateriaSource( void );
		MateriaSource( MateriaSource const & copy  );
		void learnMateria(AMateria* copy);
		AMateria* createMateria(std::string const & type);
		static int i;
};

//-----------------------------------------------------------------------------------------------------------------------

class Character : public ICharacter {
	private :
		AMateria *inventory[4];
		bool index[4];
		std::string _name;
	public :
		Character( std::string name );
		Character( Character const & copy );
		~Character( void ) {};
		std::string const &getName() const;
		void use(int idx, ICharacter& target);
		void equip(AMateria* m);
		void unequip(int idx);
		static int i;
};

//-----------------------------------------------------------------------------------------------------------------------

class Ice : public AMateria
{
	private :
		std::string type;
	public :
		Ice( void );
		Ice( const Ice &src): AMateria(){
			*this = src;
		}
		~Ice( void );
		virtual AMateria* clone( void ) const;
		void use(ICharacter& target);
		Ice &operator=(const Ice &src){
			this->type = src.getType();
			return *this;
		};
	
};

class Cure : public AMateria
{
	private :
		std::string type;
	public :
		Cure( void );
		Cure( const Cure &src): AMateria(){
			*this = src;
		}
		~Cure( void );
		virtual AMateria* clone( void ) const;
		void use(ICharacter& target);
		Cure &operator=(const Cure &src){
			this->type = src.getType();
			return *this;
		};
};

#endif