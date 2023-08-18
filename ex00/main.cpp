#include"BitcoinExchange.hpp"






int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: wrong argument number" << std::endl;
        return(0);
    }

    std::ifstream dataCSV("data.csv");
    std::ifstream dataTAUX(av[1]);
    
    if (!dataCSV || !dataTAUX)
    {
        std::cout << "Error: could not open file." << std::endl;
        return(0);
    }

    std::map<std::string, std::string> data;
    std::string str;

    std::getline(dataCSV, str);
    while (std::getline(dataCSV, str))
    {
        size_t PosVirgule = str.find(',');
        if (PosVirgule != std::string::npos)
        {
            std::string key = str.substr(0, PosVirgule);
            std::string value = str.substr(PosVirgule + 1);
            data[key] = value;
        }
    }

    std::getline(dataTAUX, str);
    while (std::getline(dataTAUX, str))
    {
        BitcoinExchange(str, data);
    }
    
}


