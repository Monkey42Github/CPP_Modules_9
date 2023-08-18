#include"RPN.hpp"


bool is_symbole(const char c)
{
    if (c == '*' || c == '-' || c == '+' || c == '/')
    {
        return true;

    }
    return false;
}

bool is_caractvalid(std::string test)
{
    for (std::string::size_type i = 0; i < test.length(); ++i)
    {
        if (!isdigit(test[i]) && !is_symbole(test[i]) && test[i] != ' ')
            return false;
    }
    return true;
}

bool operatorvalid(std::string test)
{
    int nbOPE = 0;
    int nbCHI = 0;

    for (std::string::size_type i = 0; i < test.length(); ++i)
    {
        if (isdigit(test[i]))
            nbCHI++;
        if (is_symbole(test[i]))
            nbOPE++;
    }
    if (nbOPE == nbCHI-1)
        return true;

    return false;
}


int calculate(int op1, int op2, char op)
{
    switch (op)
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default: return 0;
    }
}


int ReversePolishNotation(std::string test)
{
    std::istringstream iss(test);
    std::stack<float> stack;
    std::string token;

    if (!is_caractvalid(test))
        return 0;
    if (!operatorvalid(test))
        return 0;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1])))
            stack.push(std::stof(token));
        else if (is_symbole(token[0]))
        {
            if (stack.size() < 2)
                return 0;
            float op2 = stack.top(); stack.pop();
            float op1 = stack.top(); stack.pop();
            float result = calculate(op1, op2, token[0]);
            stack.push(result);
        }
        else
            return 0;
    }
    if (stack.size() != 1)
        return 0;

    float finalResult = stack.top();
    std::cout << finalResult << std::endl;
    return 1;
}
