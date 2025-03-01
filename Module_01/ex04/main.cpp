#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string &filename, const std::string &search, const std::string &replace)
{
    if (search.empty())
    {
        std::cerr << "Error: search string cannot be empty." << std::endl;
        return;
    }

    std::ifstream input(filename.c_str());
    if (!input)
    {
        std::cerr << "Error: cannot open file '" << filename << "'." << std::endl;
        return;
    }

    std::string outFile = filename + ".replace";
    std::ofstream output(outFile.c_str());

    if (!output)
    {
        std::cerr << "Error: cannot create file '" << outFile << "'." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input, line))
    {
        size_t pos = 0;
        while ((pos = line.find(search, pos)) != std::string::npos)
        {
            line.erase(pos, search.length());
            line.insert(pos, replace);
            pos += replace.length();
        }
        output << line << "\n";
    }
}

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Usage: ./replace filename string1 string2" << std::endl;
        return 1;
    }

    std::string search = av[2];
    std::string replace = av[3];

    if (search.empty()) {
        std::cerr << "Error: search string cannot be empty." << std::endl;
        return 1;
    }

    replaceInFile(av[1], search, replace);
    return 0;
}