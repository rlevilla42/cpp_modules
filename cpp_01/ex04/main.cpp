#include <fstream>
#include <iostream>
#include <string>

std::string my_str_replace(std::string src, std::string s1, std::string s2)
{
    std::string buffer;
    int i = 0;
    int loop = 0;
    int found = src.find(s1, i);
    while (found != std::string::npos)
    {
        found = src.find(s1, i);
        if (found != std::string::npos)
        {
            if (loop == 0)
                buffer = buffer + src.substr(i, found) + s2;
            else
                buffer = buffer + src.substr(i, found - i) + s2;
        }
        else
        {
            buffer = buffer + src.substr(i, src.length());
        }
        i = found + s1.length();
        loop++;
    }
    return (buffer);
}

int    main(int argc, char **argv)
{
    std::ifstream read_file;
    std::ofstream write_file;
    std::string   buffer;

    if (argc != 4)
    {
        std::cerr << "Not good format bro." << std::endl << "Instead do this: <filename> <string 1> < string 2>" << std::endl;
        return (1);
    }
    read_file.open(argv[1]);
    write_file.open("test.replace");
    if (!read_file.is_open() || !write_file.is_open())
    {
        std::cerr << "Error open file" << std::endl;
        return (1);
    }
    while(std::getline(read_file, buffer))
    {
        write_file << my_str_replace(buffer, argv[2], argv[3]) << std::endl;
        buffer.erase(0, buffer.length());
    }
    read_file.close();
    write_file.close();
    return (0);
};

/*int main(void)
{
    // MAIN TO TEST MY REPLACE FUNCTION


    //std::string src = "Love Macron";
    //std::string src = "Why do think Macron is the best ? *_*";
    //std::string src = "Macron is so fast brr brr";
    //std::string src = "Macron et Macron quoi";
    //std::string src = "Macron Macron Macron Macron Macron Macron Macron Macron Macron Macron Macron Macron";
    //std::string src = "Macron is so strong *__* Macron Mac manu macs Macron";
    std::string s1 = "Macron";
    std::string s2 = "Muhammad Ali";
    std::cout << my_str_replace(src, s1, s2) << std::endl;
    return(0);
}*/