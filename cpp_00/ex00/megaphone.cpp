#include <iostream>

int    main(int argc, char **argv)
{
    int i = 0;
    int j = 1;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        while (j < argc)
        {
            while (argv[j][i] != '\0')
            {
                std::cout << (char)std::toupper((unsigned char)argv[j][i]) << std::flush;
                i++;
            }
            if (j != argc - 1)
            {
                std::cout << ' ' << std::flush;
            }
            i = 0;
            j++;
        }
    }
    return (0);
}