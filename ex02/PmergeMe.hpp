#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <exception>
#include <climits>
#include <chrono>




void PmergeMe(char **av);

std::vector<int> combine_lists(std::vector<int> l1, std::vector<int> l2);
std::vector<int> init_list(const std::string &str_nbr1, const std::string &str_nbr2);
std::vector<std::vector<int> > init_vector(char **av);
bool IsValideNumber(const std::string &s);
bool IsOnlyValidNumber(char **av);





#endif