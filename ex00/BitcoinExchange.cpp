#include"BitcoinExchange.hpp"
#include <climits>
#include <sstream>

bool IsNumber(std::string &value)
{
    int i = 0;
    while (value[i])
    {
        if (!std::isdigit(value[i]) && value[i] != '.')
            return false;
        i++;
    }
    return !value.empty();
}


bool istoomany(const std::string& value)
{
    return std::atof(value.c_str()) >= (float)INT_MAX ? 1 : 0 ;
}

bool IsValidDate(const std::string date)
{
    struct tm test;
    if (strptime(date.c_str(), "%Y-%m-%d", &test))
        return 1;
    else
        return 0;
}


// std::string CloseDate(std::string date, std::map<std::string, std::string> data)
// {
//     time_t givenTime = std::stoi(date.substr(0, 4)) * 365 + std::stoi(date.substr(5, 2)) * 30 + std::stoi(date.substr(8, 2));
    
//     int minDifference = 10000000;
//     std::string closestDate;

//     for (std::map<std::string, std::string>::const_iterator it = data.begin(); it != data.end(); ++it)
//     {
//         const std::string& strDate = it->first;
//         time_t entryTime = std::stoi(strDate.substr(0, 4)) * 365 + std::stoi(strDate.substr(5, 2)) * 30 + std::stoi(strDate.substr(8, 2));
        
//         int difference = std::abs(givenTime - entryTime);
//         if (difference < minDifference)
//         {
//             minDifference = difference;
//             closestDate = strDate;
//         }
//     }
//     return (closestDate);
// }

std::string CloseDate(std::string date, std::map<std::string, std::string> data)
{
    std::string StrDate;
    std::string ClosestDate;
    struct tm timeInfo1 = {};
    struct tm timeInfo2 = {};
    strptime(date.c_str(), "%Y-%m-%d", &timeInfo1);
    time_t time1 = mktime(&timeInfo1);
    time_t time2;
    double differenceDays;
    double minDiff;

    strptime(data.begin()->first.c_str(), "%Y-%m-%d", &timeInfo2);
    time2 = mktime(&timeInfo2);
    minDiff = difftime(time1, time2) / (24 * 60 * 60); 

    for (std::map<std::string, std::string>::iterator it = data.begin(); it != data.end(); ++it)
    {
        StrDate = it->first;
        strptime(StrDate.c_str(), "%Y-%m-%d", &timeInfo2);
        time2 = mktime(&timeInfo2);

        differenceDays = difftime(time1, time2) / (24 * 60 * 60);
        if(differenceDays <= minDiff &&  differenceDays >= 0)
        {
            minDiff = differenceDays;
            ClosestDate = StrDate;
        }
    }
    return(ClosestDate);
}

void BitcoinExchange(std::string line, std::map<std::string, std::string> data)
{
    
    size_t pipePos = line.find(" | ");

    try {
        std::string date = line.substr(0, pipePos);
        std::string value = line.substr(pipePos + 3);


        if (!IsValidDate(date) || date.length() != 10 || (date[8] == '0' && date[9] == '0')) 
            throw std::runtime_error("bad input => "+ date);
        else if (!IsNumber(value))
            throw std::runtime_error("not a positive number.");
        else if (istoomany(value))
            throw std::runtime_error("too large a number.");
        

        std::string dataclose = CloseDate(date, data);
        std::cout << date << " => " << value << " = " << std::atof(value.c_str()) * std::atof(data[dataclose].c_str()) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

}


