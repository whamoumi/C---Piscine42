#ifndef  _ICHARACTERE_HPP_
#define _ICHARACTERE_HPP_

#include "material.hpp"

class ICharacter
{
	//class AMateria;
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif