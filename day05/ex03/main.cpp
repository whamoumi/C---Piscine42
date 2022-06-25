#include "material.hpp"

int Character::i = 0;
int MateriaSource::i = 0;
AMateria::AMateria(std::string const &type)
{
	_type=type;
}

std::string const& AMateria::getType() const
{
	return _type;
}
AMateria* Ice::clone( void ) const
{
	AMateria *element = new Ice();
	return element;
}

Ice::Ice( void ): AMateria("ice")
{
}
void	AMateria::SetType(std::string type)
{
	this->_type = type;
}

AMateria* Cure::clone( void ) const
{
	AMateria *element = new Cure();
	return element;
}

Cure::Cure( void ): AMateria("cure")
{
}


//------------------------------------------------------------------------------------------------

Character::Character(std::string name): ICharacter(){
	this->_name = name;
	
	int i = 0; 
	while( i < 4 )
		this->index[i++] = true;
}

Character::Character(Character const & copy) : ICharacter(){
	*this = copy;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria * m)
{
	if (this->i < 4)
	{
		this->inventory[i] = m;
		this->index[i] = false;
	}
	this->i++;	
	int u = 0;
	while(u < i)
	{
		std::cout << "element du sac --> "<< u << " --> "<<this->inventory[u]->getType() << std::endl;
		u++;
	}
}

void Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4  && this->index[idx] == false)
	{	
		this->inventory[idx]->SetType("");
		this->index[idx] = true;
	}
	else
		std::cout << "Wrong index" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx]->getType() == "ice")
		std::cout << "* shoots an ice bolt at "<< target.getName() << "*"<< std::endl;
	else if(this->inventory[idx]->getType() == "cure")
		std::cout << "* heals "<< target.getName() <<"'s wounds *"<< std::endl;
	else
		std::cout << "";
}
//------------------------------------------------------------------------------------------------

void MateriaSource::learnMateria(AMateria* copy)
{
	if (this->i < 4 && this->i >= 0)
	{
		this->inventory_learn[i] = copy;
		this->index[i] = false;
		this->i++;
	}
}


void AMateria::use(ICharacter& target){
		std::cout <<"Amateria use "<< target.getName() << std::endl;
}

void Cure::use(ICharacter& target){
		std::cout <<"Cure use "<< target.getName() << std::endl;
}

void Ice::use(ICharacter& target){
		std::cout <<"Ice use "<< target.getName() << std::endl;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	int w = 0;
	while (w < 3)
	{
		if (type == this->inventory_learn[w]->getType())
		{
			if (type == "ice")
			{
				AMateria *nouveau = new Ice();
				return nouveau;
			}
			if (type == "cure")
			{
				AMateria *nouveau = new Cure();
				return nouveau;
			}
		}
		w++;
	}
	return 0;
}

MateriaSource::MateriaSource( void ) : IMateriaSource()
{
	int i = 0;
	while (i < 4)
		this->index[i++] = true;
}

MateriaSource::MateriaSource( MateriaSource const & copy ) : IMateriaSource()
{
	*this = copy;
	return ;
}

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}