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
	std::string str_to_replace = av[2];
	std::string replace_str = av[3];
	//check if str to replace is empty
	if (str_to_replace == "")
	{
		std::cout << "Error : string to replace cannot be empty." << std::endl;
		return (1);
	}
	//opening file
	std::ifstream file;
	std::string	file_copy = "";
	file.open(av[1], std::ios::in);
	//check for file existing
	if (!file.is_open())
	{
		std::cout << "File is not accessible or does not exist !" << std::endl;
		return (1);
	}
	//copy the file
	while (true)
	{
		std::string buff;
		std::getline(file, buff);
		buff += "\n";
		if (file.fail())
			break;
		file_copy += buff;
	}
	//replace words in the copy
	size_t pos = file_copy.find(str_to_replace);
	while (pos != std::string::npos)
	{
		file_copy = file_copy.substr(0, pos) + replace_str + file_copy.substr(pos + str_to_replace.length());
		pos = file_copy.find(str_to_replace, pos + replace_str.length());
	}
	//create the new file and copy the new text inside
	std::string filename = av[1];
	filename += ".replace";
	std::ofstream outfile(filename.c_str());
	outfile << file_copy;
	return (0);
}