
#include <iostream>
#include <fstream>
#include <sstream>

#define ERR_ARGS "Error : try with ./Sed_is_for_losers <infile> <outfile>\n"

std::string	file_read(char *filename)
{
	std::ifstream		infile(filename);
	std::stringstream	buffer;
	buffer << infile.rdbuf();
	infile.close();
	return (buffer.str());
}

void		file_write(char *filename, std::string to_write)
{
	(void)filename;
	(void)to_write;
}

std::string replace_in_file(std::string s1, std::string s2)
{
	std::string		replaced_content;
	unsigned long	find_start = 0;

	while (find_start < s2.length())
	{
		std::cout << find_start;
		find_start = s2.find(s1, find_start) + 1;
	}
	return (replaced_content);
}

int main(int ac, char **av)
{
	if (ac != 3)
		return (std::cout << ERR_ARGS, 0);

	std::string infile_content		= file_read(av[1]);
	std::string outfile_content		= file_read(av[2]);
	std::string replaced_content	= replace_in_file(infile_content, outfile_content);
//	file_write(av[2], replaced_content);
}
