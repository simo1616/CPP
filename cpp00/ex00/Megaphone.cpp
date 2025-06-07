#include <iostream>
#include <cstring>

int main (int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for(int i = 1; i < ac; ++i)
    {
        int len = strlen(av[i]);
        for(int j = 0; j < len; ++j)
        {
            if(av[i][j] >= 'a' && av[i][j] <= 'z' )
            {
                av[i][j] -= 32;
            }
            std::cout << av[i][j];
        }
        if(i != ac - 1)
            std::cout << " ";
    }
    std::cout << '\n';
    return(0);
}