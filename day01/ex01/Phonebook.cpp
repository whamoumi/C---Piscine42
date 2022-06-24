#include <iostream>
#include <string>
#include "Phonebook.class.hpp"

Contact::Contact(void)
{
	this->index = 0;
}

Contact::~Contact(void)
{
}

void Contact::create_contact(int i)
{ 
	this->index = i + 1;
	std::cout << "your first name : ";
	getline(std::cin, this->first_name);
	std::cout << "your last name : ";
	getline(std::cin, this->last_name);
	std::cout << "your nick name : ";
	getline(std::cin, this->nick_name);
	std::cout << "your phone number : ";
	getline(std::cin, this->phone_number);
	std::cout << "your darkest_secret : ";
	getline(std::cin, this->darkest_secret);

}

std::string Contact::getfirst_name()
{
	return (this->first_name);
}

std::string Contact::getlast_name()
{
	return (this->last_name);
}

std::string Contact::getnick_name()
{
	return (this->nick_name);
}

std::string Contact::getphone_number()
{
	return (this->phone_number);
}

std::string Contact::getdarkest_secret()
{
	return (this->darkest_secret);
}


std::string Phonebook::print_good_size(std::string test)
{
	std::string new_chaine;
	int number_space = 0;
	int i = 0;

	if(test.size() < 10)
	{
		number_space = 10 - test.size();
		while(i < number_space)
		{	
			new_chaine.append(" ");
			i++;
		}
		new_chaine.append(test);
	}
	else
	{
		new_chaine = test.substr(0, 9);
		new_chaine.append(".");
	}
	return(new_chaine);
}
void Phonebook::print_contact(void)
{
	int i = 0;

	while(i < 8)
	{
		if (this->contact[i].index > 0)
		{
			std::cout << "         " << this->contact[i].index;
			std::cout << "|" << print_good_size(this->contact[i].getfirst_name()) << "|" << print_good_size(this->contact[i].getlast_name()) << "|" << print_good_size(this->contact[i].getnick_name()) << std::endl;
			i++;
		}
		if (this->contact[i].index == 0)
			break ;
		
	}
}

void Phonebook::print_contact_index(int index)
{
	if (this->contact[index -1].index > 0)
	{
		std::cout << "your first name : " << this->contact[index -1].getfirst_name() << std::endl;	
		std::cout << "your last name : " << this->contact[index -1].getlast_name() << std::endl;
		std::cout << "your nick name : " << this->contact[index -1].getnick_name() << std::endl;	
		std::cout << "your phone number : " << this->contact[index -1].getphone_number() << std::endl;	
		std::cout << "your darkest_secret : " << this->contact[index -1].getdarkest_secret()<< std::endl;
	}
	else
		std::cout << "this contact is empty" << std::endl;
}
void Phonebook::get_contact_index(std::string index)
{
	if(index == "1")
		print_contact_index(1);
	else if(index == "2")
		print_contact_index(2);
	else if(index == "3")
		print_contact_index(3);
	else if(index == "4")
		print_contact_index(4);
	else if(index == "5")
		print_contact_index(5);
	else if(index == "6")
		print_contact_index(6);
	else if(index == "7")
		print_contact_index(7);
	else if(index == "8")
		print_contact_index(8);
	else 
		std::cout << "Wrong index" << std::endl;
}
int main()
{
	Phonebook Carnet;
	std::string enter;
	std::string index;
	int i = 0;
	
	while(1)
	{
		std::cout << "your command : ";
		std::getline (std::cin,enter);
		if(std::cin.eof())
			exit (0);
		if (i == 9)
		{
			std::cout << "the Phonebook is full" << std::endl;
			exit(0);
		}
		if (enter == "ADD")
		{	
			Carnet.contact[i].create_contact(i);
			i++;
		}
		if (enter == "SEARCH")
		{
			Carnet.print_contact();
			std::cout << "search a specific contact : ";
			std::getline (std::cin, index);
			Carnet.get_contact_index(index);
		}
		if (enter == "EXIT")
			exit(0);
	}
	return 0;
}