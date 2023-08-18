
#include"PmergeMe.hpp"


int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error: Number of arguments must be more than 1." << std::endl;
        return -1;
    }
    
    PmergeMe(av);

    return 0;
}
