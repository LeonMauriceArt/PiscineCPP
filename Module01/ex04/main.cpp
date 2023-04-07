#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char *av[])
{
	//check functions args and specify usage
	if (ac != 4)
	{
		std::cout << "Not enough arguments, usage :" << std::endl;
		std::cout << "./my_replace <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	//getting a string copy of file
	std::ifstream file;
	std::string	file_copy = "";
	file.open(av[1], std::ios::in);
	if (!file.is_open())
	{
		std::cout << "File is not accessible or does not exist !" << std::endl;
		return (1);
	}
	while (true)
	{
		std::string buff;
		std::getline(file, buff);
		if (file.fail())
			break;
		buff += "\n";
		file_copy += buff;
	}
	std::string substr = av[2];
	std::string replace_str = av[3];
	size_t pos = file_copy.find(substr);
	while (pos != std::string::npos)
	{
		file_copy = file_copy.substr(0, pos) + replace_str + file_copy.substr(pos + substr.length());
		pos = file_copy.find(substr, pos + replace_str.length());
	}
	std::string filename = av[1];
	filename += ".replace";
	std::ofstream outfile(filename.c_str());
	outfile << file_copy;
	return (0);
}