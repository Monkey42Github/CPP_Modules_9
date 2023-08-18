#include"RPN.hpp"


int main(int ac, char **av)
{
    
    if (ac == 2)
    {
        std::string line = av[1];
        if (ReversePolishNotation(line))
            return 1;
    }
    std::cout << "Error" << std::endl;
    return 0;
}
