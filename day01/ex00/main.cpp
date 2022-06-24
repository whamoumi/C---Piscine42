#include <iostream>
#include <string>

void	megaphone(int argc, char **argv)
{
	int i = 0;
	char caractere;
	int j;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
			{	
				caractere =  (argv[i][j] - 32);
				std::cout << caractere;
			}
			else
				std::cout << argv[i][j];
		}
	}
}

int	main(int argc, char **argv)
{
	megaphone(argc, argv);
	return (0);
}
