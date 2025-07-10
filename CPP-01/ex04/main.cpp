
#include <iostream>
#include <fstream>
#include <sstream>

#define ERR_ARGS "Error: try with ./sed_is_for_losers <infile> <string 1> <string 2>.\n"
#define ERR_FILE "Error: input file don't exist or don't have read permissions.\n"

std::string	read_file(const char *filename)
{
	std::string		temp = "";
	std::string		buffer;
	std::ifstream	infile(filename);

	if (infile.is_open())
		while (std::getline(infile, temp))
		{
			buffer += temp;
			if (infile.peek() != EOF)
				buffer += '\n';
		}
	else
		std::cout << ERR_FILE;
	infile.close();
	return (buffer);
}

void	write_in_file(const char * filename, std::string content)
{
	std::ofstream outfile(filename);
	outfile << content;
	outfile.close();
}

void	replace_content(const char *filename, std::string s1, std::string s2)
{
	std::string outfile = (std::string)filename + (std::string)".replace";

	std::string buffer = read_file(filename);
	int temp = 0;
	while ((temp = buffer.find(s1)) != int(std::string::npos))
	{
		buffer.erase(temp, s1.length());
		buffer.insert(temp, s2);
	}
	write_in_file(outfile.c_str(), buffer);
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << ERR_ARGS, 0);

	replace_content(av[1], std::string(av[2]), std::string(av[3]));
	return 0;
}
