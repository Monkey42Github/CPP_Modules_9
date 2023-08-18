#include"PmergeMe.hpp"


bool IsValideNumber(const std::string &s)
{
    for (std::string::const_iterator i = s.begin(); i != s.end(); ++i)
    {
        if (!std::isdigit(*i))
            return false;
    }
    return !s.empty() && std::stoi(s) <= INT_MAX;
}

std::vector<int> init_list(const std::string &str_nbr1, const std::string &str_nbr2)
{
    std::vector<int> l;

    if(str_nbr2.length() == 0)
        l.push_back(atoi(str_nbr1.c_str()));
    else if(atoi(str_nbr1.c_str()) <= atoi(str_nbr2.c_str()))
    {
        l.push_back(atoi(str_nbr1.c_str()));
        l.push_back(atoi(str_nbr2.c_str()));
    }
    else
    {
        l.push_back(atoi(str_nbr2.c_str()));
        l.push_back(atoi(str_nbr1.c_str()));
    }
    return l;
}

bool IsOnlyValidNumber(char **av)
{
    for (int i = 1; av[i]; ++i)
    {
        if (!IsValideNumber(av[i]))
            return false;
    }
    return true;
}

std::vector<std::vector<int> > init_vector(char **av)
{
    std::vector<std::vector<int> > v;
    int i = 1;

    if (!IsOnlyValidNumber(av))
        throw std::runtime_error("Only positifs number are avalable.");

    std::cout << "Before: ";
    while (av[i])
    {
        if (av[i+1])
        {
            std::cout << av[i] << " " << av[i+1] << " ";
            v.push_back(init_list(av[i], av[i+1]));
            i = i + 2;
        }
        else
        {
            std::cout << av[i] << " ";
            v.push_back(init_list(av[i], ""));
            i = i + 1;
        }
    }
    std::cout << std::endl;
    return v;
}

std::vector<int> combine_lists(std::vector<int> l1, std::vector<int> l2)
{
    std::vector<int> l;
    size_t index1 = 0, index2 = 0;
    while (index1 < l1.size() && index2 < l2.size())
    {
        if (l1[index1] < l2[index2])
        {
            l.push_back(l1[index1]);
            ++index1;
        }
        else
        {
            l.push_back(l2[index2]);
            ++index2;
        }
    }
    while (index1 < l1.size())
    {
        l.push_back(l1[index1]);
        ++index1;
    }
    while (index2 < l2.size())
    {
        l.push_back(l2[index2]);
        ++index2;
    }
    return l;
}

void PmergeMe(char **av)
{
    try
    {
        std::vector<std::vector<int> > v = init_vector(av);

        while (v.size() != 1)
        {
            std::vector<int> l1 = v[0];
            v.erase(v.begin());
            std::vector<int> l2 = v[0];
            v.erase(v.begin());

            v.push_back(combine_lists(l1, l2));
        }
        std::vector<int> lFinal = v[0];

        std::clock_t startClock = std::clock();
        std::cout << "After:  ";
        for (std::vector<int>::iterator i = lFinal.begin(); i != lFinal.end(); ++i)
            std::cout << *i << " ";
        std::cout << std::endl;

        std::clock_t endClock = std::clock();
        double microseconds = (endClock - startClock) / (double)CLOCKS_PER_SEC * 1000000;

        std::cout << "Time to process a range of " << v[0].size() << " elements: " <<  microseconds << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
