#include <iostream>
#include <string>

void	display_float_numbers( std::string &sentence )
{
	float entier = std::stof(sentence);
	if (static_cast<char>(entier) > 32 && static_cast<char>(entier) < 127)
		std::cout << "char: " << static_cast<char>(entier) << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(entier) << std::endl;
	if (entier == static_cast<int>(entier))
		std::cout << "float: " << entier << ".0f" << std::endl;
	else
		std::cout << "float: " << entier << "f" << std::endl;
	if (entier == static_cast<int>(entier))
		std::cout << "double: " << static_cast<double>(entier) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(entier) << std::endl;
}

void	display_double_numbers( std::string &sentence )
{
	double entier = std::stod(sentence);
	if (static_cast<char>(entier) > 32 && static_cast<char>(entier) < 127)
		std::cout << "char: " << static_cast<char>(entier) << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(entier) << std::endl;
	if (entier == static_cast<int>(entier))
		std::cout << "float: " << static_cast<float>(entier) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(entier) << "f" << std::endl;
	if (entier == static_cast<int>(entier))
		std::cout << "double: " << entier << ".0" << std::endl;
	else
		std::cout << "double: " << entier << std::endl;
}

void	display_char_numbers( std::string &sentence )
{
	char entier = sentence[0];
	if (static_cast<char>(entier) > 32 && static_cast<char>(entier) < 127)
		std::cout << "char: " << static_cast<char>(entier) << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(entier) << std::endl;
	std::cout << "float: " << static_cast<float>(entier) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(entier) << ".0" << std::endl;
}

void	display_int_numbers( std::string &sentence )
{
	if (sentence.length() < 10)
	{
		int entier = std::stoi(sentence);
		if (static_cast<char>(entier) > 32 && static_cast<char>(entier) < 127)
			std::cout << "char: " << static_cast<char>(entier) << std::endl;
		else
			std::cout << "char: non displayable" << std::endl;
		std::cout << "int: " << entier << std::endl;
		std::cout << "float: " << static_cast<float>(entier) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(entier) << ".0" << std::endl;
	}
}

int		is_number( std::string &sentence )
{
	int i = 0;
	if(sentence[0] == '-' || sentence[0] == '+' || (sentence[0] >= '0' && sentence[0] <= '9'))
		i++;
	while(sentence[i])
	{
		if(sentence[i] < '0' || sentence[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
int		is_flottant( std::string &sentence )
{
	int count_point = 0;
	int i = 0;
	while(sentence[i])
	{
		if (sentence[i] == '.')
			count_point++;
		i++;
	}
	if (count_point == 1)
		return (1);
	return (0);
}

int		check_string_return(std::string &sentence)
{
	if(sentence == "nan" || sentence == "-inf" || sentence == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << sentence << "f" << std::endl;
		std::cout << "double: " << sentence<< std::endl;
		return (1);
	}
	if(sentence == "nanf" || sentence == "-inff" || sentence == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << sentence << std::endl;
		std::cout << "double: " << sentence.substr(0,sentence.length() - 1) << std::endl;
		return (1);
	}
	return (0);

}

int		is_double( std::string &sentence )
{
	int i = 0;

	while(sentence[i] && (sentence[i] >= '0' && sentence[i] <= '9'))
		i++;
	if (sentence[i] == '.')
		i++;
	while(sentence[i] && (sentence[i] >= '0' && sentence[i] <= '9'))
		i++;
	if (sentence[i] == 'f')
		return(0);
	else
		return (1);
}

int is_float(std::string &sentence)
{
{
	int i = 0;

	while(sentence[i] && (sentence[i] >= '0' && sentence[i] <= '9'))
		i++;
	if (sentence[i] == '.')
		i++;
	while(sentence[i] && (sentence[i] >= '0' && sentence[i] <= '9'))
		i++;
	if ((sentence[sentence.length() - 1] == 'f') && i == (int)sentence.length() - 1)
		return(1);
	else
		return (0);
}
}
int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string sentence = av[1];
		if(is_number(sentence) == 1)
			display_int_numbers(sentence);
		else
		{
			if(is_flottant(sentence) == 1)
			{
				if (is_double(sentence) == 1)
					display_double_numbers(sentence);
				else
				{
					if (is_float(sentence) == 1)
						display_float_numbers(sentence);
					else
						std::cout << "Une erreur est survenue" << std::endl;
				}
			}
			else
			{
				if (sentence.length() == 1)
					display_char_numbers(sentence);
				else
				{
					if (check_string_return(sentence) == 1)
					{
					}
					else
						std::cout << "Une erreur est survenue" << std::endl;

				}
			}
		}
	}
	else
		std::cout << "Une erreur est survenue" << std::endl;
}
