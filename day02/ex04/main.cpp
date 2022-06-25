#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		std::ifstream monflux(filename);
		std::ofstream monfluxx(filename + ".replace");
		std::string sentence;
		int count = 0;
		std::ifstream monfluxxx(filename);
		while (getline(monfluxxx, sentence))
			count++;
		monfluxxx.close();
		while (getline(monflux, sentence))
		{
			int i = 0;
			while(sentence[i])
			{
				if (sentence[i] == av[2][0])
				{
					unsigned long y = 0;
					while(av[2][y] && sentence[i + y] == av[2][y])
						y++;
					if(s1.size() == y)
					{	
						monfluxx << s2;
						i += y - 1;
					}
				}
				else
					monfluxx << sentence[i];
				i++;
			}
			if (count > 1)
			{
				count--;
				monfluxx << std::endl;
			}
		}
		monflux.close();
	}
	else
		std::cout << "error" << std::endl;
}