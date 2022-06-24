
#ifndef PHONEBOOK_CLASS_H 
#define PHONEBOOK_CLASS_H
#include <iostream>
class	Contact{
	public:
		Contact(void);
		~Contact(void);
		void create_contact(int i);
		std::string getfirst_name();
		std::string getlast_name();
		std::string getnick_name();
		std::string getphone_number();
		std::string getdarkest_secret();
		int index;
	private :	
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
		
};

class	Phonebook{
	public:
		void get_contact_index(std::string index);
		void print_contact_index(int index);
		void print_contact(void);
		std::string print_good_size(std::string test);
		Contact contact[8];
};
#endif
